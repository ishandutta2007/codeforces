#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

/*inline void mod(int &x) {
    if(x >= MOD)
        x -= MOD;
}

inline void add(int &x, int y) {
    x += y;
    mod(x);
}

inline void mul(int &x, int y) {
    x = (1LL * x * y) % MOD;
}*/

using namespace std;


const ll INF = 1e18;

ll mn = INF, mx = 0;

inline ll gcd(ll a, ll b) {
    ll r;
    while(b > 0) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

inline void get(ll a, ll b) {

    ll cur = b / gcd(a, b);
    mn = min(mn, cur);
    mx = max(mx, cur);
}


int main() {
    //ifstream cin("B.in");
    //ofstream cout("B.out");
    int i, n, k, a, b;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> k >> a >> b;

    if(a > b) {
        swap(a, b);
    }

    ll x = 1 + a;
    for(i = 1; i <= (n + 1); i++) {
        ll y = 1LL * (i - 1) * k + 1 + b;
        get(y - x, 1LL * n * k);

        y = 1LL * i * k + 1 - b;
        get(y - x, 1LL * n * k);
    }

    cout << mn << " " << mx;

    //cin.close();
    //cout.close();
    return 0;
}