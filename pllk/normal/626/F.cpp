#include <iostream>
#include <algorithm>

using namespace std;

#define M 1000000007

typedef long long ll;

int n, k;
int a[555];
int d[201][101][1001];

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a+1,a+n+1);
    d[0][0][0] = 1;
    for (int i = 1; i <= n; i++) {
        int e = a[i]-a[i-1];
        for (int j = 0; j <= n/2; j++) {
            for (int h = 0; h <= k; h++) {
                int u = h+e*j;
                if (u > k) continue;
                if (j+1 <= n/2) {
                    d[i][j+1][u] += d[i-1][j][h];
                    d[i][j+1][u] %= M;
                }
                d[i][j][u] += ((ll)(j+1)*d[i-1][j][h])%M;
                d[i][j][u] %= M;
                if (j-1 >= 0) {
                    d[i][j-1][u] += ((ll)j*d[i-1][j][h])%M;
                    d[i][j-1][u] %= M;
                }
            }
        }
    }
    ll t = 0;
    for (int h = 0; h <= k; h++) {
        t += d[n][0][h];
        t %= M;
    }
    cout << t << "\n";
}