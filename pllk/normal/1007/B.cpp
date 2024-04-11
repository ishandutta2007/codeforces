#include <iostream>

using namespace std;

int d[101010];

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b,a%b);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 1; i <= 100000; i++) {
        for (int j = i; j <= 100000; j += i) {
            d[j]++;
        }
    }
    int t;
    cin >> t;
    while (t--) {
        int x[3];
        cin >> x[0] >> x[1] >> x[2];
        int z[6][3] = {{0,1,2},{0,2,1},{1,0,2},{1,2,0},{2,0,1},{2,1,0}};
        int r = 0;
        int ww[8];
        ww[1] = x[0];
        ww[2] = x[1];
        ww[4] = x[2];
        ww[3] = gcd(x[0],x[1]);
        ww[5] = gcd(x[0],x[2]);
        ww[6] = gcd(x[1],x[2]);
        ww[7] = gcd(x[0],gcd(x[1],x[2]));
        for (int b = 1; b < (1<<6); b++) {
            int g[3] = {0};
            int f = 0;
            for (int i = 0; i < 6; i++) {
                if (b&(1<<i)) {
                    f++;
                    g[0] |= (1<<z[i][0]);
                    g[1] |= (1<<z[i][1]);
                    g[2] |= (1<<z[i][2]);
                }
            }
            int u = d[ww[g[0]]]*d[ww[g[1]]]*d[ww[g[2]]];
            if (f%2 == 1) r += u;
            else r -= u;
        }
        int u = 0;
        int gg = ww[7];
        int h0 = ww[3];
        int h1 = ww[5];
        int h2 = ww[6];
        u += d[gg];
        r -= d[gg];
        int e = d[x[0]]+d[x[1]]+d[x[2]]-d[h0]-d[h1]-d[h2]+d[gg];
        u += d[gg]*(e-1);
        r -= d[gg]*(e-1)*3;
        u += (d[h0]-d[gg])*d[x[2]];
        r -= (d[h0]-d[gg])*d[x[2]]*3;
        u += (d[h1]-d[gg])*d[x[1]];
        r -= (d[h1]-d[gg])*d[x[1]]*3;
        u += (d[h2]-d[gg])*d[x[0]];
        r -= (d[h2]-d[gg])*d[x[0]]*3;
        u += r/6;
        cout << u << "\n";
    }
}