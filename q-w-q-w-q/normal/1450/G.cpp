#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

const int N = 5005, K = 20;
int n, a, b, tot;
int l[K], r[K], cnt[K];
bool f[1 << K];
char s[N], v[N];

bool check(int s) {
  int lt = n, rt = 0, sz = 0;
  for (int i = 0; i < tot; i++)
    if (s >> i & 1) {
      lt = min(lt, l[i]);
      rt = max(rt, r[i]);
      sz += cnt[i];
    }
  return b * sz >= a * (rt - lt + 1);
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  cin >> n >> a >> b >> s;
  memcpy(v, s, sizeof v);
  sort(v, v + n);
  tot = unique(v, v + n) - v;
  for (int i = 0; i < n; i++) {
    int x = lower_bound(v, v + tot, s[i]) - v;
    if (!cnt[x])
      l[x] = i;
    r[x] = i;
    cnt[x]++;
  }

  f[0] = 1;
  for (int s = 1; s < (1 << tot); s++) {
    if (check(s))
      for (int i = 0; i < tot; i++)
        if (s >> i & 1)
          f[s] |= f[s ^ (1 << i)];

    vector<pair<int, int>> a;
    for (int i = 0; i < tot; i++)
      if (s >> i & 1)
        a.push_back(make_pair(r[i], i));
    sort(a.begin(), a.end());

    int t = 0;
    for (auto tp : a) {
      t |= 1 << tp.second;
      f[s] |= f[t] & f[s ^ t];
    }
  }

  vector<int> ans;
  for (int i = 0; i < tot; i++)
    if (f[((1 << tot) - 1) ^ (1 << i)])
      ans.push_back(i);
  cout << ans.size();
  for (int i = 0; i < (int)ans.size(); i++)
    cout << ' ' << v[ans[i]];
}