#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int md=1000000007;
int N,n,m,i,l,r,x,z[1000100];
char s[1000100];
long long pw(int a, int b) {
  if (b==0) return 1LL;
  if (b&1) return (pw(a,b-1)*a)%md;
  long long x=pw(a,b/2);
  return (x*x)%md;
}
int main() {
  scanf("%d%d",&N,&m);
  scanf("%s",s);
  n=strlen(s);
  for (i=1; i<n; i++) {
    if (r>i) z[i]=min(z[i-l],r-i);
    for (; i+z[i]<n && s[i+z[i]]==s[z[i]]; z[i]++);
    if (i+z[i]>r) { l=i; r=i+z[i]; }
  }
  for (r=i=0; i<m; i++) {
    scanf("%d",&x);
    if (r>x && x+z[x+n-r]<r) {
      puts("0");
      return 0;
    }
    N-=x+n-max(r,x);
    r=x+n;
  }
  printf("%d\n",int(pw(26,N)));
  return 0;
}