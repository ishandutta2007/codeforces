#include <iostream>
#include <map>

using namespace std;

typedef long long ll;
#define M 1000000007

int n, b, k, x;
int c[1111];

ll pot(int a, int b) {
    if (b == 0) return 1;
    if (b%2 == 0) {
        ll u = pot(a,b/2);
        return (u*u)%x;
    } else {
        ll u = pot(a,b-1);
        return (u*a)%x;
    }
}

map<int,map<int,int>> d, v;

ll laske(int n, int m) {
    if (v[n][m]) return d[n][m];
    if (n == 0) return m == 0;
    ll v1[111] = {0};
    ll v2[111] = {0};
    if (n%2 == 0) {
        for (int i = 0; i < x; i++) {
            int u = (i*pot(10,n/2))%x;
            v1[u] += laske(n/2,i);
            v1[u] %= M;
            v2[i] += laske(n/2,i);
            v2[i] %= M;
        }
    } else {
        for (int i = 0; i < x; i++) {
            int u = (10*i)%x;
            v1[u] += laske(n-1,i);
            v1[u] %= M;
            v2[i] += c[i];
            v2[i] %= M;
        }
    }
    ll r = 0;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < x; j++) {
            if ((i+j)%x == m) r += v1[i]*v2[j];
            r %= M;
        }
    }
    v[n][m] = 1;
    d[n][m] = r;
    return r;
}

int main() {
    cin >> n >> b >> k >> x;
    for (int i = 0; i < n; i++) {
        int u;
        cin >> u;
        c[u%x]++;
    }
    cout << laske(b,k) << "\n";
}