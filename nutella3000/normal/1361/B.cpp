#include <bits/stdc++.h>
using namespace std;
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
 
#define int long long
#define pii pair<int, int>
#define sz(a) ((int)a.size())
typedef long double ld;

const int inf = 1e9 + 7;
const int max_n = 1e6 + 4, mod = 1e9 + 7;

int binpow(int a, int b) {
    int res = 1;
    for(;b; b /= 2, a = a * a % mod) if (b & 1) res = res * a % mod;
    return res;
}


signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int test;
    cin >> test;
    while(test--) {
        int n, p;
        cin >> n >> p;
        vector<int> k(n);
        for(int i = 0;i < n;i++) cin >> k[i];
        sort(k.begin(), k.end(), [](int v1, int v2) {return v1 > v2;});

        int res = 0;
        int cnt = 0;

        for(int i = 0;i < n;i++) {
            if (cnt != 0) {
                int num = k[i - 1] - k[i];
                if (p != 1) {
                    while(num--) {
                        if (cnt > n) break;
                        cnt = cnt * p;
                    }
                }
            }

            if (cnt != 0) {
                res -= binpow(p, k[i]);
                cnt--;
            }
            else {
                res += binpow(p, k[i]);
                cnt++;
            }

            res %= mod;
            //cout << cnt << " " << res << endl;
        }

        cout << (res + mod) % mod << endl;
    }
}