#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int A, B, C, D;
  cin >> A >> B >> C >> D;
  int R1 = B - A;
  int R2 = C - B;
  lint ans = 0;

  vector<lint> can(2 * D + 5);
  for (int x = A; x <= B; x++) {
    can[x + B]++;
    can[x + C + 1]--;
  }
  for (int i = 1; i < D + 5; i++) {
    can[i] += can[i - 1];
  }

  for (int i = 1; i < D + 5; i++) {
    can[i] += can[i - 1];
  }
  for (int z = C; z <= D; z++) {
    // x + y > z -> x + y - z - 1 >= 0
    ans += 1ll * (B - A + 1) * (C - B + 1);
    ans -= can[z];
  }
  
  cout << ans << "\n";
  return 0;
}