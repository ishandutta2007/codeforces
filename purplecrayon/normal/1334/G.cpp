#include "bits/stdc++.h"
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7, MAXL = 34;
const int INF = 1e9+10;
const ll INFLL = 1e18+10;

// make it understandable one day...
namespace fft {
    typedef float dbl;

    struct num {
      dbl x, y;
      num() { x = y = 0; }
      num(dbl x_, dbl y_) : x(x_), y(y_) {}
    };

    inline num operator+(num a, num b) { return num(a.x + b.x, a.y + b.y); }
    inline num operator-(num a, num b) { return num(a.x - b.x, a.y - b.y); }
    inline num operator*(num a, num b) { return num(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x); }
    inline num conj(num a) { return num(a.x, -a.y); }

    int base = 1;
    vector<num> roots = {{0, 0}, {1, 0}};
    vector<int> rev = {0, 1};

    const dbl PI = static_cast<dbl>(acosl(-1.0));

    void ensure_base(int nbase) {
          if (nbase <= base) {
            return;
          }
          rev.resize(1 << nbase);
          for (int i = 0; i < (1 << nbase); i++) {
            rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (nbase - 1));
          }
          roots.resize(1 << nbase);
          while (base < nbase) {
            dbl angle = 2 * PI / (1 << (base + 1));
        //      num z(cos(angle), sin(angle));
            for (int i = 1 << (base - 1); i < (1 << base); i++) {
              roots[i << 1] = roots[i];
        //        roots[(i << 1) + 1] = roots[i] * z;
              dbl angle_i = angle * (2 * i + 1 - (1 << base));
              roots[(i << 1) + 1] = num(cos(angle_i), sin(angle_i));
            }
            base++;
          }
    }
    void fft(vector<num>& a, int n = -1) {
          if (n == -1) {
            n = (int) a.size();
          }
          assert((n & (n - 1)) == 0);
          int zeros = __builtin_ctz(n);
          ensure_base(zeros);
          int shift = base - zeros;
          for (int i = 0; i < n; i++) {
            if (i < (rev[i] >> shift)) {
              swap(a[i], a[rev[i] >> shift]);
            }
          }
          for (int k = 1; k < n; k <<= 1) {
            for (int i = 0; i < n; i += 2 * k) {
              for (int j = 0; j < k; j++) {
                num z = a[i + j + k] * roots[j + k];
                a[i + j + k] = a[i + j] - z;
                a[i + j] = a[i + j] + z;
              }
            }
          }
    }
    vector<num> fa, fb;
    vector<int64_t> square(const vector<int>& a) {
          if (a.empty()) {
            return {};
          }
          int need = (int) a.size() + (int) a.size() - 1;
          int nbase = 1;
          while ((1 << nbase) < need) nbase++;
          ensure_base(nbase);
          int sz = 1 << nbase;
          if ((sz >> 1) > (int) fa.size()) {
            fa.resize(sz >> 1);
          }
          for (int i = 0; i < (sz >> 1); i++) {
            int x = (2 * i < (int) a.size() ? a[2 * i] : 0);
            int y = (2 * i + 1 < (int) a.size() ? a[2 * i + 1] : 0);
            fa[i] = num(x, y);
          }
          fft(fa, sz >> 1);
          num r(1.0 / (sz >> 1), 0.0);
          for (int i = 0; i <= (sz >> 2); i++) {
            int j = ((sz >> 1) - i) & ((sz >> 1) - 1);
            num fe = (fa[i] + conj(fa[j])) * num(0.5, 0);
            num fo = (fa[i] - conj(fa[j])) * num(0, -0.5);
            num aux = fe * fe + fo * fo * roots[(sz >> 1) + i] * roots[(sz >> 1) + i];
            num tmp = fe * fo;
            fa[i] = r * (conj(aux) + num(0, 2) * conj(tmp));
            fa[j] = r * (aux + num(0, 2) * tmp);
          }
          fft(fa, sz >> 1);
          vector<int64_t> res(need);
          for (int i = 0; i < need; i++) {
            res[i] = llround(i % 2 == 0 ? fa[i >> 1].x : fa[i >> 1].y);
          }
          return res;
    }
    vector<int64_t> multiply(const vector<int>& a, const vector<int>& b) {
          if (a.empty() || b.empty()) {
            return {};
          }
          if (a == b) {
            return square(a);
          }
          int need = (int) a.size() + (int) b.size() - 1;
          int nbase = 1;
          while ((1 << nbase) < need) nbase++;
          ensure_base(nbase);
          int sz = 1 << nbase;
          if (sz > (int) fa.size()) {
            fa.resize(sz);
          }
          for (int i = 0; i < sz; i++) {
            int x = (i < (int) a.size() ? a[i] : 0);
            int y = (i < (int) b.size() ? b[i] : 0);
            fa[i] = num(x, y);
          }
          fft(fa, sz);
          num r(0, -0.25 / (sz >> 1));
          for (int i = 0; i <= (sz >> 1); i++) {
            int j = (sz - i) & (sz - 1);
            num z = (fa[j] * fa[j] - conj(fa[i] * fa[i])) * r;
            fa[j] = (fa[i] * fa[i] - conj(fa[j] * fa[j])) * r;
            fa[i] = z;
          }
          for (int i = 0; i < (sz >> 1); i++) {
            num A0 = (fa[i] + fa[i + (sz >> 1)]) * num(0.5, 0);
            num A1 = (fa[i] - fa[i + (sz >> 1)]) * num(0.5, 0) * roots[(sz >> 1) + i];
            fa[i] = A0 + A1 * num(0, 1);
          }
          fft(fa, sz >> 1);
          vector<int64_t> res(need);
          for (int i = 0; i < need; i++) {
            res[i] = llround(i % 2 == 0 ? fa[i >> 1].x : fa[i >> 1].y);
          }
          return res;
    }
}  // namespace fft

/*
    int n, m; cin >> n >> m;
    vector<int> a(n), b(m);
    for (auto& it : a) cin >> it;
    for (auto& it : b) cin >> it;
    reverse(b.begin(), b.end());
 
    //i+(-j) = k
    //i+n-1-j = k+n
    auto ans = fft::multiply(a, b);
    for (int i = 0; i < n+m-1; i++) cout << ans[i] << ' ';
    cout << '\n';
*/

vector<int> get(vector<int>& a, vector<int>& b) {
    int n = sz(a), m = sz(b);
    reverse(b.begin(), b.end());
    auto ans = fft::multiply(a, b);
    vector<int> res(n-m+1);
    for (int i = m-1; i < n; i++) {
        res[i-(m-1)] = ans[i];
    }
    return res;
}
int p[26];
void solve(){
    for (int i = 0; i < 26; i++) cin >> p[i], --p[i];
    string s, t; cin >> s >> t;
    int n = sz(t), m = sz(s);

    vector<int> a(n), b(m);
    vector<bool> ans(n-m+1, 1);
    for (int c = 0; c < 26; c++) {
        int tot = 0;
        for (int i = 0; i < m; i++) b[i] = s[i] == c+'a', tot += b[i];
        for (int i = 0; i < n; i++) a[i] = t[i] == c+'a' || t[i] == p[c]+'a';

        auto cur = get(a, b);
        for (int i = 0; i < n-m+1; i++) ans[i] = ans[i] && (cur[i] == tot);
    }
    for (auto c : ans) cout << c;
    cout << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}