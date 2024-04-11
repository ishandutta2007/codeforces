#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int N = 2e5 + 123;

enum Type {
  ASK = 0,
  END = 1,
  BEGIN = 2
};

int d, n, m;
int c[N];

int main() {
  ios::sync_with_stdio(false);
  cout.tie(0);
  cin.tie(0);
  
  #ifdef LOCAL
  freopen("input.txt", "r", stdin);
  #endif
  
  cin >> d >> n >> m;
  
  vector<pair<int, pair<int, int>>> events;
  events.reserve(4 * m + 4);
  
  events.push_back({0, {BEGIN, 0}});
  events.push_back({n, {END, 0}});
  events.push_back({n, {ASK, 0}});
  events.push_back({d, {ASK, 0}});
  
  for (int i = 1; i <= m; i++) {
    int x;
    cin >> x >> c[i];
    events.push_back({x, {BEGIN, i}});
    events.push_back({x + n, {END, i}});
    events.push_back({x, {ASK, i}});
    events.push_back({x + n, {ASK, i}});
  }
  
  sort(events.begin(), events.end());
  
  ll ans = 0;
  multiset<int> q;
  int prev_x = 0;
  
  for (auto &ev : events) {
    if (ev.first > d) break;
    
    if (ev.second.first == BEGIN) {
      q.insert(c[ev.second.second]);
    } else if (ev.second.first == END) {
      q.erase(q.find(c[ev.second.second]));
    } else {
      if (q.empty()) {
        cout << "-1\n";
        return 0;
      }
      
      ans += (*q.begin()) * 1LL * (ev.first - prev_x);
      prev_x = ev.first;
    }
  }
  
  cout << ans << "\n";
  
  return 0;
}