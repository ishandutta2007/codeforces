#include <iostream>

using namespace std;

typedef long long ll;

ll n;
int c[10];

ll cur[100], pre[100];

ll ncr[100][100];

ll calc(int a, int b) {
    return ncr[a+b-1][b];
}

int main() {
    ncr[0][0] = 1;
    for (int i = 1; i < 100; i++) {
        ncr[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            ncr[i][j] = ncr[i-1][j]+ncr[i-1][j-1];
        }
    }
    cin >> n;
    while (n > 0) {
        c[n%10]++;
        n /= 10;
    }
    pre[0] = 1;
    for (int u = 9; u >= 0; u--) {
        if (c[u] == 0) continue;
        for (int a = 0; a < 100; a++) cur[a] = 0;
        for (int k = 1; k <= c[u]; k++) {
            for (int a = 0; a < 100; a++) {
                cur[a+k] += pre[a]*calc(a+1-(u==0),k);
            }
        }
        for (int a = 0; a < 100; a++) pre[a] = cur[a];
    }
    ll total = 0;
    for (int a = 0; a < 100; a++) total += pre[a];
    cout << total << "\n";
}