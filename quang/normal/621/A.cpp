#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n;
long long sum = 0;
int numodd = 0, valodd = (1 << 30);

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int u;
    scanf("%d",&u);
    sum += u;
    if (u & 1) {
      numodd ^= 1;
      valodd = min(valodd, u);
    }
  }
  if (numodd) {
    cout << sum - valodd;
  } else {
    cout << sum;
  }
  return 0;
}