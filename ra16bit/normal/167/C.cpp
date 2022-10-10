#include <cstdio>
#include <algorithm>
using namespace std;
int t;
long long a,b;
bool solve(long long a, long long b) {
  if (b==0) return false;
  long long x=a%b;
  if (!solve(b,x)) return true;
  x=a-x;
  if (b%2) {
    return (x%2==0);
  } else if (b>=2000000000 || x<=b*b) {
    return (((x-1)/b)%2==1);
  }
  x=(x-b*b-1)%(b*b+b);
  return ((x/b)%2==0);
}
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%I64d%I64d",&a,&b);
    if (a<b) swap(a,b);
    puts(solve(a,b)?"First":"Second");
  }
  return 0;
}