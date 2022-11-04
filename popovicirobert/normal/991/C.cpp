#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

inline bool check(ll x, ll n) {
    ll s = 0;
    ll aux = n;
    while(aux > 0) {
        s += min(aux, x);
        aux -= min(aux, x);
        aux -= aux / 10;
    }
    return s >= (n + 1) / 2;
}

int main() {
    //ifstream cin("B.in");
    //ofstream cout("B.out");
    ll n;
    ios::sync_with_stdio(false);
    cin >> n;
    ll res = 0;
    for(ll step = 1LL << 60; step; step >>= 1) {
        if(check(res + step, n) == 0) {
            res += step;
        }
    }
    cout << res + 1;
    //cin.close();
    //cout.close();
    return 0;
}