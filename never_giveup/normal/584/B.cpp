#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;

int main()
{
    //ifstream cin("a.in");
    //ofstream cout("a.out");
    ios::sync_with_stdio(0);
    ll n;
    cin >> n;
    ll a, b, all;
    a = 20, b = 0, all = 27;
    for (int i = 1; i < n; i++){
        ll x, y, z;
        x = (20 * all) % MOD;
        y = (7 * (a + b)) % MOD;
        z = (27 * all) % MOD;
        a = x;
        b = y;
        all = z;
    }
    cout << (a + b) % MOD;
}