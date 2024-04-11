#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int md=1000000007;
int rn,n1,n2,n,m,ii,i,j,k,cur,zcur,last,t,e[300300],f[20][600600],a[300300][3];
pair<int,int> st[300300];
long long cnt,r[300300];
char s[300300];
bool cmp(int i, int j) {
  if (f[k][i]!=f[k][j]) return f[k][i]<f[k][j];
  return f[k][i+(1<<k)]<f[k][j+(1<<k)];
}
int main() {
  scanf("%s",s);
  n1=strlen(s)+1;
  rn=n1-1;
  s[n1-1]='z'+1;
  scanf("%s",s+n1);
  n2=n1+strlen(s+n1)+1;
  rn=min(rn,int(strlen(s+n1)));
  s[n2-1]='z'+2;
  scanf("%s",s+n2);
  rn=min(rn,int(strlen(s+n2)));
  n=strlen(s);
  for (i=0; i<n; i++) {
    f[0][i]=s[i]-'a'+1;
    e[i]=i;
  }
  for (k=0; k<19; k++) {
    sort(e,e+n,cmp);
    for (m=ii=0; ii<n; ii++) {
      i=e[ii];
      if (ii==0 || f[k][i]!=f[k][j] || f[k][i+(1<<k)]!=f[k][j+(1<<k)]) m++;
      f[k+1][i]=m;
      //if (k<2) printf("%d %d = %d\n",k+1,i,m);
      j=i;
    }
  }
  for (ii=0; ii<n; ii++) {
    i=e[ii];
    for (int j=0; j<3; j++) a[ii+1][j]=a[ii][j];
    if (i<n1-1) a[ii+1][0]++;
    if (i>=n1 && i<n2-1) a[ii+1][1]++;
    if (i>=n2) a[ii+1][2]++;
    if (ii) {
      cur=0;
      for (k=18; k>=0; k--) if (f[k][i+cur]==f[k][j+cur]) cur+=(1<<k);
      for (last=ii-1; t>0 && cur<=st[t].second; t--) {
        last=st[t].first;
        cnt=a[ii][0]-a[last][0];
        cnt*=a[ii][1]-a[last][1];
        cnt%=md;
        cnt*=a[ii][2]-a[last][2];
        cnt%=md;
        zcur=cur;
        if (t>1 && st[t-1].second>cur) zcur=st[t-1].second;
        r[zcur+1]+=cnt;
        if (r[zcur+1]>=md) r[zcur+1]-=md;
        r[st[t].second+1]-=cnt;
        if (r[st[t].second+1]<0) r[st[t].second+1]+=md;
      }
      st[++t]=make_pair(last,cur);
    }
    j=i;
  }
  cnt=0;
  for (i=1; i<=rn; i++) {
    cnt+=r[i];
    if (cnt>=md) cnt-=md;
    printf("%I64d%c",cnt,i==rn?'\n':' ');
  }
  return 0;
}