#include "bits/stdc++.h"
#define puba push_back
#define ff first
#define ss second
#define bend(_x) begin(_x), end(_x)
#define szof(_x) ((int) (_x).size())
#define TASK_NAME ""

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9 + 7;
const ll INFL = 1e18 + 123;
const double PI = atan2(0, -1);
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 5;

vector<ll> fact = {1};

ll mpow(ll a, ll b) {
    if (!b) {
        return 1;
    }
    ll tmp = mpow(a, b / 2);
    tmp = tmp * tmp % MOD;
    if (b & 1) {
        tmp = tmp * a % MOD;
    }
    return tmp;
}

ll inv(ll num) {
    return mpow(num, MOD - 2);
}

ll cnk(int n, int k) {
    return fact[n] * inv(fact[n - k]) % MOD * inv(fact[k]) % MOD;
}

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);
    cerr << fixed << setprecision(15);
    cout << fixed << setprecision(15);
    
    /*
    for (int n = 1; n < 15; ++n) {
        for (int i = 0; i < n; ++i) {
            vector<int> now(n);
            now[i] = 1;
            int sign = 0;
            for (int j = 0; j < n - 1; ++j) {
                vector<int> cur;
                for (int k = 0; k < szof(now) - 1; ++k) {
                    cur.puba((now[k] + now[k + 1] * (sign ? -1 : 1)) % MOD);
                    sign ^= 1;
                }
                now = cur;
            }

            cout << now[0] << " ";
        }
        cout << "\n";
    }*/                              

    ll ans = 0;
    
    for (int i = 1; i < MAXN; ++i) {
        fact.puba((fact.back() * i) % MOD);
    }

    int n;
    vector<int> inp;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int num;
        scanf("%d", &num);
        inp.puba(num);
    }

    if (n == 1) {
        cout << inp[0] << "\n";
        return 0;
    }

    int tmp = n;
    if (n % 2 == 1) {
        tmp -= 1;
    }
    vector<ll> res;
    
    for (int i = 0; i < tmp; ++i) {
        res.puba(cnk(tmp / 2 - 1, i / 2));
    }

    if (tmp % 4 == 0) {
        for (int i = 1; i < tmp; i += 2) {
            res[i] *= -1;
        }
    }
    
    /*
    for (int num : res) {
        cerr << num << " ";
    }
    cerr << endl;
    */
    if (n % 2 == 1) {
        vector<ll> newr = {res[0]};
        int sign = 0;
        for (int i = 1; i < szof(res); ++i) {
            newr.puba((res[i] + res[i - 1] * (sign ? -1 : 1)) % MOD);
            sign ^= 1;
        }
        newr.puba(res.back() * (sign ? -1 : 1));
        res = newr;
    }

    /*
    for (int num : res) {
        cerr << num << " ";
    }
    cerr << endl;
    */
    for (int i = 0; i < n; ++i) {
        ans = (ans + inp[i] * res[i]) % MOD;
    }

    if (ans < 0) {
        ans += MOD;
    }

    cout << ans << "\n";

    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}