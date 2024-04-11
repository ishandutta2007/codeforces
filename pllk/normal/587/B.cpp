#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

#define ll long long
#define M 1000000007

int n, k;
ll l;
int a[1010101];
vector<int> v;
unordered_map<int,int> z;

ll d[1010101];
ll s[1010101];

ll w;

ll pot(ll n, int k) {
    if (k == 0) return 1;
    if (k%2 == 0) {
        ll u = pot(n,k/2);
        return (u*u)%M;
    } else {
        return (pot(n,k-1)*n)%M;
    }
}

ll inv(ll x) {
    return pot(x,M-2);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> l >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        v.push_back(a[i]);
    }
    sort(v.begin(), v.end());
    int c = 0;
    for (int i = 0; i < n; i++) {
        if (i == n-1 || v[i] != v[i+1]) {
            c++;
            z[v[i]] = c;
        }
    }
    ll x = l%n;
    ll e1 = l/n;
    ll e2 = l/n+1;
    e1 %= M;
    e2 %= M;
    int cc = 0;
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= c; j++) {
            d[j] = 0;
        }
        for (int j = 0; j < n; j++) {
            cc++;
            if (cc > l) goto lol;
            ll u = s[z[a[j]]];
            if (i == 1) u = 1;
            d[z[a[j]]] += u;
            d[z[a[j]]] %= M;
            if (j < x) w += u*e2;
            else w += u*e1;
            w %= M;
        }
        for (int j = 1; j <= c; j++) {
            s[j] = s[j-1]+d[j];
            s[j] %= M;
        }
        e1--;
        if (e1 < 0) e1 += M;
        e2--;
        if (e2 < 0) e2 += M;
    }
    lol:
    cout << w << "\n";
}