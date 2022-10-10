#include <cstdio>
#include <vector>
#include <string>
using namespace std;
int n,t,m,x,i,j,jj,ct,dt,a[111][2],b[111][2],c[111],d[111][111],q[1010101],fi,fr;
vector <int> r[111];
string s[111];
char st[22];
int main() {
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  scanf("%d%d",&n,&t);
  for (i=0; i<n; i++) for (j=0; j<2; j++) scanf("%d%d",&a[i][j],&b[i][j]);
  scanf("%d",&m); fr=m;
  for (i=0; i<m; i++) {
    scanf("%s",st);
    scanf("%d",&c[i]);
    s[i]=st; q[i]=i;
  }
  for (jj=0; fi<fr; jj++) {
    j=jj&1;
    for (i=0; i<n; i++) {
      ct=t;
      while (fi<fr && ct>0) {
        x=q[fi++];
        dt=c[x]-a[i][j]-b[i][1-j]-d[i][x];
        if (dt<1) dt=1;
        if (ct<dt) {
          d[i][x]+=ct;
          q[fr++]=x;
        } else r[i].push_back(x);
        ct-=dt;
      }
    }
  }
  for (i=0; i<n; i++, puts("")) {
    printf("%d",int(r[i].size()));
    for (j=0; j<r[i].size(); j++) printf(" %s",s[r[i][j]].c_str());
  }
  return 0;
}