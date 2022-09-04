#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 2e5 + 100, mod = 1e9 + 7;

ll n, k;

int main()
{
    #ifdef ONPC
    ifstream cin("a.in");
    ofstream cout("a.out");
    #endif // ONPC
    ios::sync_with_stdio(0);
    cin >> n >> k;
    k = (k + 1) / 2;
    for (int it = 0; it < k && n > 1; it++){
        ll x = n, m = n;
        for (ll i = 2; i <= sqrt(m); i++)
        if (m % i == 0){
            while (m % i == 0)
                m /= i;
            x -= x / i;
        }
        if (m > 1)
            x -= x / m;
        n = x;
    }
    cout << n % mod;
}