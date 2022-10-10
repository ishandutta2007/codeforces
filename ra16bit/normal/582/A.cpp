#include <cstdio>
#include <set>
using namespace std;
int n,i,j,k,a,r[505];
multiset<int> s;
int gcd(int a, int b) { return b?gcd(b,a%b):a; }
int main() {
  scanf("%d",&n);
  for (i=0; i<n*n; i++) {
    scanf("%d",&a);
    s.insert(a);
  }
  for (i=0; i<n; i++) {
    r[i]=*(--s.end());
    s.erase(s.find(r[i]));
    for (j=0; j<i; j++) for (k=0; k<2; k++) s.erase(s.find(gcd(r[i],r[j])));
  }
  for (i=0; i<n; i++) printf("%d ",r[i]);
  return 0;
}