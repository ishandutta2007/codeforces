#include<bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int n; cin >> n;
  vector<long long> a(n);
  for(long long &x : a) cin >> x;

  vector<int> cnt(2200005), sum = cnt;

  for(int x : a) {
    int first = 1, cstx = 0;
    for(int y = x; y > 0; y >>= 1) {
      int csty = cstx;
      for(int z = y; z < cnt.size(); z <<= 1) {
        cnt[z] += csty;
        sum[z]++;
        csty++;
        if(!first) break;
      }
      if((y / 2) * 2 != y) first = 1;
      else first = 0;
      cstx++;
    }
  }

  int ans = n * 40;
  for(int i = 0; i < sum.size(); ++i) {
    if(sum[i] == n) {
      ans = min(ans, cnt[i]);
    }
  }

  cout << ans << endl;

  return 0;
}