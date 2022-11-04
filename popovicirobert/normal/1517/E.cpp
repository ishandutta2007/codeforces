#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define Test(tt) cout << "Case #" << tt << ": "
 
 
using namespace std;

constexpr int MOD = 998244353;


int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n + 1);
        vector<ll> sp(n + 1), sp2(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            sp[i] = sp[i - 1] + a[i];
            if (i > 1) {
                sp2[i] = sp2[i - 2] + a[i];
            }
        }

        if (n == 1) {
            cout << 1 << "\n";
            continue;
        }
        if (n == 2) {
            cout << 2 << "\n";
            continue;
        }
        if (n == 3) {
            int ans = 0;
            for (int mask = 0; mask < (1 << n); mask++) {
                ll sum = 0;
                for (int i = 0; i < n; i++) {
                    if (mask & (1 << i)) {
                        sum += a[i + 1];
                    }
                }
                if (sum < (sp[n] + 1) / 2) {
                    ans++;
                }
            }
            cout << ans << "\n";
            continue;
        }

        const ll half = (sp[n] + 1) / 2;
        int ans = 0;

        // PPPPPCCCCCC
        for (int i = 3; i <= n - 1; i++) {
            if (sp[n] - sp[i - 1] < half) {
                ans++;
            }
        }

        for (int beg = 0; beg < 2; beg++) {
            for (int end = 0; end < 2; end++) {
                int l = beg + 1;
                int r = n - end;

                for (int pref = 2 * beg; pref + l - 1 <= r; pref++) {
                    ll sum = (end == 1 ? a[n] : 0) + sp[pref + l - 1] - sp[l - 1];
                    if (sum >= half) {
                        break;
                    }

                    int pos = pref + l - 1;
                    if (end && pos == r) {
                        continue;
                    }

                    int res = pos;
                    for (int step = 1 << 18; step > 1; step >>= 1) {
                        if (res + step <= r && sp2[res + step] - sp2[pos] + sum < half) {
                            res += step;
                        }
                    }

                    ans += (res - pos) / 2 + 1;

                    if (r == res && end && (res > pos + 2 || pref > 1 || (pref == 1 && res > pos))) {
                        ans = (ans + MOD - 1) % MOD;
                    }
                    if (r == res + 1 && end) {
                        ans = (ans + MOD - 1) % MOD;
                    }

                    ans %= MOD;

                    // if (t == 1)
                    //    cerr << ans << " " << beg << " " << end << " " << pref << " " << (res - pos) / 2 << "\n";
                }
            }
        }

        /*
            PPPP - 1
            PCPP - 1
            PCCP - 3
            PPPC - 2
            PCPC - 1
            PPCC - 0
            PCCC - 4
        */

        /*
            PPPPP - 1
            CPPPP - 2
            PCPPP - 1
            CCPPP - 2
            PCCPP
            PCPCP - 1
            PPPPC - 3
            CPPPC
            PCPPC - 3
            PPPCC - 0
        */

        cout << ans << "\n";
    }
    
    return 0;
}