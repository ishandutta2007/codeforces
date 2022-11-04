#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const ll INF = 1e18;

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i;
    ll n, k, m, d;
    ios::sync_with_stdio(false);
    cin >> n >> k >> m >> d;
    ll ans = m;
    for(i = 1; i < d; i++) {
        ll res = 0;
        for(ll step = 1LL << 60; step; step >>= 1) {
            if(INF / i < k || INF / (i * k) < res + step)
                continue;
            if((res + step) * (i * k) + res + step <= n)
                res += step;
        }
        res = min(res, m);
        ans = max(ans, i * res + res);
        if(INF / i >= k)
            ans = max(ans, i * min(m, (n / (i * k))));
    }
    if(INF / k >= d)
        ans = max(ans, d * min(m, (n / (k * d))));
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}