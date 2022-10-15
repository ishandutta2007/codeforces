#include <iostream>

using namespace std;

#define ll long long
#define M 1000000007

int ncr[4040][4040];

int d[4040][2];
int v[4040][2];
int n;

ll laske(int k, int c) {
    if (k == 0) return 1-c;
    if (v[k][c]) return d[k][c];
    ll s = 0;
    for (int r = 1; r <= k; r++) {
        s += laske(k-r,c)*ncr[k-1][r-1];
        s %= M;
    }
    s += laske(k-1,0);
    s %= M;
    v[k][c] = 1;
    d[k][c] = s;
    return s;
}

int main() {
    cin >> n;
    for (int i = 0; i <= n; i++) ncr[i][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            ncr[i][j] = ncr[i-1][j]+ncr[i-1][j-1];
            ncr[i][j] %= M;
        }
    }
    cout << laske(n,1) << "\n";
}