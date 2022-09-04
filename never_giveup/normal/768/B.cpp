#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 2e5 + 100;

ll fun(ll x){
    if (x < 2)
        return 1;
    return fun(x / 2) * 2 + 1;
}

ll go(ll n, ll l, ll r, ll len){
    if (l > r)
        return 0;
    if (n < 2)
        return n;
    if (r - l + 1 == len){
        ll ret = 0, pw = 1;
        while (n > 0)
            ret += pw * (n % 2), pw *= 2, n /= 2;
        return ret;
    }
    if (r < len / 2)
        return go(n / 2, l, r, len / 2);
    if (l > len / 2)
        return go(n / 2, l - len / 2 - 1, r - len / 2 - 1, len / 2);
    return n % 2 + go(n / 2, l, len / 2 - 1, len / 2) + go(n / 2, 0, r - len / 2 - 1, len / 2);
}

int main(){
    #ifdef ONPC
    ifstream cin("a.in");
    ofstream cout("a.out");
    #endif // ONPC
    ios::sync_with_stdio(0);
    ll n;
    cin >> n;
    ll l, r;
    cin >> l >> r;
    cout << go(n, l - 1, r - 1, fun(n));
}