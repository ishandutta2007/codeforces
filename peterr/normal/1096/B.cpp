#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;

int solve(string &s, char c, int n)
{
    int left = n, right = -1;
    for (int i = 0; i < n; i++)
    {
        if (s[i] != c)
        {
            right = i;
            left = min(left, i);
        }
    }
    return ((long long) (left + 1) * (n - right) - 1) % MOD;
}

int main()
{
    int n;
    string s;
    cin >> n >> s;
    int ans = 1;
    for (char c = 'a'; c <= 'z'; c++)
    {
        ans += solve(s, c, n);
    }
    cout << ans << endl;
    return 0;
}