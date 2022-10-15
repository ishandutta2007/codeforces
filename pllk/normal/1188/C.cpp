#include <iostream>
#include <algorithm>

using namespace std;

#define M 998244353

typedef long long ll;

int n, k;
int a[1111];
ll d[1111];
ll s[1111], z[1111];
ll r;

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a+1,a+n+1);
    ll vh = 0;
    for (int u = 1; ; u++) {
        for (int i = 1; i <= n; i++) {
            d[i] = 1; s[i] = i;
        }
        for (int j = 2; j <= k; j++) {
            int f = 0;
            for (int i = 1; i <= n; i++) {
                while (a[i]-a[f+1] >= u) f++;
                d[i] = s[f];
                z[i] = (z[i-1]+d[i])%M;
            }
            for (int i = 1; i <= n; i++) s[i] = z[i];
        }
        ll h = 0;
        for (int i = 1; i <= n; i++) {h += d[i]; h %= M;}
        if (u != 1) {
            ll e = ((vh-h)%M+M)%M;
            r += e*(u-1);
            r %= M;
        }
        vh = h;
        if (u*(k-1) > 100000 || u > a[n]) break;
    }
    cout << r << "\n";
}