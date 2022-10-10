#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int L=18,MX=100100,MASK=(1<<L)-1;
int n,m,i,j,k,p,f[L][MX],a[MX];
long long b[MX],c[MX],ll;
char s[MX],cur;
void go(int L, int R, int d) {
  while (L<=R) {
    int l=L,r=R,h;
    cur=s[a[L]+d];
    while (l<r) {
      h=(l+r)/2+1;
      if (cur==s[a[h]+d]) l=h; else r=h-1;
    }
    ll=r-L+1;
    if (ll>=m) {
      for (h=0; h<=d; h++) putchar(s[a[L]+h]);
      puts("");
      return;
    }
    m-=ll;
    if (c[r+1]-c[L]-(d+1LL)*ll>=m) {
      if (n-a[L]==d+1) L++;
      go(L,r,d+1);
      return;
    }
    m-=c[r+1]-c[L]-(d+1LL)*ll;
    L=r+1;
  }
}
int main() {
  scanf("%s",s);
  n=strlen(s);
  scanf("%d",&m);
  for (i=0; i<n; i++) f[0][i]=s[i]-'a'+1;
  for (k=1; k<L; k++) {
    for (i=0; i<n; i++) {
      j=i+(1<<(k-1));
      b[i]=(((((long long)f[k-1][i])<<L)+(j<n?f[k-1][j]:0))<<L)+i;
    }
    sort(b,b+n);
    for (f[k][b[0]&MASK]=p=i=1; i<n; i++) {
      if ((b[i]&(~MASK))!=(b[i-1]&(~MASK))) p++;
      f[k][b[i]&MASK]=p;
    }
  }
  for (i=0; i<n; i++) a[i]=b[i]&MASK;
  for (i=0; i<n; i++) c[i+1]=c[i]+n-a[i];
  if (m>c[n]) puts("No such line."); else go(0,n-1,0);
  return 0;
}