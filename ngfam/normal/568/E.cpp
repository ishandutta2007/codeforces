// Things learned:

// 1) std::max(pair, pair) is as slow as your fucking brain, dont use interactive
// 2) Fenwick can also be rebuilt. Use in case only prefix or suffix max min required
// 3) I really shouldnt implement segtree from the start, shouldn't I
//

#include<bits/stdc++.h>

using namespace std;

const int MAXN = 200005;

pair<int, int> f[MAXN], g[MAXN];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int n; cin >> n;

  vector<int> a(n);

  vector<pair<int, int>> b;
  for(int i = 0; i < n; ++i) {
    cin >> a[i];
    if(a[i] != -1) b.emplace_back(a[i], 0);
  }

  multiset<int> avail;

  int m; cin >> m;
  for(int i = 0; i < m; ++i) {
    int x; cin >> x;
    if(!avail.count(x)) b.emplace_back(x, 1);
    avail.insert(x);
  }

  b.emplace_back(-1, 0);
  b.emplace_back((int)1e9 + 7, 0);
  sort(b.begin(), b.end());

  vector<int> kpos;

  for(int i = b.size() - 1; i >= 0; --i) {
    if(b[i].second) kpos.push_back(i + 1);
  }

  fill(f, f + MAXN, make_pair(1, -1));

  int sz = b.size();

  for(int i = 0; i < n; ++i) {
    if(a[i] != -1) {
      int fpos = lower_bound(b.begin(), b.end(), make_pair(a[i], 0)) - b.begin();
      auto val = make_pair(-1, -1);

      for(int x = fpos; x > 0; x -= x & -x) {
        if(f[x].first > val.first) val = f[x];
      }
      g[i] = val;
      g[i].first++;
      val.first++;
      val.second = i;
      int gpos = upper_bound(b.begin(), b.end(), make_pair(a[i], 1)) - b.begin();
      for(int x = gpos; x < sz; x += x & -x) {
        if(val.first > f[x].first) f[x] = val;
      }
    }
    else {
      for(int x = 1; x < sz; ++x) {
        if(f[x - 1].first > f[x].first) f[x] = f[x - 1];
      }
      for(int x : kpos) {
        if(f[x].first < f[x - 1].first + 1) {
          f[x].first = f[x - 1].first + 1;
          f[x].second = f[x - 1].second;
        }
      }

      for(int x = 1; x < sz; ++x) {
        if(f[x - 1].first > f[x].first) f[x] = f[x - 1];
      }
    }
  }

  for(int x = 1; x < b.size(); ++x) {
    f[x] = max(f[x], f[x - 1]);
  }

///  cout << g[2] << endl;

  vector<bool> mark(n);

  vector<int> pos;
  for(int i = f[b.size() - 1].second; i >= 0;) {
    pos.push_back(i);
    mark[i] = 1;
    i = g[i].second;
  }
  reverse(pos.begin(), pos.end());


  int last = 1e9 + 7;
  for(int i = n - 1; i >= 0; --i) {
    if(mark[i]) pos.pop_back(), last = a[i];
    if(a[i] == -1) {
      auto it = avail.lower_bound(last);
      if(it == avail.begin()) continue;
      --it;

      if(pos.empty() || *it > a[pos.back()]) {
        last = a[i] = *it;
        avail.erase(it);
      }
    }
  }

  for(int i = 0; i < n; ++i) {
    if(a[i] == -1) {
      a[i] = *avail.begin();
      avail.erase(avail.begin());
    }
    cout << a[i] << " ";
  }



  return 0;
}