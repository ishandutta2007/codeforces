#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

const int N = 5010;
const long long inf = 1ll << 60;

int l[N], r[N];
set<int> S;
vector<int> pos;
vector<long long> dp;
int n, x;

int dis(int a, int b) {
  return abs(a - b);
}
int dis(int p, int l, int r) {
  if(p > r) return p - r;
  if(p < l) return l - p;
  return 0;
}
int main() {
  cin >> n >> x;
  S.insert(x);
  for(int i = 0;i < n;i++) {
    cin >> l[i] >> r[i];
    S.insert(l[i]);
    S.insert(r[i]);
  }
  pos.assign(S.begin(), S.end());
  dp.resize(pos.size(), 0ll);
  for(int j = 0;j < pos.size();j++) dp[j] = dis(pos[j], x);
  for(int i = 0;i < n;i++) {
    long long mn = inf;
    for(int j = 0;j < pos.size();j++) {
      mn = min(mn, dp[j] - pos[j]);
      dp[j] = pos[j] + mn;
    }
    mn = inf;
    for(int j = pos.size()-1;j >= 0;j--) {
      mn = min(mn, dp[j] + pos[j]);
      dp[j] = mn - pos[j];
    }
    for(int j = 0;j < pos.size();j++) {
      dp[j] += dis(pos[j], l[i], r[i]);
    }
  }
  long long ans = inf;
  for(long long val : dp) {
    ans = min(ans, val);
  }
  cout << ans << endl;
  return 0;
}