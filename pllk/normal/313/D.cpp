#include <iostream>

#define ll long long int

using namespace std;

int n, m, k;
int c[100000][3];

int pp[300][300];

ll dp[300][305];
char dv[300][305];

ll laske(int a, int b) {
    if (a == -1) {
        if (b == 0) return 0;
        else return -1;
    }
    if (b < 0) return -1;
    if (dv[a][b]) return dp[a][b];
    ll v = -1;
    for (int i = a; i >= 0; i--) {
        if (pp[i][a] == 0) continue;
        ll u = laske(i-1, b-(a-i+1));
        if (u == -1) continue;
        if (v == -1 || u+pp[i][a] < v) v = u+pp[i][a];
    }
    ll u = laske(a-1, b);
    if (v == -1 || (u != -1 && u < v)) v = u;
    dp[a][b] = v;
    dv[a][b] = 1;
    return v;
}

int main() {
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        cin >> c[i][0] >> c[i][1] >> c[i][2];
        c[i][0]--;
        c[i][1]--;
        for (int j = c[i][0]; j <= c[i][1]; j++) {
            if (pp[c[i][0]][j] == 0 || pp[c[i][0]][j] > c[i][2]) {
                pp[c[i][0]][j] = c[i][2];
            }
        }
    }
    ll v = -1;
    for (int i = k; i <= n; i++) {
        ll u = laske(n-1, i);
        if (v == -1 || (u != -1 && u < v)) v = u;
    }
    cout << v << endl;
}