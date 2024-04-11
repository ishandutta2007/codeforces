#include <iostream>
#include <set>

using namespace std;
using ll = long long;
const int M = 998244353;

int n;
set<pair<int,int>> ts;
int x[202020], y[202020], s[202020];
int f[202020];

ll d[202020];
ll z[202020];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i] >> s[i];
        ts.insert({x[i],i});
    }
    for (int i = 1; i <= n; i++) {
        f[i] = ts.upper_bound({y[i],0})->second;
    }

    ll r = 0;

    for (int i = 1; i <= n; i++) {
        d[i] = x[i] - y[i];
        d[i] += z[i-1] - z[f[i]-1];
        d[i] = (d[i] % M + M) % M;
        z[i] = (z[i-1] + d[i]) % M;

        r += x[i] - x[i-1];
        if (s[i]) r += d[i];
        r %= M;
    }

    r = (r+1)%M;
    cout << r << "\n";
}