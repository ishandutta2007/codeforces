#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair
#define int long long

int mod = 1000000007;

using namespace std;

int a[50][50][205];
int c[51][51];
void precompute()
{
    c[0][0] = 1;
    for (int n = 1; n <= 50; ++n)
        for (int r = 50; r >= 0 ; --r)
            c[n][r] = (c[n - 1][r] + c[n - 1][r - 1]) % mod;
}

int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    precompute();
    int n, K;
    cin >> n >> K;
    K /= 50;
    int fif = 0, hun = 0;
    for (int i = 0; i < n; ++i)
    {
        int x; cin >> x;
        if (x == 50)
            fif++;
        else
            hun++;
    }
    a[0][0][0] = 1;
    for (int i = 0; i <= 203; ++i)
        for (int j = 0; j <= hun; ++j)
            for (int k = 0; k <= fif; ++k)
                if (i % 2 == 0)
                    for (int o = 0; o <= min(hun - j, K / 2); ++o)
                        for (int p = 0; p <= min(K - o * 2, fif - k); ++p)
                        {
                            if (o + p == 0)
                                continue;
                            a[j + o][p + k][i + 1] = (a[j + o][p + k][i + 1] + c[hun - j][o] * c[fif - k][p] * a[j][k][i]) % mod;
                        }
                else
                    for (int o = 0; o <= min(j, K / 2); ++o)
                        for (int p = 0; p <= min(K - o * 2, k); ++p)
                        {
                            if ((o + p) == 0)
                                continue;
                            a[j - o][k - p][i + 1] = (a[j - o][k - p][i + 1] + c[j][o] * c[k][p] * a[j][k][i]) % mod;
                        }
    for (int i = 0; i <= 203; ++i)
        if (a[hun][fif][i])
        {
            cout << i << "\n";
            cout << a[hun][fif][i] << "\n";
            exit(0);
        }
    cout << "-1\n0\n";
}