#include <iostream>

using namespace std;

typedef long long ll;

#define M 1000000007

int n, m;
string s;
int d[4040][4040];
int v[4040][4040];

int laske(int a, int b) {
    if (a == 0) return b == 0;
    if (v[a][b]) return d[a][b];
    ll s = 0;
    s += laske(a-1,b+1);
    if (b > 0) s += laske(a-1,b-1);
    s %= M;
    v[a][b] = 1;
    d[a][b] = s;
    return s;
}

int main() {
    cin >> n >> m;
    cin >> s;
    int c = 0, p = 0;
    for (int i = 0; i < m; i++) {
        if (s[i] == '(') c++;
        else c--;
        p = min(p,c);
    }
    ll t = 0;
    for (int a = 0; a <= n-m; a++) {
        for (int b = 0; b <= a; b++) {
            if (b < -p) continue;
            ll x = laske(a,b);
            ll y = laske(n-m-a,b+c);
            t += x*y;
            t %= M;
        }
    }
    cout << t << "\n";
}