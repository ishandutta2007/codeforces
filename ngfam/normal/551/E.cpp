#include<bits/stdc++.h>
#define int long long

using namespace std;

const int MAXN = 500050;
const int Base = 750;

int n, q;
int a[MAXN];

int lazy[Base];
vector<pair<int, int>> comp[Base];

main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  cin >> n >> q;
  for(int i = 0; i < n; ++i) cin >> a[i];

  for(int i = 0; i < n; ++i) {
    comp[i / Base].emplace_back(a[i], i);
  }

  for(int i = 0; i < Base; ++i) {
    sort(comp[i].begin(), comp[i].end());
  }

  while(q--) {
    int t;
    cin >> t;

    if(t == 1) {
      int l, r, x;
      cin >> l >> r >> x;
      --l; --r;
      int u = (l / Base), v = (r / Base);
      while(l <= r) {
        if(l % Base == 0 && l + Base - 1 <= r) {
          lazy[l / Base] += x;
          l += Base;
          continue;
        }
        a[l] += x;
        l++;
      }

      comp[u].clear();
      for(int i = u * Base; i < min(n, (u + 1) * Base); ++i) {
        a[i] += lazy[u];
        comp[u].emplace_back(a[i], i);
      }
      lazy[u] = 0;
      sort(comp[u].begin(), comp[u].end());

      comp[v].clear();
      for(int i = v * Base; i < min(n, (v + 1) * Base); ++i) {
        a[i] += lazy[v];
        comp[v].emplace_back(a[i], i);
      }
      lazy[v] = 0;
      sort(comp[v].begin(), comp[v].end());
    }
    else {
      int x; cin >> x;

      int ansl = n + 1, ansr = -1;
      for(int i = 0; i < Base; ++i){
        auto fpos = lower_bound(comp[i].begin(), comp[i].end(), make_pair(x - lazy[i], -1LL));
        if(fpos != comp[i].end() && fpos -> first == x - lazy[i]) {
          ansl = min(ansl, fpos -> second);
          ansr = max(ansr, fpos -> second);
        }
        auto gpos = upper_bound(comp[i].begin(), comp[i].end(), make_pair(x - lazy[i], n));
        if(gpos != comp[i].begin()) --gpos;
        if(gpos != comp[i].end() && gpos -> first == x - lazy[i]) {
          ansl = min(ansl, gpos -> second);
          ansr = max(ansr, gpos -> second);
        }
      }

      if(ansl > ansr) cout << -1 << "\n";
      else cout << ansr - ansl << "\n";
    }
  }

  return 0;
}