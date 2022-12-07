#include<bits/stdc++.h>

using namespace std;

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

    long long count_substrings() {
      long long ret = 0;
      for(int i = 0; i < SA.size(); ++i) {
        ret += SA.size() - SA[i];
        ret -= LCP[i];
      }
      return ret;
    }

    string get_kth(long long id) { /// 0-based
      for(int i = 0; i < SA.size(); ++i) {
        int here = SA.size() - SA[i] - LCP[i];
        if(here <= id) id -= here;
        else {
          return a.substr(SA[i], LCP[i] + id + 1);
        }
      }
      return "";
    }
};

const int maxn = 1005;

int n, m;
string s;
long long k;
long long f[maxn][maxn];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  cin >> n >> m >> k >> s;
  SuffixArray sa(s);

  int low = 0, high = sa.count_substrings() - 1, ans = high + 1;

  while(low <= high) {
    int mid = (low + high) >> 1;
    string now = sa.get_kth(mid);

    memset(f, 0, sizeof f);

    f[0][0] = 1;
    f[1][0] = -1;

    for(int i = 0; i < n; ++i) {
      int ok = i;
      for(int j = 0; j < now.size(); ++j) {
        if(ok == n || now[j] > s[ok]) {
          ok = -1;
          break;
        }
        if(now[j] == s[ok]) ok++;
        else break;
      }
      if(ok - i == now.size()) --ok;

      for(int j = 0; j < m; ++j) {
        if(i > 0) {
          f[i][j] += f[i - 1][j];
          if(f[i][j] > k) f[i][j] = k + 1;
        }

        if(ok != -1) {
          f[ok + 1][j + 1] += f[i][j];
          if(f[ok + 1][j + 1] > k) f[ok + 1][j + 1] = k + 1;
        }
      }
    }

    for(int i = 0; i < n; ++i) {
      f[i + 1][m] += f[i][m];
      if(f[i + 1][m] > k) f[i + 1][m] = k + 1;
    }

    if(f[n][m] < k) {
      ans = mid;
      high = mid - 1;
    }
    else {
      low = mid + 1;
    }
  }
  cout << sa.get_kth(ans - 1) << endl;

  return 0;
}