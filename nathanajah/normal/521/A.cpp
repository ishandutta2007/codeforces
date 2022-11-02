#include <bits/stdc++.h>
using namespace std;

int n;
char c[100005];
int res = 0;
int cnt[100005];
int maxi;
int nummax;
long long MOD = 1000000007;

int main() {
  scanf("%d",&n);
  scanf("%s",c);
  for (int i = 0; i < n; i++) {
    ++cnt[c[i]];
  }
  maxi = 0;
  for (int i = 0; i < 500; i++) {
    if (cnt[i] > maxi) {
      maxi = cnt[i];
      nummax = 0;
    }
    if (cnt[i] == maxi) {
      ++nummax;
    }
  }
  long long res = 1;
  for (int i = 0; i < n; i++) {
    res = (res * nummax) % MOD;
  }
  printf("%I64d\n", res);
}