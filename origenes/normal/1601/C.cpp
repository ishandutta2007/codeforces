#include <bits/stdc++.h>


#include <cassert>
#include <numeric>
#include <type_traits>

namespace atcoder {

namespace internal {

#ifndef _MSC_VER
template <class T>
using is_signed_int128 =
    typename std::conditional<std::is_same<T, __int128_t>::value ||
                                  std::is_same<T, __int128>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using is_unsigned_int128 =
    typename std::conditional<std::is_same<T, __uint128_t>::value ||
                                  std::is_same<T, unsigned __int128>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using make_unsigned_int128 =
    typename std::conditional<std::is_same<T, __int128_t>::value,
                              __uint128_t,
                              unsigned __int128>;

template <class T>
using is_integral = typename std::conditional<std::is_integral<T>::value ||
                                                  is_signed_int128<T>::value ||
                                                  is_unsigned_int128<T>::value,
                                              std::true_type,
                                              std::false_type>::type;

template <class T>
using is_signed_int = typename std::conditional<(is_integral<T>::value &&
                                                 std::is_signed<T>::value) ||
                                                    is_signed_int128<T>::value,
                                                std::true_type,
                                                std::false_type>::type;

template <class T>
using is_unsigned_int =
    typename std::conditional<(is_integral<T>::value &&
                               std::is_unsigned<T>::value) ||
                                  is_unsigned_int128<T>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using to_unsigned = typename std::conditional<
    is_signed_int128<T>::value,
    make_unsigned_int128<T>,
    typename std::conditional<std::is_signed<T>::value,
                              std::make_unsigned<T>,
                              std::common_type<T>>::type>::type;

#else

template <class T> using is_integral = typename std::is_integral<T>;

template <class T>
using is_signed_int =
    typename std::conditional<is_integral<T>::value && std::is_signed<T>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using is_unsigned_int =
    typename std::conditional<is_integral<T>::value &&
                                  std::is_unsigned<T>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using to_unsigned = typename std::conditional<is_signed_int<T>::value,
                                              std::make_unsigned<T>,
                                              std::common_type<T>>::type;

#endif

template <class T>
using is_signed_int_t = std::enable_if_t<is_signed_int<T>::value>;

template <class T>
using is_unsigned_int_t = std::enable_if_t<is_unsigned_int<T>::value>;

template <class T> using to_unsigned_t = typename to_unsigned<T>::type;

}  // namespace internal

}  // namespace atcoder

#include <cassert>
#include <vector>

namespace atcoder {

// Reference: https://en.wikipedia.org/wiki/Fenwick_tree
template <class T> struct fenwick_tree {
    using U = internal::to_unsigned_t<T>;

  public:
    fenwick_tree() : _n(0) {}
    fenwick_tree(int n) : _n(n), data(n) {}

    void add(int p, T x) {
        assert(0 <= p && p < _n);
        p++;
        while (p <= _n) {
            data[p - 1] += U(x);
            p += p & -p;
        }
    }

    T sum(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        return sum(r) - sum(l);
    }

  private:
    int _n;
    std::vector<U> data;

    U sum(int r) {
        U s = 0;
        while (r > 0) {
            s += data[r - 1];
            r -= r & -r;
        }
        return s;
    }
};

}  // namespace atcoder


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

const int maxn = 1123456;

struct Seg {
  int l, r;
  int pos, mn, lzy;
} T[maxn << 2];

void push_up(int o) {
  if (T[o << 1].mn < T[o << 1 | 1].mn) {
    T[o].mn = T[o << 1].mn;
    T[o].pos = T[o << 1].pos;
  } else if (T[o << 1].mn > T[o << 1 | 1].mn) {
    T[o].mn = T[o << 1 | 1].mn;
    T[o].pos = T[o << 1 | 1].pos;
  } else {
    T[o].mn = T[o << 1].mn;
    T[o].pos = min(T[o << 1].pos, T[o << 1 | 1].pos);
  }
}

void push_down(int o) {
  if (T[o].lzy) {
    T[o << 1].mn += T[o].lzy; T[o << 1].lzy += T[o].lzy;
    T[o << 1 | 1].mn += T[o].lzy; T[o << 1 | 1].lzy += T[o].lzy;
    T[o].lzy = 0;
  }
}

void build(int o, int l, int r) {
  T[o].lzy = 0;
  T[o].l = l, T[o].r = r;
  if (l == r) T[o].pos = T[o].mn = l;
  else {
    int mi = l + r >> 1;
    build(o << 1, l, mi);
    build(o << 1 | 1, mi + 1, r);
    push_up(o);
  }
}

void update(int o, int l, int r, int v) {
  if (l <= T[o].l && T[o].r <= r) {
    T[o].mn += v;
    T[o].lzy += v;
    return;
  }
  int mi = T[o].l + T[o].r >> 1;
  push_down(o);
  if (l <= mi) update(o << 1, l, r, v);
  if (r > mi) update(o << 1 | 1, l, r, v);
  push_up(o);
}

pii query(int o, int l, int r) {
  if (r < T[o].l || l > T[o].r) return {1e9, 0};
  if (l <= T[o].l && T[o].r <= r) return {T[o].mn, T[o].pos};
  push_down(o);
  auto [mn, pos] = query(o << 1, l, r);
  auto [mn2, pos2] = query(o << 1 | 1, l, r);
  if (mn < mn2) return {mn, pos};
  if (mn > mn2) return {mn2, pos2};
  return {mn, min(pos, pos2)};
}

int a[maxn], b[maxn], id[maxn];

void solve() {
  int n, m;
  cin >> n >> m;
  FOR(i, 1, n) cin >> a[i];
  FOR(i, 1, m) cin >> b[i];
  iota(id + 1, id + n + 1, 1);
  sort(id + 1, id + n + 1, [](int x, int y) { return a[x] < a[y]; });
  sort(b + 1, b + m + 1);
  build(1, 0, n);
  int p1 = 1, p2 = 1, border = 0;
  ll ans = 0;
  FOR(i, 1, m) {
    while (p1 <= n && a[id[p1]] < b[i]) {
      update(1, 0, id[p1] - 1, 1);
      p1++;
    }
    while (p2 <= n && a[id[p2]] <= b[i]) {
      update(1, id[p2], n, -1);
      p2++;
    }
    auto [v, p] = query(1, border, n);
    ans += v;
    border = p;
  }
  FOR(i, 1, n) id[i] = a[i];
  sort(id + 1, id + n + 1);
  FOR(i, 1, n) a[i] = lower_bound(id + 1, id + n + 1, a[i]) - id;
  atcoder::fenwick_tree<int> fen(n + 1);
  FOR(i, 1, n) {
    ans += fen.sum(a[i] + 1, n + 1);
    fen.add(a[i], 1);
  }
  cout << ans << '\n';
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int T; cin >> T;
  while (T--) solve();
}