#include <iostream>
#include <vector>

using namespace std;

#define A 1e9

int n, k;
int m;
int e[88][88];
int v[88][88][3][88];
int d[88][88][3][88];

int laske(int a, int b, int s, int c) {
    int u = A;
    if (c == k-1) return 0;
    if (v[a][b][s][c]) return d[a][b][s][c];
    if (s == 0) {
        for (int i = a+1; i <= b-1; i++) {
            if (e[a][i] == A) continue;
            int u1 = e[a][i]+laske(i,b,0,c+1);
            int u2 = e[a][i]+laske(a,i,1,c+1);
            u = min(u,u1);
            u = min(u,u2);
        }
    } else {
        for (int i = a+1; i <= b-1; i++) {
            if (e[b][i] == A) continue;
            int u1 = e[b][i]+laske(i,b,0,c+1);
            int u2 = e[b][i]+laske(a,i,1,c+1);
            u = min(u,u1);
            u = min(u,u2);
        }
    }
    v[a][b][s][c] = 1;
    d[a][b][s][c] = u;
    return u;
}

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            e[i][j] = A;
        }
    }
    cin >> m;
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        e[a][b] = min(e[a][b],c);
    }
    int p = A;
    for (int i = 1; i <= n; i++) {
        p = min(p,laske(i,n+1,0,0));
        p = min(p,laske(0,i,1,0));
    }
    if (p == A) cout << "-1\n";
    else cout << p << "\n";
}