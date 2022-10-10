#include <cstdio>
#include <algorithm>
using namespace std;
long long a,b;
long long sol(long long a, long long b) {
  if (a%b==0) return a/b;
  return sol(b,a%b)+a/b;
}
int main() {
  scanf("%I64d%I64d",&a,&b);
  printf("%I64d\n",sol(a,b));
  return 0;
}