#include <iostream>

using namespace std;

int r, n;
int t[101010];
int x[101010];
int y[101010];
int d[101010];
int p[101010];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> r >> n;
    for (int i = 1; i <= n; i++) cin >> t[i] >> x[i] >> y[i];
    x[0] = 1; y[0] = 1;
    for (int i = 1; i <= n; i++) {
        d[i] = -1;
        for (int j = 1; j <= 2*r && i-j >= 0; j++) {
            if (d[i-j] != -1 && abs(x[i]-x[i-j])+abs(y[i]-y[i-j]) <= t[i]-t[i-j]) {
                d[i] = max(d[i],d[i-j]+1);
            }
        }
        if (i-2*r >= 0) d[i] = max(d[i],p[i-2*r]+1);
        p[i] = max(p[i-1],d[i]);
    }
    cout << p[n] << "\n";
}