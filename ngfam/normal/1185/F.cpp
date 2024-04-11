#include <bits/stdc++.h>

using namespace std;

const int N = (1 << 9);

int n, m;
int f[N];
vector < pair < int, int > > prices[N];

int main(){
	ios_base::sync_with_stdio(false); 
  cin.tie(NULL); cout.tie(NULL); 

  cin >> n >> m;
  for(int i = 1; i <= n; ++i) {
    int sz; cin >> sz;
    int mask = 0;

    while(sz--) {
      int x; cin >> x;
      mask |= (1 << (x - 1));
    }
    for(int bigmask = 0; bigmask < N; bigmask++) {
      if((bigmask | mask) == bigmask) ++f[bigmask];
    }
  }

  for(int i = 1; i <= m; ++i) {
    int val, sz, mask = 0;
    cin >> val >> sz;

    while(sz--) {
      int x; cin >> x;
      mask |= (1 << (x - 1));
    }

    prices[mask].emplace_back(val, i);
  }

  for(int i = 0; i < N; ++i) sort(prices[i].begin(), prices[i].end());

  pair < int, int > ans = make_pair(0, (int)2e9 + 1);
  pair < int, int > ret = make_pair(-1, -1);
  for(int mask = 0; mask < N; ++mask) {
    for(int otherMask = 0; otherMask < N; ++otherMask) {
      if(otherMask != mask && prices[mask].size() && prices[otherMask].size()) {
        int tot = f[otherMask | mask], sum = prices[mask].front().first + prices[otherMask].front().first;
        if(tot > ans.first || (tot == ans.first && sum < ans.second)) {
          ans = make_pair(tot, sum);
          ret = make_pair(prices[mask].front().second, prices[otherMask].front().second);
        }
      }
    }

    if(prices[mask].size() > 1) {
      if(f[mask] > ans.first || (f[mask] == ans.first && prices[mask][0].first + prices[mask][1].first < ans.second)) {
        ans = make_pair(f[mask], prices[mask][0].first + prices[mask][1].first);
        ret = make_pair(prices[mask][0].second, prices[mask][1].second);
      }
    }
  }

  cout << ret.first << " " << ret.second << endl;

  return 0;
}