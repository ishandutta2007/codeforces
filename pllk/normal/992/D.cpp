#include <iostream>

using namespace std;

typedef long long ll;

ll n, k;
ll a[202020];
ll z[202020];
ll cc;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    z[n+1] = n+1;
    for (int i = n; i >= 1; i--) {
        if (a[i] == 1) z[i] = z[i+1];
        else z[i] = i;
    }
    for (int i = 1; i <= n; i++) {
        ll s = a[i];
        ll t = a[i];
        if (k == 1) cc++;
        for (int j = i+1; j <= n; j++) {
            if (a[j] != 1) {
                if (4e18/t < a[j]) break;
                t *= a[j];
                s += a[j];
                if (s*k == t) cc++;
            } else {
                int c = z[j]-j;
                if (s*k < t && t%k == 0 && (s+c)*k >= t) cc++;
                s += c;
                j += c-1;
            }
        }
    }
    cout << cc << "\n";
}