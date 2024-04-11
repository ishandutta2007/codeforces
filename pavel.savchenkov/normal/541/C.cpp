#include <bits\stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef vector<int> Vint;
typedef long double ld;

typedef unsigned long long ull;

ull gcd(ull a, ull b)
{
    while (a && b)
    {
        if (a > b)
            a %= b;
        else
            b %= a;
    }

    return a + b;
}

ull lcm(ull a, ull b)
{
    return (a / gcd(a, b)) * b;
}

int ends_max(const Vint &f, int pos)
{
    int n = (int)f.size() - 1;

    Vint dp(n + 1, 0);

    for (int it = 1; it <= n; it++)
    {
        for (int i = 1; i <= n; i++)
        if (dp[f[i]] <= dp[i])
            dp[f[i]] = dp[i] + 1;
    }

    return dp[pos] + 1;
}

void solve(int n)
{
    Vint f(n + 1);
    for (int i = 1; i <= n; i++)
        scanf(" %d", &f[i]);

    int border = 0;
    ull ans = 1;

    for (int i = 1; i <= n; i++)
    {
        Vint path;
        vector<char> used(n + 1, 0);
        path.pb(i);

        while (!used[path.back()])
            used[path.back()] = 1, path.pb(f[path.back()]);

        if (path.back() == path[0])
            ans = lcm(ans, (ull)(path.size() - 1));
        else
            border = max(border, ends_max(f, i));
    }

    for (int i = 1;; i++)
    if (ans * i >= border)
    {
        ans *= i;
        break;
    }

    cout << ans << endl;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    while (cin >> n)
        solve(n);
}