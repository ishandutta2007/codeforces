#include<bits/stdc++.h>

using namespace std;

const int M = 200005;

struct SuffixArray {
    string a;
    int N, m;
    vector<int> SA, LCP, x, y, w, c;
    SuffixArray(string _a, int m = 256) : a(" " + _a), N(a.size()), m(m),
        SA(N), LCP(N), x(N), y(N), w(max(m, N)), c(N) {
        a[0] = 0;
        DA();
        kasaiLCP();
#define REF(X) { rotate(X.begin(), X.begin()+1, X.end()); X.pop_back(); }
        REF(SA); REF(LCP);
        a.erase(a.begin());
        for (int i = 0; i < (int) SA.size(); ++i) --SA[i];
#undef REF
        buildRMQ();
    }
    inline bool cmp (const int a, const int b, const int l) { return (y[a] == y[b] && y[a + l] == y[b + l]); }
    void Sort() {
        for (int i = 0; i < m; ++i) w[i] = 0;
        for (int i = 0; i < N; ++i) ++w[x[y[i]]];
        for (int i = 0; i < m - 1; ++i) w[i + 1] += w[i];
        for (int i = N - 1; i >= 0; --i) SA[--w[x[y[i]]]] = y[i];
    }

    void DA() {
        for (int i = 0; i < N; ++i) x[i] = a[i], y[i] = i;
        Sort();
        for (int i, j = 1, p = 1; p < N; j <<= 1, m = p) {
            for (p = 0, i = N - j; i < N; i++) y[p++] = i;
            for (int k = 0; k < N; ++k) if (SA[k] >= j) y[p++] = SA[k] - j;
            Sort();
            for (swap(x, y), p = 1, x[SA[0]] = 0, i = 1; i < N; ++i)
                x[SA[i]] = cmp(SA[i - 1], SA[i], j) ? p - 1 : p++;
        }
    }
    void kasaiLCP() {
        for (int i = 0; i < N; i++) c[SA[i]] = i;
        for (int i = 0, j, k = 0; i < N; LCP[c[i++]] = k)
            if (c[i] > 0) for (k ? k-- : 0, j = SA[c[i] - 1]; a[i + k] == a[j + k]; k++);
            else k = 0;
    };

    vector < vector < pair < int, int > > > rmq;
    void buildRMQ() {
      rmq.resize(N, vector < pair < int, int > > (20, {1e9, 1e9}));
      for(int i = N - 1; i > 0; --i) {
        rmq[i][0] = make_pair(LCP[i], i);
        for(int j = 1; j < 20; ++j) {
          if(i + (1 << j) - 1 >= N) continue;
          rmq[i][j] = min(rmq[i][j - 1], rmq[i + (1 << (j - 1))][j - 1]);
        }
      }
    }

    pair < int, int > get(int l, int r) {
      int lg_val = log2(r - l);
      return min(rmq[l + 1][lg_val], rmq[r - (1 << lg_val) + 1][lg_val]);
    }
};

int id[M], n, cnt;
string s, inv;
long long answer;
set < int > pos[M];

int solve(int l, int r, int x, int y, SuffixArray &sa, SuffixArray &sa2) {
  /*** remember that we are putting the asterisk in (id - 1)th position
       so make sure that we are not calculating id = 0
  ***/

  //cout << make_pair(l, r) << ": " << x << endl;

  int idx = ++cnt;
  if(l == r) {
    int p = sa.SA[r];
    if(p == 0) {
  //      if(x == 0) ++answer;
        return idx;
    }
    int leftside = p;
    int rightside = s.size() - p; /// 0 -> rightside
    y = min(y, rightside);
    if(y >= x) answer += 1LL * (y - x + 1) * leftside;
    pos[idx].insert(id[p]);
   // cout << p << " " << make_pair(x, y) << " " << leftside << " " << pos[idx] << endl;
    return idx;
  }

  auto minpos = sa.get(l, r);
  int idlarge, idsmall;
  if(minpos.second - l > r - minpos.second) {
    idlarge = solve(l, minpos.second - 1, x, y, sa, sa2);
    idsmall = solve(minpos.second, r, minpos.first + 1, y, sa, sa2);
  }
  else {
    idlarge = solve(minpos.second, r, x, y, sa, sa2);
    idsmall = solve(l, minpos.second - 1, minpos.first + 1, y, sa, sa2);
  }

  /// now calculate the x -> minpos.first of the idsmall side
  /// also need to subtract from themselves??
  /// they all have the same substring right there so not really matter that way
 // cout << pos[idsmall] << " " << pos[idlarge] << endl;
  for(auto t : pos[idsmall]) {
    auto it = pos[idlarge].upper_bound(t);
    /// x is its position on the second suffix array
    int maxlen = n - sa2.SA[t], bound = -1;
    if(it != pos[idlarge].end()) {
      bound = max(bound, sa2.get(t, *it).first);
    }
    if(it != pos[idlarge].begin()) {
      --it;
      bound = max(bound, sa2.get(*it, t).first);
    }

   // cout << t << " " << make_pair(bound + 1, maxlen) << " " << make_pair(x, minpos.first) << endl;
    if(bound < maxlen && minpos.first >= x) answer += 1LL * (maxlen - bound) * (minpos.first - x + 1);
    pos[idlarge].insert(t);
  }

  return idlarge;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  if(fopen("inp", "r")) freopen("inp", "r", stdin);

  cin >> s;
  inv = s; reverse(inv.begin(), inv.end());
  n = s.size();
  SuffixArray sa(s + " "), sa2(inv + " ");

  answer = 1LL * n * (n + 1) / 2;

  for(auto &x : sa.LCP) answer -= x;

  for(int i = 0; i < sa2.SA.size(); ++i) {
    int p = sa2.SA[i];
    id[n - p + 1] = i;
  }
  //for(int i = 0; i <= n; ++i) cout << id[i] << endl;

  solve(0, n, 0, n + 5, sa, sa2);

  cout << answer + 1 << endl;

  return 0;
}