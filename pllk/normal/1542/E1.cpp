#include <iostream>

using namespace std;

typedef long long ll;

ll d[55][2555];

int main() {
    int n, m;
    cin >> n >> m;
    d[1][0] = 1;
    for (int i = 2; i <= n; i++) {
        for (int e = 0; e <= (i-1)*(i-2)/2; e++) {
            for (int f = 0; f <= i-1; f++) {
                d[i][e+f] += d[i-1][e];
                d[i][e+f] %= m;
            }
        }
    }
    ll r = 0;
    ll f = 1;
    for (int i = 0; i <= n-2; i++) {
        int k = n-i;
        ll c[50*50] = {0};
        for (int x = 0; x < k*k; x++) {
            for (int y = 0; y < x; y++) {
                c[x-y] += d[k-1][x]*d[k-1][y];
                c[x-y] %= m;
            }
        }
        ll u = 0;
        for (int a = 1; a <= k; a++) {
            for (int b = a+1; b <= k; b++) {
                for (int i = b-a+1; i < k*k; i++) {
                    u = (u+c[i])%m;
                }
            }
        }
        r = (r+u*f)%m;
        f = f*(n-i)%m;
    }
    cout << r << "\n";
}