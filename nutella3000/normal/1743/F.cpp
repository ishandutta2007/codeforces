#include<bits/stdc++.h>
using namespace std;
 
#define all(a) a.begin(), a.end()
using ll = long long;
using ull = unsigned long long;
using ld = long double;
 
template <typename T> bool chmin(T& a, T b) { if (a <= b) return false; a = b; return true; }
template <typename T> bool chmax(T& a, T b) { if (a >= b) return false; a = b; return true; }

const ll inf = 1e18;
const ll mod = 998244353;


void run() {
    int n; cin >> n;
    vector<int> L(n), R(n);
    for (int i = 0; i < n; ++i) {
        cin >> L[i] >> R[i];
    }
    ll res = 0;
    vector<ll> pw2(n+1); pw2[0] = 1;
    vector<ll> pw3(n+1); pw3[0] = 1;
    for (int i = 1; i <= n; ++i) {
        pw2[i] = pw2[i-1] * 2 % mod;
        pw3[i] = pw3[i-1] * 3 % mod;
    }

    set<pair<int, int>> seg{{0, 3e6}};
    set<pair<int, int>> nseg;

    for (int i = n-1; i >= 0; --i) {
        int l = L[i], r = R[i];

        auto it = seg.lower_bound({l, l});
        if (it != seg.begin()) --it;

        for (; it != seg.end() && it->first <= r;) {
            auto& [a, b] = *it;

            if (min(r, b) - max(l, a) >= 0)
                res += pw2[n-max(i, 1)] * pw3[max(i, 1)-1] % mod * (min(r, b) - max(l, a) + 1) % mod;    

            if (min(l-1, b) >= a)
                nseg.emplace(a, min(l-1, b));

            if (b >= max(a, r + 1))
                nseg.emplace(max(a, r+1), b);

            it = seg.erase(it);
        }
        for (auto [a, b] : nseg)
            seg.emplace(a, b);
        nseg.clear();
        /*for (auto i : seg)
            cout << i.first << " " << i.second << '\n';
        cout << '\n';*/
    }

    cout << res % mod << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        run();
    }
}