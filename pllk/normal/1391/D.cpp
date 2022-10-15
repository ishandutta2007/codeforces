#include <iostream>

using namespace std;

int n, m;
int r[3][1000000];
int dd[1000000][10];
int dv[1000000][10];

bool valid(int a, int b) {
    int x = a^b;
    if (n == 2) return x == 1 || x == 2;
    else return x == 2 || x == 5;
}

int calc(int k, int b) {
    if (dv[k][b]) return dd[k][b];
    int c = 0;
    for (int i = 0; i < n; i++) {
        char a = (b&(1<<i)) ? '1' : '0';
        if (a != r[i][k]) c++;
    }
    int d = 0;
    if (k > 0) {
        d = 1e9;
        for (int u = 0; u < (1<<n); u++) {
            if (valid(u,b)) d = min(d,calc(k-1,u));
        }
    }
    dv[k][b] = 1;
    dd[k][b] = c+d;
    return dd[k][b];
}

int main() {
    cin >> n >> m;
    if (n == 1 || m == 1) {
        cout << "0\n";
        return 0;
    }
    if (n >= 4 && m >= 4) {
        cout << "-1\n";
        return 0;
    }
    int f = n < m;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            if (f) r[i][j] = s[j];
            else r[j][i] = s[j];
        }
    }
    if (!f) swap(n,m);
    int r = 1e9;
    for (int i = 0; i < (1<<n); i++) r = min(r,calc(m-1,i));
    cout << r << "\n";
}