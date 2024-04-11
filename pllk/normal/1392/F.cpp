#include <iostream>

using namespace std;

typedef long long ll;

ll n;
ll r[1222333];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    ll s = 0;
    for (int i = 1; i <= n; i++) {
        ll x;
        cin >> x;
        s += x;
    }
    s -= (n*(n+1)/2);
    ll b = s/n;
    s -= b*n;
    for (int i = 1; i <= n; i++) r[i] = i+b;
    for (int i = 1; i <= s; i++) r[i]++;
    for (int i = 1; i <= n; i++) cout << r[i] << " ";
    cout << "\n";
}