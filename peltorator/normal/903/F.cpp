#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <cstdio>
#include <string>
#include <cstring>
#include <queue>
#include <set>
#include <memory.h>
#include <map>
#include <complex>
#include <unordered_map>
#include <unordered_set>
#include <deque>

#define deb(a) cerr << #a << " = " << (a) << "\n"
#define deb2(a, b) deb(a); deb(b)
#define deb3(a, b, c) deb(a); deb(b); deb(c)
#define deb4(a, b, c, d) deb(a); deb(b); deb(c); deb(d)

using namespace std;

typedef long long ll;

const ll INF = 1e18 + 7LL;
const int N = 5, M = 1011, T = (1 << 12) + 3;

ll a[N];
string s[N];
string t = "";

ll dp[M][N][T];

void f(int i, int j, int k, int l, int m, int n, ll q = 0)
{
  //  cout << i << " " << j << " " << k << endl;
    dp[i][j][k] = min(dp[i][j][k], dp[l][m][n] + q);
}

int main()
{
   // freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 1; i <= 4; i++)
        cin >> a[i];
    for (int i = 0; i < 4; i++)
        cin >> s[i];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 4; j++)
            t += s[j][i];
    for (int i = 0; i < 100000; i++)
        t.push_back('.');
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            for (int k = 0; k < T; k++)
                dp[i][j][k] = INF;
  /*  for (int i = 0; i < 3; i++)
        for (int j = 0; j < 4; j++)
            dp[i][j][0] = 0;*/
    dp[0][0][0] = 0;
    for (int i = 0; i < n + 4; i++)
        for (int j = 0; j < 4; j++)
            for (int mask = 0; mask < (1 << 12); mask++)
            {
                bool ok = 0;
                if (mask % 2 == 1 || i * 4 + j < 11 || t[i * 4 + j - 11] == '.')
                {
                //    cout << i << " " << j << " " << mask << endl;
                    if (j + 1 < 4)
                        f(i, j + 1, mask / 2, i, j, mask);
                    else
                        f(i + 1, 0, mask / 2, i, j, mask);
                    ok = true;
                }
                for (int k = 0; k < 3; k++)
                    f(i, j, (mask | (1 << k)), i, j, mask, a[1]);
                for (int k = 5; k < 12; k++)
                    if ((11 - k) % 4 != j)
                        f(i, j, (mask | (1 << k) | (1 << (k - 1)) | (1 << (k - 4)) | (1 << (k - 5))), i, j, mask, a[2]);
                for (int k = 10; k <= 11; k++)
                    if ((k == 10 && j == 3 && i >= 2) || (k == 11 && j >= 2 && i >= 2) || (k == 10 && j == 0 && i >= 3))
                        f(i, j, (mask | (1 << k) | (1 << (k - 1)) | (1 << (k - 2)) | (1 << (k - 4)) | (1 << (k - 5)) | (1 << (k - 6)) | (1 << (k - 8)) | (1 << (k - 9)) | (1 << (k - 10))), i, j, mask, a[3]);
                if (j == 3)
                    f(i + 1, j, (1 << 12) - 1, i, j, mask, a[4]);
            }
    cout << dp[n + 2][3][0] << endl;
    return 0;
}