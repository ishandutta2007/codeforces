#include <bits/stdc++.h>
using namespace std;

typedef long long int LLI;

LLI n;
string ans;
LLI high, low;

LLI comb4(LLI x) {
  return x*(x-1)*(x-2)*(x-3)/24;
}

int main() {
  scanf("%I64d", &n);
  ans = "a";
  low = -1;
  high = 101;
  while (high - low > 1) {
    LLI mid = (high+low)/2;
    LLI t = comb4(mid);
    if (t <= n) low = mid;
    else high = mid;
  }

  LLI rem = n;
  for (LLI i=0; i<low-3; i++) {
    LLI t = rem/comb4(low-i);
    for (LLI j=0; j<t; j++) {
      printf("a");
    }
    printf("b");
    
    rem -= comb4(low-i)*t;
  }
  printf("bbb");
  puts(" abbbb");
}