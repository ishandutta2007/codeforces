#include <cstdio>
using namespace std;
long long x,y;
long long gcd(long long a, long long b) { return b?gcd(b,a%b):a; }
int main() {
  scanf("%I64d%I64d",&x,&y);
  if (gcd(x,y)==1) {
    while (x!=1 && y!=1) if (x<y) {
      printf("%I64dB",y/x);
      y%=x;
    } else {
      printf("%I64dA",x/y);
      x%=y;
    }
    if (x>1) printf("%I64dA",x/y-1); else if (y>1) printf("%I64dB",y/x-1);
  } else puts("Impossible");
  return 0;
}