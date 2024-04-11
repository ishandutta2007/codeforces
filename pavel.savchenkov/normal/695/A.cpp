#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <cassert>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> vvi;

#define forn(i, n) for (int i = 0; i < (int) n; ++i)
#define ford(i, n) for (int i = ((int) n) - 1; i >= 0; --i)
#define sz(c) ((int) (c).size())
#define mp(x, y) make_pair(x, y)
#define prev prev___________________
#define hash hash___________________
#define pb push_back

#define FILE_NAME ""

void solve (int n)
{
    int k;
    cin >> k;

    typedef double T;
    vector<T> p(n);
    for (int i = 0; i < n; i++)
        cin >> p[i];

    T dp[2][1 << n];
    memset(dp, 0, sizeof dp);

    vector<char> isgood(n);
    vi good;
    for (int i = 0; i < n; i++)
    if (p[i] != 0)
    {
        isgood[i] = 1;
        good.pb(i);
    }

    dp[0][0] = 1;
    int c = 1;

    vector<T> sum(1 << n);
    sum[0] = 1.0;
    for (int j = 1; j < (1 << n); j++)
    {
        int x = __builtin_ctz(j);
        assert((j >> x) & 1);
        sum[j] = sum[j ^ (1 << x)] - p[x];
    }

    for (int i = 0; i < min(sz(good), k); i++)
    {
        memset(dp[c], 0, sizeof dp[c]);

        for (int j = 0; j < (1 << n); j++)
        {
            if (__builtin_popcount(j) != i)
                continue;

            for (int next : good)
            if (!((j >> next) & 1))
            {
                dp[c][j ^ (1 << next)] += dp[c ^ 1][j] * p[next] / sum[j];
            }
        }

        c ^= 1;
    }

    c ^= 1;
    for (int i = 0; i < n; i++)
    {
        if (!isgood[i])
            printf("%.12f ", (double)0);
        else
        {
            T ans = 0;
            for (int j = 0; j < (1 << n); j++)
            if (((j >> i) & 1))
                ans += dp[c][j];
            printf("%.12f ", (double)ans);
        }
        puts("");
    }
}

int main() {
#ifndef ONLINE_JUDGE
  freopen(FILE_NAME ".in", "r", stdin);
	freopen(FILE_NAME ".out", "w", stdout);
#endif

	int n;
	while (cin >> n)
		solve(n);

#ifdef LOCAL
	cerr << "Time: " << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}