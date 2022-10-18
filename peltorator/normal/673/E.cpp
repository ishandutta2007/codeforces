#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <cstdio>
#include <string>
#include <cstring>
#include <complex>
#include <queue>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 200001, K = 55;
const ll INF = 1e18;

ld dp[K][N];
ll sum[N], t[N];
ld x[N], y[N];

ld sumt(int j, int i)
{
    return x[i] - x[j - 1] - (y[i] - y[j - 1]) * (ld)sum[j - 1];
}

void divide(int l, int r, int ql, int qr, int cur)
{
    if (r < l)
        return;
    int mid = (r + l) / 2;
    int p = mid + 1;
    for (int i = ql; i <= min(mid, qr); i++)
    {
        ld now = dp[cur - 1][i - 1] + sumt(i, mid);
        if (now < dp[cur][mid])
        {
            dp[cur][mid] = now;
            p = i;
        }
    }
    divide(l, mid - 1, ql, min(qr, p), cur);
    divide(mid + 1, r, max(ql, p), qr, cur);
}

int main()
{
    //freopen("in.txt", "r", stdin);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> t[i];
    for (int i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + t[i];
    for (int i = 1; i <= n; i++)
        x[i] = x[i - 1] + (ld)sum[i] / (ld)t[i];
    for (int i = 1; i <= n; i++)
        y[i] = y[i - 1] + (ld)1 / (ld)t[i];
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= k; j++)
            dp[j][i] = INF;
    dp[0][0] = 0;
    for (int i = 1; i <= k; i++)
    {
        divide(1, n, 1, n, i);
    }
    cout.precision(30);
    cout << dp[k][n];
    return 0; 
}