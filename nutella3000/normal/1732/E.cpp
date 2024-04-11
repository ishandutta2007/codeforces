#include<bits/stdc++.h>
using namespace std;
 
#define all(a) a.begin(), a.end()
using ll = long long;
using ull = unsigned long long;
using ld = long double;
 
template <typename T> bool chmin(T& a, T b) { if (a <= b) return false; a = b; return true; }
template <typename T> bool chmax(T& a, T b) { if (a >= b) return false; a = b; return true; }

const ll inf = 1e15;
const int N = 5e4 + 3, K = 120;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

ll get(int a, int b) {
    int g = gcd(a, b);
    return (ll) a / g * b / g;
}

void run() {
    int n, q; cin >> n >> q;
    vector<int> a(n), b(n), X(n / K + 1, -1);
    vector<ll> val(n), min_get(n / K + 1, inf);
    vector Xch(n / K + 1, vector<ll>(N, inf));

    for (auto& i : a)
        cin >> i;
    for (auto& i : b)
        cin >> i;

    for (int bl = 0; K*bl < n; ++bl) {
        for (int i = K*bl; i < min(n, K*(bl+1)); ++i) {
            val[i] = get(a[i], b[i]);
            chmin(min_get[bl], get(a[i], b[i]));

            for (int j = 1; j * j <= b[i]; ++j) {
                if (b[i] % j == 0) {
                    chmin(Xch[bl][j], (ll)b[i]);
                    chmin(Xch[bl][b[i] / j], (ll)b[i]);
                }
            }
        }
        for (int i = 1; i < N; ++i)
            if (Xch[bl][i] != inf) Xch[bl][i] /= i;

        for (int d = 1; d < N; ++d) {
            for (int g = 2; d * g < N; ++g) {
                chmin(Xch[bl][d*g], Xch[bl][d] * g);
            }
        }
    }

    while (q--) {
        int t, l, r, x; cin >> t >> l >> r; --l;
        int bll = l / K;
        int blr = r / K;

        if (t == 1) {
            cin >> x;

            auto set_block1 = [&](int bl) {
                if (X[bl] == -1) return;
                for (int i = bl * K; i < min((bl+1) * K, n); ++i)
                    a[i] = X[bl];
                X[bl] = -1;
            };
            auto set_block2 = [&](int bl) {
                min_get[bl] = inf;
                for (int i = bl * K; i < min((bl+1) * K, n); ++i) {
                    val[i] = get(a[i], b[i]);
                    chmin(min_get[bl], val[i]);
                }
            };

            set_block1(bll);
            set_block1(blr);

            for (int bor = K * (bll+1); l < min(r, bor);)
                a[l++] = x;
            for (int bor = K*blr; r > max(l, bor);)
                a[--r] = x;

            set_block2(bll);
            set_block2(blr);

            for (++bll; bll < blr;)
                X[bll++] = x;

        } else {
            ll res = inf;

            for (int bor = K * (bll+1); l < min(r, bor); ++l)
                chmin(res, X[bll] == -1 ? val[l] : get(X[bll], b[l]));

            for (int bor = K * blr; r > max(l, bor);) {
                --r; chmin(res, X[blr] == -1 ? val[r] : get(X[blr], b[r]));
            }

            for (++bll; bll < blr; ++bll)
                chmin(res, X[bll] == -1 ? min_get[bll] : Xch[bll][X[bll]]);

            cout << res << '\n';
        }

    }
}

signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int t = 1;
    //cin >> t;
    while (t--) {
        run();
    }
}