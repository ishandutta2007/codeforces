#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
const int inf=1000000000;
int n,m,qm,i,j,k,p,cur,cc,pos,was,last,wlast,a[100100],b[3535],st[3535][35],where[3535][35],e[100100],q[300300];
bool u[100100];
pair<int,int> z[44];
map<int, long long> w;
int main() {
  for (i=2; i<32000; i++) if (!u[i]) {
    e[i]=m; b[m++]=i;
    for (j=i+i; j<32000; j+=i) u[j]=true;
  }
  scanf("%d",&n);
  for (i=1; i<=n; i++) scanf("%d",&a[i]);
  scanf("%d",&qm);
  for (i=0; i<qm; i++) {
    scanf("%d",&q[i]);
    w[q[i]]=0;
  }
  for (i=1; i<=n; i++) {
    cur=a[i];
    for (j=k=0; j<m; j++) {
      if (b[j]*b[j]>cur) break;
      if (cur%b[j]==0) {
        for (p=0; cur%b[j]==0; p++) {
          cur/=b[j];
          if (st[j][p]<i-1) where[j][p]=i-1;
          st[j][p]=i;
          z[k++]=make_pair(where[j][p],b[j]);
        }
      }
    }
    if (cur>1) {
      if (cur<32000) {
        j=e[cur]; last=p=0;
        if (st[j][p]<i-1) where[j][p]=i-1;
        st[j][p]=i;
        z[k++]=make_pair(where[j][p],b[j]);
      } else {
        if (last!=cur) {
          wlast=i-1;
          last=cur;
        }
        z[k++]=make_pair(wlast,last);
      }
    } else last=0;
    sort(z,z+k);
    cur=a[i]; pos=i;
    for (j=k-1; j>=0; ) {
      for (cc=cur, was=j; j>=0 && z[j].first==z[was].first; j--) cc/=z[j].second;
      if (w.count(cur)) w[cur]+=pos-z[was].first;
      pos=z[was].first;
      cur=cc;
    }
    if (pos>0 && w.count(cur)) w[cur]+=pos;
  }
  for (i=0; i<qm; i++) printf("%I64d\n",w[q[i]]);
  return 0;
}