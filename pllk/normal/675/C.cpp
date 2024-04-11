#include <iostream>
#include <map>

using namespace std;

typedef long long ll;

int n;
int t[202020];
ll s[202020];
map<ll,int> v;
int d[202020];
int cc = 999999999;
int r[202020];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> t[i];
        t[i+n] = t[i];
    }
    ll u = 0;
    int x = n+1, k;
    for (int i = 1; i <= 2*n; i++) {
        u += t[i];
        s[i] = u;
        d[i] = v[u];
        v[u] = i;
    }
    for (int i = n+1; i <= 2*n; i++) {
        int k = i;
        int c1 = 0, c2 = 0;
        bool ok = false;
        while (true) {
            if (r[k]) break;
            r[k] = 1;
            c1 += (k-d[k])-1;
            c2 += (k-d[k]);
            k = d[k];
            if (c2 == n) {
                ok = true;
                break;
            }
        }
        if (ok) cc = min(cc,c1);
    }
    cout << cc << "\n";
}