#include <iostream>

using namespace std;

typedef long long ll;

int m;

ll pot[404];
ll ncr[404][404];

int v[404][404];
ll d[404][404];

ll calc(int n, int k) {
    if (k == 0) return n == 0;
    if (v[n][k]) return d[n][k];
    ll u = 0;
    for (int h = 1; h <= n; h++) {
        u += ncr[n][h]*calc(n-h,k-1)%m*pot[h-1]%m;
        u %= m;
    }
    v[n][k] = 1;
    d[n][k] = u;
    return u;
}

int main() {
    int n;
    cin >> n >> m;
    pot[0] = 1;
    for (int i = 1; i <= 400; i++) pot[i] = pot[i-1]*2%m;
    ncr[0][0] = 1;
    for (int i = 1; i <= 400; i++) {
        ncr[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            ncr[i][j] = (ncr[i-1][j]+ncr[i-1][j-1])%m;
        }
    }
    ll u = 0;
    for (int k = 1; k <= (n+1)/2; k++) {
        u += calc(n-k+1,k);
        u %= m;
    }
    cout << u << "\n";
}