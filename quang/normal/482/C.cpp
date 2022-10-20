#include<bits/stdc++.h>

using namespace std;

string s[60];
int m, n;
long long d[(1 << 21)], a[60], c[60][60];

int main() {
    ios_base::sync_with_stdio(0);
    //freopen("inp.txt", "r", stdin);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> s[i];
    m = s[0].size();
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++) {
            int mask = 0;
            for(int k = 0; k < m; k++)
                if(s[i][k] == s[j][k])
                    mask |= (1 << k);
            d[mask] |= (1ll << i);
            d[mask] |= (1ll << j);
        }
    for(int i = (1 << m) - 1; i; i--)
        for(int j = 0; j < m; j++)
            if(i & (1 << j))
                d[i ^ (1 << j)] |= d[i];
    for(int i = 0; i < (1 << m); i++) {
        int sl = __builtin_popcount(i) + 1;
        for(int j = 0; j < m; j++)
            if((i & (1 << j)) == 0) {
                long long mask = d[i] ^ d[i | (1 << j)];
                int sl2 = __builtin_popcountll(mask);
                a[sl] += sl2;
            }
    }
    for(int i = 0; i <= m; i++)
        for(int j = 0 ; j <= i; j++)
            if(j == 0 || j == i) c[i][j] = 1;
            else c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
    long double ans = 0;
    for(int i = 1; i <= m; i++)
        ans += (long double)a[i] / (long double)c[m][i];
    ans /= (long double) n;
    printf("%0.15f", (double)ans);
    return 0;
}