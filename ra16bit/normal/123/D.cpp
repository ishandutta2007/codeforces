#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const long long MX=100100;
const int L=18;
const int MASK=(1<<L)-1;
int i,j,k,n,m,a[MX],b[MX],f[L][MX],st[MX],sp[MX];
long long ps[MX],ans[MX],res;
char s[MX];
void refresh(int bi) {
  for (; st[m-1]>bi; m--) ans[i-sp[m]]+=st[m]-st[m-1];
  if (st[m]>bi) {
    ans[i-sp[m]]+=st[m]-bi;
    st[m]=bi;
  }
}
int main() {
  scanf("%s",s);
  n=strlen(s);
  for (i=0; i<n; i++) f[0][i]=s[i]-'a'+1;
  for (k=1; k<L; k++) {
    for (i=0; i<n; i++) {
      j=i+(1<<(k-1));
      ps[i]=(((f[k-1][i]*MX)+(j<n?f[k-1][j]:0LL))<<L)+i;
    }
    sort(ps,ps+n);
    for (f[k][ps[0]&MASK]=m=i=1; i<n; i++) {
      if ((ps[i]&(~MASK))!=(ps[i-1]&(~MASK))) m++;
      f[k][ps[i]&MASK]=m;
    }
  }
  for (i=0; i<n; i++) a[i]=ps[i]&MASK;
  for (i=1; i<n; i++) {
    m=max(n-a[i],n-a[i-1]);
    for (j=L-1; j>=0; j--) {
      if (f[j][a[i-1]+b[i]]==f[j][a[i]+b[i]]) b[i]+=1<<j;
      if (b[i]>=m) { b[i]=m; break; }
    }
  }
  st[1]=n-a[0];
  for (m=i=1; i<n; i++) {
    refresh(b[i]);
    if (m==0 || st[m]<n-a[i]) {
      st[++m]=n-a[i];
      sp[m]=i;
    }
  }
  refresh(0);
  for (i=1; i<=n; i++) res+=(((i+1LL)*i)/2LL)*ans[i];
  printf("%I64d\n",res);
  return 0;
}