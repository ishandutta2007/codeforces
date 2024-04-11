#include "bits/stdc++.h"
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;
typedef long long ll;
typedef double dbl;
typedef pair <int, int> pii;
const ll MOD = 1e9 + 7;
const int MAXN = 1005;

int mpow(ll a, ll b) {
    if (b == 0) {
        return 1;
    }
    ll ret = mpow(a, b / 2);
    ret = (ret * ret) % MOD;
    if (b & 1) {
        ret = (ret * a) % MOD;
    }
    return ret;
}

ll factorial[MAXN];

ll rev(ll num) {
    return mpow(num, MOD - 2);
}

ll cnk(int n, int k) {
    return factorial[n] * rev(factorial[n - k]) % MOD * rev(factorial[k]) % MOD;
}

int k;
ll ans = 0;

int main() {    
    factorial[0] = 1;
    for (int i = 1; i < MAXN; ++i) {
        factorial[i] = factorial[i - 1] * i % MOD;
    }
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    cin >> k;
    int sum = 0;

    ans = 1;

    for (int i = 0; i < k; ++i) {
        int num;
        cin >> num;
        ans = (ans * cnk(sum + num - 1, num - 1)) % MOD;
        sum += num;
    }

    cout << ans << endl;

    return 0;
}