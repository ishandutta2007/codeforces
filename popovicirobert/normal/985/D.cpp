#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 220
// 44

using namespace std;



int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    //int ;
    ll n, h;
    ios::sync_with_stdio(false);
    cin >> n >> h;
    ll res = 0;
    for(ll step = 1LL << 31; step; step >>= 1) {
        ll k = res + step;
        ll h1 = min(k, h);
        if(k * k - h1 * (h1 - 1) / 2 <= n)
            res += step;
    }
    ll k = res;
    ll h1 = min(k, h);
    n -= (k * k - h1 * (h1 - 1) / 2);
    cout << 2 * k - 1 - (h1 - 1) + (n + k - 1) / k;
    //cin.close();
    //cout.close();
    return 0;
}