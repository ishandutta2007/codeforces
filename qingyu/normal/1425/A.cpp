#include <bits/stdc++.h>

#define ll long long

inline ll read()
{
    ll x = 0;
    char ch = getchar();
    while (!isdigit(ch)) ch = getchar();
    while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
    return x;
}

inline ll solve(ll n)
{
    if (!n) return 0;
    if (n == 4) return 3;
    if (n & 1) return n - solve(n - 1);
    if (n % 4 == 0) return n - solve(n - 1);
    if (n % 2 == 0) return n - solve(n / 2);
}
int f[11000000] = {0};
int main()
{
    int T = read();
    while (T--)
    {
        printf("%lld\n", solve(read()));
    }
    return 0;
}