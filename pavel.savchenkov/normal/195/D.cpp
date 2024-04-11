#include <cstdio>
#include <set>

using namespace std;

int n;

int gcd(int a, int b) { return (b) ? gcd(b, a%b) : a; }

int main() {
 scanf("%d", &n);
 set < pair <int, int> > s;
 for (int i = 0; i < n; i++)
 {
  int k, b; scanf("%d%d", &k, &b);
  if  (!k) continue;
  int g = gcd(k, b);
  k /= g; b /= g;
  if  (k < 0) k = -k, b = -b;
  s.insert(make_pair(b, k));
 }
 printf("%d\n", (int)s.size());
 return 0;
}