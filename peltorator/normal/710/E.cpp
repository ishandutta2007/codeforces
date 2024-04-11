#include <iostream>
#include <vector>
#include <cstdio>
#include <map>
#include <algorithm>
#include <math.h>
#include <string>
#include <cstring>
#include <set>
#include <queue>
#include <unordered_set>
#include <unordered_map>
using namespace std;

typedef long long ll;
typedef double ld;

const int N = 30000001;

ll dp[N];

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, x, y;
    cin >> n >> x >> y;
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = dp[i - 1] + x;
        if (i % 2 == 0)
            dp[i] = min(dp[i], dp[i / 2] + y);
        else
            dp[i] = min(dp[i], min(dp[i / 2], dp[(i + 1) / 2]) + x + y);
    }
    cout << dp[n];
    return 0;
}