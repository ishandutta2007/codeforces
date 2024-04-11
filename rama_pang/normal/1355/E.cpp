#include <bits/stdc++.h>
using namespace std;
using lint = long long;
const int MAXN = 1e5 + 5;

lint N, A, R, M;
lint H[MAXN];
pair<lint, lint> pref[MAXN];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  cin >> N >> A >> R >> M;
  M = min(M, A + R);
  vector<lint> coords;
  for (int i = 0; i < N; i++) {
    cin >> H[i];
    coords.emplace_back(H[i]);
  }
  sort(begin(coords), end(coords));
  coords.resize(unique(begin(coords), end(coords)) - begin(coords));
  int n = coords.size();
  for (int i = 0; i < N; i++) {
    int pos = lower_bound(begin(coords), end(coords), H[i]) - begin(coords);
    pref[pos].second++;
    pref[pos].first += H[i];
  }
  for (int i = 1; i < n; i++) {
    pref[i].first += pref[i - 1].first;
    pref[i].second += pref[i - 1].second;
  }
  lint ans = 2e18;
  for (int i = 0; i < n; i++) {
    lint take = (pref[n - 1].first - pref[i].first) - ((pref[n - 1].second - pref[i].second) * coords[i]);
    lint need = pref[i].second * coords[i] - pref[i].first;
    // cout << coords[i] << " " << need << " " << take << " q\n";

    lint cost = min(need, take) * M;
    if (need < take) cost += (take - need) * R;
    if (need > take) cost += (need - take) * A;
    ans = min(ans, cost);
  }

  lint sum = 0;
  for (int i = 0; i < N; i++) {
    sum += H[i];
  }
  ans = min(ans, (*max_element(H, H + N) * N - sum) * A);
  ans = min(ans, (sum - *min_element(H, H + N) * N) * R);
  if (sum % N == 0) {
    sum /= N;
    lint cost = 0;
    for (int i = 0; i < N; i++) {
      cost += abs(H[i] - sum);
    }
    cost /= 2;
    ans = min(ans, cost * M);
  }

  auto MinCost = [&](lint h) {
    int i = upper_bound(begin(coords), end(coords), h) - begin(coords) - 1;
    lint take = (pref[n - 1].first - pref[i].first) - ((pref[n - 1].second - pref[i].second) * h);
    lint need = pref[i].second * h - pref[i].first;
    // cout << coords[i] << " " << need << " " << take << " q\n";

    lint cost = min(need, take) * M;
    if (need < take) cost += (take - need) * R;
    if (need > take) cost += (need - take) * A;
    // cout << need << " " << take << "\n";
    ans = min(ans, cost);
    return cost;
  }; 

  lint lo = 0, hi = 1e9;
  while (lo < hi) {
    lint mid = (lo + hi) / 2;
    if (MinCost(mid) < MinCost(mid + 1)) {
      hi = mid;
    } else {
      lo = mid + 1;
    }
  }

  cout << ans << "\n";
  return 0;
}