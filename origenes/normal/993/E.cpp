#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define all(x) (x).begin(), (x).end()
#define reset(x, y) memset(x, y, sizeof(x))
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define mp make_pair
#define _1 first
#define _2 second

namespace FFT {
    typedef complex<double> cd;
    const double PI = acos(-1);

    void fft(vector<cd> &a, bool inv = false) {
        int n = a.size();
        for (int i = 0, j = 0; i < n; i++) {
            if (j > i) swap(a[i], a[j]);
            int k = n;
            while (j & (k >>= 1)) j &= ~k;
            j |= k;
        }
        double pi = inv ? -PI : PI;
        for (int step = 1; step < n; step <<= 1) {
            double alpha = pi / step;
            REP(k, step) {
                cd omegak = exp(cd(0, alpha * k));
                for (int ek = k; ek < n; ek += step << 1) {
                    int ok = ek + step;
                    cd t = omegak * a[ok];
                    a[ok] = a[ek] - t;
                    a[ek] += t;
                }
            }
        }
        if (inv) REP(i, n) a[i] /= n;
    }

    vector<ll> operator*(const vector<ll> &v1, const vector<ll> &v2) {
        int s1 = v1.size(), s2 = v2.size(), s = 2;
        while (s < s1 + s2) s <<= 1;
        vector<cd> a(s, 0), b(s, 0);
        REP(i, s1) a[i] = v1[i];
        REP(i, s2) b[i] = v2[i];
        fft(a);
        fft(b);
        REP(i, s) a[i] *= b[i];
        fft(a, true);
        vector<ll> ans(s1 + s2 - 1);
        REP(i, s1 + s2 - 1) ans[i] = ll(round(a[i].real()));
        return ans;
    }
}

const int maxn = 212345;

int n, x;
int s[maxn];
map<int, int> mmap;

using namespace FFT;

int main() {
    scanf("%d%d", &n, &x);
    FOR(i, 1, n) {
        int now;
        scanf("%d", &now);
        s[i] = s[i - 1] + (now < x);
    }
    vector<ll> A(n + 1, 0), B(n + 1, 0);
    FOR(i, 1, n) A[s[i]]++;
    REP(i, n) B[n - s[i]]++;
    A = A * B;
    mmap[0]++;
    ll ans = 0;
    FOR(i, 1, n) {
        ans += mmap[s[i]];
        mmap[s[i]]++;
    }
    printf("%lld", ans);
    FOR(i, 1, n) printf(" %lld", A.size() > i + n ? A[i + n] : 0);
    return 0;
}