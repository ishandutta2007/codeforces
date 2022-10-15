#include <iostream>

using namespace std;

#define INF 999999999

int a[111];
int b[111];

int d[101][101][10001];
char v[101][101][10001];

int f(int n, int k, int m) {
    if (k < 0 || m < 0) return -INF;
    if (n == 0) return (k == 0 && m == 0) ? 0 : -INF;
    if (v[n][k][m]) return d[n][k][m];
    int r = max(f(n-1,k-1,m-b[n])+a[n]-b[n],f(n-1,k,m));
    v[n][k][m] = 1;
    d[n][k][m] = r;
    return r;
}

int main() {
    int n;
    cin >> n;
    int s = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
        s += b[i];
    }
    for (int i = 1; i <= n; i++) {
        double g = 0;
        for (int m = 0; m <= 100*i && m <= s; m++) {
            double u = m+min((double)(s-m)/2,(double)f(n,i,m));
            g = max(g,u);
        }
        cout << g << " ";
    }
    cout << "\n";
}