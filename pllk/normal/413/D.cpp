#include <iostream>

using namespace std;

#define ll long long
#define M 1000000007

int n, k;
ll d[2020][2100];

int muuta(int v, int x) {
    for (int i = 0; i < x; i++) {
        if (v&(1<<i)) return 1<<x;
    }
    while (v&(1<<x)) {
        v ^= (1<<x);
        x++;
    }
    v |= (1<<x);
    return v;
}

int main() {
    cin >> n >> k;
    d[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (x == 2 || x == 0) d[i][1<<k] += d[i-1][1<<k];
        if (x == 4 || x == 0) d[i][1<<k] += d[i-1][1<<k];
        for (int j = 0; j < (1<<k); j++) {
            d[i][1<<k] %= M;
            if (x == 2 || x == 0) {
                int u = muuta(j, 1);
                if (u >= (1<<k)) u = 1<<k;
                d[i][u] += d[i-1][j];
                d[i][u] %= M;
            }
            if (x == 4 || x == 0) {
                int u = muuta(j, 2);
                if (u >= (1<<k)) u = 1<<k;
                d[i][u] += d[i-1][j];
                d[i][u] %= M;
            }
        }
    }
    cout << d[n][1<<k] << endl;
}