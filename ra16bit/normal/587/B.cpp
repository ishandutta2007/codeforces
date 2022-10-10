#include <cstdio>
#include <algorithm>
using namespace std;
const int MX=4200200,md=1000000007;
int n,k,i,j,idx,nxti,prev,cnt,r,b[MX],c[MX],nxt[MX];
long long l,fin,full,fullmd,f[MX];
pair<int,int> a[MX];
int main() {
  scanf("%d%I64d%d",&n,&l,&k);
  for (i=0; i<n; i++) { scanf("%d",&a[i].first); a[i].second=i; }
  sort(a,a+n);
  fin=l%n;
  full=l/n;
  fullmd=full%md;
  for (i=0; i<n; i=j) {
    cnt=0;
    for (j=i; a[i].first==a[j].first; j++) if (a[j].second<fin) cnt++;
    if (i==0) f[(j-1)*(k+1)]=1; else nxt[prev]=j-1;
    prev=j-1;
    b[prev]=j-i;
    c[prev]=cnt;
  }
  nxt[prev]=n;
  for (i=0; i<n; i++) {
    nxti=nxt[i]*(k+1);
    for (j=0; j<=k; j++) {
    idx=i*(k+1)+j;
    if (f[idx]) {
      f[nxti+j]=(f[nxti+j]+f[idx])%md;
      if (j<k) {
        //printf("%d %d = %I64d\n",i,j,f[idx]);
        if (full>j) {
        r=(r+f[idx]*((b[i]*(fullmd+md-j))%md))%md;
        //printf("ar+= %d (%d)\n",int(f[idx]*((b[i]*(fullmd+md-j))%md)),i);
        }
        if (full+1>j) {
        r=(r+f[idx]*c[i])%md;
        //printf("br+= %d (%d)\n",int(f[idx]*c[i]),i);
        }
        f[idx+1]=(f[idx+1]+b[i]*f[idx])%md;
      }
    }
    }
  }
  printf("%d\n",r);
  return 0;
}