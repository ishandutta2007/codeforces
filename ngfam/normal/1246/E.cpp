#include<bits/stdc++.h>

using namespace std;

const int MAXN = 16;
const int MAXK = 2002;

int n, k;
int a[MAXN];
int b[MAXN];
bitset < MAXK > f[1 << MAXN];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int large = 0;

  cin >> n >> k;
  for(int i = 0; i < n; ++i) {
    cin >> a[i];
    large += a[i];
  }

  f[0][0] = 1;
  large -= large % k;

  for(int mask = 1; mask < (1 << n); ++mask) {
    for(int i = 0; i < n; ++i) {
      if(mask & (1 << i)) {
        f[mask] |= f[mask ^ (1 << i)] << a[i];
      }
    }
    for(int x = large; x > 0; x -= k) {
      if(f[mask][x]) f[mask][x / k] = 1;
    }
  }

  if(f[(1 << n) - 1][1]) {
    cout << "YES\n";
    int cur_deg = 0, cur_mask = (1 << n) - 1, curx = 1;

    while(true) {
      if(cur_mask == 0) break;
      int found = 0;
      for(int i = 0; i < n; ++i) {
        if(cur_mask & (1 << i)) {
          if((f[cur_mask ^ (1 << i)] << a[i])[curx]) {
            found = 1;
            b[i] = cur_deg;
            cur_mask ^= (1 << i);
            curx -= a[i];
            break;
          }
        }
      }
      if(found) continue;
      ++cur_deg;
      curx *= k;
    }

    multiset < pair < int, int > > vals;
    for(int i = 0; i < n; ++i) vals.emplace(b[i], a[i]);

    while(vals.size() > 1) {
      auto p = *vals.rbegin(); vals.erase(vals.find(p));
      auto q = *vals.rbegin(); vals.erase(vals.find(q));
      cout << p.second << " " << q.second << endl;
      p.second += q.second;
      while(p.second % k == 0) {
        p.second /= k;
        p.first--;
      }
      vals.insert(p);
    }
  }
  else {
    cout << "NO\n";
  }

  return 0;
}