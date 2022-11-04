#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const ll INF = 2e18;
const int MAXN = (int) 5e5 + 5;

int v[MAXN + 1], n, r;
ll sp[MAXN + 1], aux[MAXN + 1];

inline ll check(ll val) {
    int i;
    ll bonus;
    memset(sp, 0, sizeof(sp));
    ll ans = 0;
    for(i = 1; i <= n; i++) {
        sp[i] += sp[i - 1];
        if(sp[i] + aux[i] < val) {
            bonus = val - aux[i] - sp[i];
            int pos = min(i + 2 * r + 1, n + 1);
            sp[pos] -= bonus;
            sp[i] += bonus;
            ans += bonus;
            if(ans > INF)
                return INF;
        }
    }
    return ans;
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i;
    ll k;
    ios::sync_with_stdio(false);
    cin >> n >> r >> k;
    for(i = 1; i <= n; i++) {
        cin >> v[i];
    }
    for(i = 1; i <= n; i++) {
        aux[max(1, i - r)] += v[i];
        aux[min(n + 1, i + r + 1)] -= v[i];
    }
    for(i = 1; i <= n; i++) {
        aux[i] += aux[i - 1];
    }
    ll res = 0;
    for(ll step = 1LL << 60; step; step >>= 1) {
        if(check(res + step) <= k)
            res += step;
    }
    cout << res;
    //cin.close();
    //cout.close();
    return 0;
}