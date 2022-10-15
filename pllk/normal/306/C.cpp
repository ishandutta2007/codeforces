#include <iostream>

using namespace std;

#define ll long long int
#define M 1000000009

int m[5000][5000];
char v[5000][5000];

ll laske(int p, int t) {
    if (p == 0 && t == 0) return 1;
    if (p == 0 || t == 0) return 0;
    if (p > t) return 0;
    if (v[p][t]) return m[p][t];
    ll s = 0;
    s += t*laske(p-1,t-1);
    s %= M;
    s += t*laske(p,t-1);
    s %= M;
    v[p][t] = 1;
    m[p][t] = s;
    return s;
}

int main() {
    ll s = 0;
    int n, w, b;
    cin >> n >> w >> b;
    for (int i = 2; i <= n-1; i++) {
        for (int j = i; j <= n-1; j++) {
            ll u = 1;
            u *= laske(i-1+n-j,w);
            u %= M;
            u *= laske(j-i+1,b);
            u %= M;
            s += u;
            s %= M;
        }
    }
    cout << s << endl;
}