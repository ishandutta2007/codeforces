#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
long double prob[MAXN + 1];

long double poww(long double b, int p)
{
    long double x = b;
    long double ans = 1;
    while (p)
    {
        if (p & 1)
        {
            ans *= x;
        }
        p = p >> 1;
        x = x * x;
    }
    return ans;
}

int main()
{
    int m, n;
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
    {
        prob[i] = poww((long double) i / m, n);
        //cout << i << " " << prob[i] << endl;
    }
    long double ans = 0;
    for (int i = 1; i <= m; i++)
    {
        ans += (prob[i] - prob[i - 1]) * i;
        //cout << i << " " << ans << endl;
    }
    cout << fixed << setprecision(5) << ans << endl;

    return 0;
}