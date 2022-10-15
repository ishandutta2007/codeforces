#include <iostream>

using namespace std;

#define ll long long

int n, m, M;

int c[555];
ll d[555][555];
bool v[555][555];

ll x(int a, int b) {
    if (a < 0 || b < 0) return 0;
    if (a == 0 && b == 0) return 1;
    if (v[a][b]) return d[a][b];
    ll t1 = (a*(a-1)*x(a-2,b+2)/2)%M;
    ll t2 = (b*(b-1)*x(a,b-2)/2)%M;
    ll t3 = (a*b*x(a-1,b))%M;
    d[a][b] = (t1+t2+t3)%M;
    v[a][b] = 1;
    return d[a][b];
}

int main() {
    cin >> n >> m >> M;
    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) {
            if (s[j] == '1') c[j]++;
        }
    }
    int a1 = 0, a2 = 0;
    for (int i = 0; i < n; i++) {
        if (c[i] == 0) a2++;
        if (c[i] == 1) a1++;
    }
    cout << x(a2,a1) << "\n";
}