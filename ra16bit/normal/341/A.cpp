#include <cstdio>
#include <algorithm>
using namespace std;
int n,i,a[100100];
long long cl,cr,sl,sr,x,d;
long long gcd(long long a, long long b) { return b==0?a:gcd(b,a%b); }
int main() {
  scanf("%d",&n); cr=n;
  for (i=0; i<n; i++) { scanf("%d",&a[i]); sr+=a[i]; }
  sort(a,a+n);
  for (x=sr, i=0; i<n; i++) {
    cr--; sr-=a[i];
	x+=sr-cr*a[i];
	x+=cl*a[i]-sl;
    cl++; sl+=a[i];
  }
  d=gcd(x,n);
  printf("%I64d %I64d\n",x/d,n/d);
  return 0;
}