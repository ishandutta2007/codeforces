#include <bits/stdc++.h>

using namespace std;

const int N = 55;
const int MOD = 1000000007;

inline int add(int u, int v) {return (u += v) >= MOD ? u - MOD : u;}
inline int sub(int u, int v) {return (u -= v) < 0 ? u + MOD : u;}
inline int mul(int u, int v) {return (long long)u * v % MOD;}
inline int power(int u, int v) {int res = 1;for (; v; v >>= 1, u = mul(u, u)) if (v & 1) res = mul(res, u); return res;}
inline int inv(int u) {return power(u, MOD - 2);}
inline void addTo(int &u, int v) {u = add(u, v);}
inline void subTo(int &u, int v) {u = sub(u, v);}
inline void mulTo(int &u, int v) {u = mul(u, v);}

int n, m;
int f[N][N], g[N][N];
int fac[N], invFac[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    fac[0] = 1;
    for (int i = 1; i < N; i++) fac[i] = mul(fac[i - 1], i);
    invFac[N - 1] = inv(fac[N - 1]);
    for (int i = N - 2; i >= 0; i--) invFac[i] = mul(invFac[i + 1], i + 1);
    cin >> n >> m;
    f[0][1] = 1;
    for (int numOp = 1; numOp <= n; numOp++) {
        for (int minCut = 1; minCut <= n + 1; minCut++) {
            // calc g
            for (int firstNumOp = 0; firstNumOp < numOp; firstNumOp++) {
                int secondNumOp = numOp - firstNumOp - 1;
                addTo(g[numOp][minCut], mul(f[firstNumOp][minCut], f[secondNumOp][minCut]));
                for (int notMinCut = minCut + 1; notMinCut <= n + 1; notMinCut++) {
                    addTo(g[numOp][minCut], mul(f[firstNumOp][minCut], f[secondNumOp][notMinCut]));
                    addTo(g[numOp][minCut], mul(f[firstNumOp][notMinCut], f[secondNumOp][minCut]));
                }
            }
            // calc f
            for (int oldNumOp = n; oldNumOp >= 0; oldNumOp--) {
                for (int oldMinCut = 1; oldMinCut <= n + 1; oldMinCut++) {
                    int numer = g[numOp][minCut];
                    for (int num = 1; oldNumOp + numOp * num <= n && oldMinCut + minCut * num <= n + 1; num++) {
                        addTo(f[oldNumOp + numOp * num][oldMinCut + minCut * num], mul(f[oldNumOp][oldMinCut], mul(numer, invFac[num])));
                        mulTo(numer, add(g[numOp][minCut], num));
                    }
                }
            }
        }
    }
    cout << f[n][m] << endl;
    return 0;
}