#include <vector>
#include <map>
#include <iostream>
#include <cstdio>
#include <cassert>
#include <algorithm>
#include <memory.h>
using namespace std;
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef long double ld;
typedef vector<int> Vint;

#define forn(i, n) for (int i = 0; i < (int) n; ++i)
#define sz(c) ((int) (c).size())

const int INF = (int)1e9;
struct SegmTree {

  vector<int> t;

  int sz;



  SegmTree(const vector<int>& a) {

    sz = 1;

    while (sz < (int) a.size()) sz *= 2;



    t.assign(sz * 2, INF);

    for (int v = sz; v < sz + (int) a.size(); ++v) {

      t[v] = a[v - sz];

    }

    for (int v = sz - 1; v > 0; --v) {

      t[v] = min(t[v * 2], t[v * 2 + 1]);

    }

  }



  int get_min(int l, int r) {

    int res = INF;

    l += sz;

    r += sz;

    while (l <= r) {

      res = min(res, t[l]);

      res = min(res, t[r]);

      l = (l + 1) / 2;

      r = (r - 1) / 2;

    }
    return res;
  }
};

    const int PP = 7;
    const int MAXN = 1 << 21;
    const int MOD[2] = { (int) 1e9 + 7, (int) 1e9 + 17 };
     
    void add(int& x, int y, int mod) {
      ((x += y) >= mod) && (x -= mod);
    }
     
    int mul(int x, int y, int mod) {
      return x * 1ll * y % mod;
    }
     
    struct Hash {
      static const int SZ = 2;
     
      int v[SZ];
     
      Hash(int x = 0) {
        forn(i, SZ) v[i] = x % MOD[i];
      }
     
      void operator += (const Hash& h) {
        forn(i, SZ) {
          add(v[i], h.v[i], MOD[i]);
        }
      }
     
      void operator -= (const Hash& h) {
        forn(i, SZ) {
          add(v[i], - h.v[i] + MOD[i], MOD[i]);
        }
      }
     
      void operator *= (const Hash& h) {
        forn(i, SZ) {
          v[i] = mul(v[i], h.v[i], MOD[i]);
        }
      }
     
      void operator *= (const int& h) {
        forn(i, SZ) {
          v[i] = mul(v[i], h, MOD[i]);
        }
      }
     
      void print() const {
        printf("%d %d\n", v[0], v[1]);
      }
    };
     
     
      Hash operator * (const Hash& h1, const Hash& h2) {
        Hash h = h1;
        h *= h2;
        return h;
      }
     
      Hash operator * (const Hash& h1, const int& h2) {
        Hash h = h1;
        h *= h2;
        return h;
      }
     
      Hash operator + (const Hash& h1, const Hash& h2) {
        Hash h = h1;
        h += h2;
        return h;
      }
     
      Hash operator - (const Hash& h1, const Hash& h2) {
        Hash h = h1;
        h -= h2;
        return h;
      }
     
      bool operator == (const Hash& h1, const Hash& h2) {
        return h1.v[0] == h2.v[0] && h1.v[1] == h2.v[1];
      }
     
      bool operator != (const Hash& h1, const Hash& h2) {
        return !(h1.v[0] == h2.v[0] && h1.v[1] == h2.v[1]);
      }
     
      bool operator < (const Hash& h1, const Hash& h2) {
        return h1.v[0] < h2.v[0] || (h1.v[0] == h2.v[0] && h1.v[1] < h2.v[1]);
      }
          
    struct Solver {
      vector<Hash> pref;
      vector<Hash> P;
      string s;
     
      Solver(const string& s) : s(s) {
        P.resize(MAXN);
        P[0] = Hash(1);
        for (int i = 1; i < MAXN; ++i) {
          P[i] = PP * P[i - 1];
        }
     
        pref.assign(sz(s) + 1, 0);
        forn(i, sz(s)) {
          int c = (s[i] == ')') + 1;
          Hash cur = P[i] * c;
          pref[i + 1] = pref[i] + cur;
        }
      }
     
      Hash hash(int l, int r) {
        Hash res = pref[r + 1] - pref[l];
        res *= P[MAXN - r - 1];
        return res;
      }
     
     
    };

int nn;
Solver text_hashes("dfdgggd");
string text;
bool weird_cmp(int l, int r)
{
    int maxlen = nn - max(r, l);

    int left = 0;
    int right = maxlen + 1;

    while (right - left > 1)
    {
        int mid = (right + left) / 2;
        if (text_hashes.hash(l, mid + l - 1) == text_hashes.hash(r, mid + r - 1))
            left = mid;
        else
            right = mid;
    }

    return text[l + left] < text[r + left];
}

void solve(string s)
{
    int n = (int)s.size();
    nn = 2 * n;

    text = s + s + char(0);

    vector<int> pref(2 * n + 1, 0);
    for (int i = 1; i <= 2 * n; i++)
        pref[i] = pref[i - 1] + (text[i - 1] == '(' ? 1 : -1);

    SegmTree Min(pref);

    Vint minbal(n);

    for (int i = 0; i < n; i++)
    {
        int l = i + 1;
        int r = i + n;

        int cnt = Min.get_min(l, r) - pref[i];
        if (cnt > 0)
            cnt = 0;

        minbal[i] = cnt;
    }

    Vint cands;
    int allbest = *max_element(minbal.begin(), minbal.end());
    assert(allbest <= 0);

    for (int i = 0; i < n; i++)
    if (minbal[i] == allbest)
        cands.pb(i);

    text_hashes = Solver(text);
//    sort(cands.begin(), cands.end(), weird_cmp);
    int pos = cands[0];
    for (int i = 1; i < sz(cands); ++i) {
      if  (weird_cmp(cands[i], pos)) pos = cands[i];
    }

    string ans = string(-allbest, '(');
    ans += text.substr(pos, n);

    int cntbal = 0;
    for (int i = 0; i < (int)ans.size(); i++)
    {
        if (ans[i] == '(')
            cntbal++;
        else if (ans[i] == ')')
            cntbal--;
        else
            assert(0);

        assert(cntbal >= 0);
    }

    ans += string(cntbal, ')');
    cout << ans << endl;
}

int main()
{
    #ifdef LOCAL
    freopen(".in", "rt", stdin);
//    freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    string s;
    while (cin >> s)
        solve(s);
}