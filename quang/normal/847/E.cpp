#include <bits/stdc++.h>
#define FOR(i, j, k) for (int i = j; i <= k; i ++)
#define FORD(i, j, k) for (int i = j; i >= k; i --)
#define mn 200005
#define maxC 1000000007
#define base 100007
#define F first
#define S second

using namespace std;
int n, lPac[mn], lastTrue[mn];
char field[mn];
bool dp[mn];

void setup()
{
    cin >> n;
    FOR(i, 1, n)
    {
        cin >> field[i];
        if (field[i - 1] == 'P')
            lPac[i] = i - 1;
        else
            lPac[i] = lPac[i - 1];
    }
}

bool ok(int x)
{
//    cout << x << '\n';
    dp[0] = true;
    lastTrue[0] = 0;

    FOR(i, 1, n)
    {
        if (dp[i - 1])
            lastTrue[i] = i - 1;
        else
            lastTrue[i] = lastTrue[i - 1];

        if (field[i] == '.')
            dp[i] = dp[i - 1];

        if (field[i] == 'P')
            dp[i] = (i - x - 1 <= lastTrue[i]);

        if (field[i] == '*')
        {
            if (!lPac[i] || i - lPac[i] > x)
            {
                dp[i] = false;
//                cout << dp[i];
                continue;
            }

            int timeMoveRight = i - lPac[i];
            int timeMoveLeft = max(x - timeMoveRight * 2, (x - timeMoveRight) / 2);
            dp[i] = (lPac[i] - timeMoveLeft - 1 <= lastTrue[lPac[i]]);
        }
//        cout << dp[i];
    }
//    cout << '\n';
//    FOR(i, 1, n)
//        cout << lastTrue[i] << ' ';
//    cout << '\n';
    return dp[n];
}

void xuly ()
{
    int l = 0, r = n * 2;
    while(r - l > 1)
    {
        int g = ((l + r) >> 1);
        if (ok(g))
            r = g;
        else
            l = g;
    }
    cout << r;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    setup ();
    xuly ();
    return 0;
}