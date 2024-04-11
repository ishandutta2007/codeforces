#include <cstdio>
#include <algorithm>
using namespace std;
int n,a,x,y,i;
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%d",&a);
	x=max(a,x);
	y=__gcd(a,y);
  }
  puts(((x/y-n)%2)?"Alice":"Bob");
  return 0;
}