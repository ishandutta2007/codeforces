#include <iostream>

using namespace std;

int n, m;
int r1[111][111];
int r2[111][111];
int dd[111][111];
int dv[111][111];

int calc(int a, int b) {
    if (a > b) return 0;
    if (dv[a][b]) return dd[a][b];
    int u = 0;
    for (int i = a; i <= b; i++) {
        int c = 0;
        for (int j = 1; j <= n; j++) {
            if (r1[j][i] >= a && r2[j][i] <= b) c++;
        }
        u = max(u,calc(a,i-1)+calc(i+1,b)+c*c);
    }
    dv[a][b] = 1;
    dd[a][b] = u;
    return u;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        for (int j = 1; j <= k; j++) {
            int a, b;
            cin >> a >> b;
            for (int h = a; h <= b; h++) r1[i][h] = a;
            for (int h = a; h <= b; h++) r2[i][h] = b;
        }
    }
    cout << calc(1,m) << "\n";
}