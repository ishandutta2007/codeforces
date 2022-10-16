#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define sqr(x) ((x) * (x))
#define all(x) (x).begin(), (x).end()
#define reset(x, y) memset(x, y, sizeof(x))
#define uni(x) (x).erase(unique(all(x)), (x).end())
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

const int maxn = 112345;

struct Rec {
  int l, r, u, d;
} tab[maxn];

struct cmpl {
  inline bool operator () (const Rec &r1, const Rec &r2) {
    return r1.l == r2.l ? r1.d < r2.d : r1.l < r2.l;
  }
};

struct cmpd {
  inline bool operator () (const Rec &r1, const Rec &r2) {
    return r1.d == r2.d ? r1.l < r2.l : r1.d < r2.d;
  }
};

struct cmpr {
  inline bool operator () (const Rec &r1, const Rec &r2) {
    return r1.r == r2.r ? r1.u < r2.u : r1.r > r2.r;
  }
};

struct cmpu {
  inline bool operator () (const Rec &r1, const Rec &r2) {
    return r1.u == r2.u ? r1.r < r2.r : r1.u > r2.u;
  }
};

int n;

int main() {
  scanf("%d", &n);
  set<Rec, cmpl> ini1;
  set<Rec, cmpd> ini2;
  set<Rec, cmpr> ini3;
  set<Rec, cmpu> ini4;
  FOR(i, 1, n) {
    scanf("%d%d%d%d", &tab[i].l, &tab[i].d, &tab[i].r, &tab[i].u);
    ini1.emplace(tab[i]);
    ini2.emplace(tab[i]);
    ini3.emplace(tab[i]);
    ini4.emplace(tab[i]);
  }

  auto solve = [](auto &&self, auto &s1, auto &s2, auto &s3, auto &s4) -> bool {
    if (s1.size() == 1) {
      s1.clear();
      s2.clear();
      s3.clear();
      s4.clear();
      return true;
    }
    int cnt = s1.size() - 1;
    decltype(ini1) t1; auto it1 = s1.begin();
    decltype(ini2) t2; auto it2 = s2.begin();
    decltype(ini3) t3; auto it3 = s3.begin();
    decltype(ini4) t4; auto it4 = s4.begin();
    int mxx = 0, mxy = 0, mnx = 1e9, mny = 1e9;

    auto go = [](auto &s1, auto &s2, auto &s3, auto &s4, auto &t1, auto &t2, auto &t3, auto &t4, auto till) {
      auto it = s1.begin();
      while (it != till) {
        auto tmp = *it; it++;
        s1.erase(tmp); t1.emplace(tmp);
        s2.erase(tmp); t2.emplace(tmp);
        s3.erase(tmp); t3.emplace(tmp);
        s4.erase(tmp); t4.emplace(tmp);
      }
    };

    while (cnt--) {
      chkmax(mxx, it1->r); it1++;
      if (mxx <= it1->l) {
        go(s1, s2, s3, s4, t1, t2, t3, t4, it1);
        return self(self, t1, t2, t3, t4) && self(self, s1, s2, s3, s4);
      }
      chkmax(mxy, it2->u); it2++;
      if (mxy <= it2->d) {
        go(s2, s1, s3, s4, t1, t2, t3, t4, it2);
        return self(self, t1, t2, t3, t4) && self(self, s1, s2, s3, s4);
      }
      chkmin(mnx, it3->l); it3++;
      if (mnx >= it3->r) {
        go(s3, s1, s2, s4, t1, t2, t3, t4, it3);
        return self(self, t1, t2, t3, t4) && self(self, s1, s2, s3, s4);
      }
      chkmin(mny, it4->d); it4++;
      if (mny >= it4->u) {
        go(s4, s1, s2, s3, t1, t2, t3, t4, it4);
        return self(self, t1, t2, t3, t4) && self(self, s1, s2, s3, s4);
      }
    }
    return false;
  };

  puts(solve(solve, ini1, ini2, ini3, ini4) ? "YES" : "NO");
}