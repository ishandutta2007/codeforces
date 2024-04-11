#include <iostream>

using namespace std;

#define M 998244353

typedef long long ll;

int n, m;
int aa[55];
int ww[55];
int s0, s1;

ll pot(int a, int b) {
    if (b == 0) return 1;
    ll u = pot(a,b/2);
    u = u*u%M;
    if (b%2 == 1) u = u*a%M;
    return u;
}

ll d[55][55][55][111];
ll inv[3000];

ll inc(ll p, ll x, ll y) {
    p *= x;
    p %= M;
    p *= inv[y];
    p %= M;
    return p;
}

int main() {
    for (int i = 1; i < 3000; i++) {
        inv[i] = pot(i,M-2);
    }
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> aa[i];
    for (int i = 1; i <= n; i++) {
        cin >> ww[i];
        if (aa[i] == 0) s0 += ww[i];
        else s1 += ww[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            for (int a = 0; a <= m; a++) {
                for (int b = 0; b <= m; b++) {
                    for (int c = 0; c <= 100; c++) {
                        d[j][a][b][c] = 0;
                    }
                }
            }
        }
        d[0][0][0][ww[i]] = 1;
        for (int j = 0; j < m; j++) {
            for (int a = 0; a <= j; a++) {
                for (int b = 0; a+b <= j; b++) {
                    int u0 = s0-a;
                    int u1 = s1+b;
                    int uu = u0+u1;
                    int r0 = max(0,ww[i]-a);
                    int r1 = min(100,ww[i]+b);
                    if (aa[i] == 0) {
                        for (int c = r0; c <= ww[i]; c++) {
                            ll p = d[j][a][b][c]%M;
                            if (u0 > 0) {
                                d[j+1][a+1][b][c-1] += inc(p,c,uu);
                                //d[j+1][a+1][b][c-1] %= M;
                                d[j+1][a+1][b][c] += inc(p,u0-c,uu);
                                //d[j+1][a+1][b][c] %= M;
                            }
                            d[j+1][a][b+1][c] += inc(p,u1,uu);
                            //d[j+1][a][b+1][c] %= M;
                        }
                    } else {
                        for (int c = ww[i]; c <= r1; c++) {
                            ll p = d[j][a][b][c]%M;
                            if (u0 > 0) {
                                d[j+1][a+1][b][c] += inc(p,u0,uu);
                                //d[j+1][a+1][b][c] %= M;
                            }
                            d[j+1][a][b+1][c+1] += inc(p,c,uu);
                            //d[j+1][a][b+1][c+1] %= M;
                            d[j+1][a][b+1][c] += inc(p,u1-c,uu);
                            //d[j+1][a][b+1][c] %= M;
                        }
                    }
                }
            }
        }
        ll pp = 0;
        for (int a = 0; a <= m; a++) {
            for (int b = 0; b <= m; b++) {
                for (int c = 0; c <= 100; c++) {
                    pp += d[m][a][b][c]%M*c;
                    pp %= M;
                }
            }
        }
        cout << pp << "\n";
    }
}