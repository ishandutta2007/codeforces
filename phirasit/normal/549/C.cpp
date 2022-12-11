#include <stdio.h>
#include <set>

#define AWIN printf("Stannis\n");
#define BWIN printf("Daenerys\n");

using namespace std;

typedef pair<int, int> pii;

int odd, even, sum;
int n, k;

int min(int a, int b) {
  return a < b ? a : b;
}
int main() {
  scanf("%d%d", &n, &k);
  odd = even = sum = 0;
  for(int i = 0;i < n;i++) {
    int val;
    scanf("%d", &val);
    if(val%2) {
      odd++;
      sum = not sum;
    }else {
      even++;
    }
  }
  int lf = n - k;
  if(lf == 0) {
    if(sum % 2) {
      AWIN
    }else {
      BWIN
    }
    return 0;
  }
  int a = (lf + 1) / 2, b = lf / 2;
  int ls = lf % 2;
  if(a >= even and (sum + a+b-even) % 2) {
    AWIN
    return 0;
  }
  if(b >= even and (sum + a+b-even) % 2 == 0) {
    BWIN
    return 0;
  }
  if(a >= odd and (sum + odd) % 2) {
    AWIN
    return 0;
  }
  if(b >= odd and (sum + odd)% 2 == 0) {
    BWIN
    return 0;
  }
  if(ls == 1) {
    for(int i = b;i <= a+b;i++) {
      int u = min(odd, i);
      if((sum + u) % 2) {
        AWIN
        return 0;
      }
    }
    BWIN
  }else {
    for(int i = a;i <= a+b;i++) {
      int u = min(odd, i);
      if((sum + u) % 2 == 0) {
        BWIN
        return 0;
      }
    }
    AWIN
  }
  return 0;
}