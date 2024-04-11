#include <bits/stdc++.h>
#define ll long long


using namespace std;

inline ll gcd(ll a, ll b) {
    ll r;
    while(b > 0) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}


int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    ll x, y;
    ios::sync_with_stdio(false);
    cin >> x >> y;
    ll ans = 0;
    while(y > 0) {
        if(x == y) {
            ans++;
            y = 0;
        }
        else {
            ll val = gcd(x, y);
            ll mn = (1LL << 62);
            ll aux = x;
            for(ll i = 2; i * i <= x; i++) {
                if(x % (i * val) == 0)
                    mn = min(mn, (y / val) % i);
                while(aux % i == 0)
                    aux /= i;
            }
            if(aux > 1 && x % (aux * val) == 0)
                mn = min(mn, (y / val) % aux);
            if(mn == (1LL << 62)) {
                ans += y / val;
                y = 0;
            }
            else {
               y -= val * mn;
               ans += mn;
            }
        }
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}