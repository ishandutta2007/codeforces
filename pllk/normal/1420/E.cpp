#include <iostream>

using namespace std;

int n;
int a[100];
int p[100];
int z;

#define INF 999999999

int dd[81][81*81][81][2];
char rr[81][81*81][81][2];

// a = oikea reuna
// b = haluttu tulos
// c = 1-bittej kytetty
// d = vli ok
int calc(int a, int b, int c, int d) {
    if (b < 0) return INF;
    if (a == 0) return (b == 0 && c == 0) ? 0 : INF;
    if (rr[a][b][c][d]) return dd[a][b][c][d];
    int u = INF;
    if (c >= 1) {
        u = min(u,calc(a-1,b,c-1,1)+abs(a-p[c]));
    }
    if (d) {
        for (int i = 1; i <= a-c; i++) {
            u = min(u,calc(a-i,b-i*(z-i),c,0));
        }
    }
    rr[a][b][c][d] = 1;
    dd[a][b][c][d] = u;
    return u;
}

int r[100*100];

int main() {
    cin >> n;
    int c = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] == 1) {
            c++;
            p[c] = i;
        } else z++;
    }
    for (int i = 0; i <= n*(n-1); i += 2) {
        int f = calc(n,i,c,1);
        if (f == INF) continue;
        r[f] = max(r[f],i/2);
    }
    int k = 0;
    for (int i = 0; i <= n*(n-1)/2; i++) {
        k = max(k,r[i]);
        cout << k << " ";
    }
    cout << "\n";
}