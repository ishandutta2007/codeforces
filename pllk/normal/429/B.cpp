#include <iostream>
#include <algorithm>

using namespace std;

#define ll long long

int n, m;
ll a[1010][1010];

ll d[4][1010][1010];

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            d[0][i][j] = a[i][j]+max(d[0][i-1][j],d[0][i][j-1]);
        }
    }
    for (int i = n; i >= 1; i--) {
        for (int j = m; j >= 1; j--) {
            d[1][i][j] = a[i][j]+max(d[1][i+1][j], d[1][i][j+1]);
        }
    }
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= m; j++) {
            d[2][i][j] = a[i][j]+max(d[2][i+1][j],d[2][i][j-1]);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= 1; j--) {
            d[3][i][j] = a[i][j]+max(d[3][i-1][j],d[3][i][j+1]);
        }
    }
    ll t = 0;
    for (int i = 2; i <= n-1; i++) {
        for (int j = 2; j <= m-1; j++) {
            ll u1 = d[0][i][j-1]+d[1][i][j+1]+d[2][i+1][j]+d[3][i-1][j];
            ll u2 = d[0][i-1][j]+d[1][i+1][j]+d[2][i][j-1]+d[3][i][j+1];
            t = max(t, u1);
            t = max(t, u2);
        }
    }
    cout << t << endl;
}