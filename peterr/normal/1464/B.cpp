#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;

long long solve(int n, string &s, int x, int y)
{
    long long ans = 0;
    int ones = 0;
    int zeros = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] != '1')
        {
            ans += (long long) ones * y;
            zeros++;
        }
        else
        {
            ans += (long long) zeros * x;
            ones++;
        }
    }
    int prefOnes = 0;
    int prefZeros = 0;
    int unknown = 0;
    long long temp = ans;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '?')
        {
            unknown++;
            temp -= (long long) (prefOnes + unknown - 1) * y;
            temp -= (long long) (ones - prefOnes) * x;
            temp += (long long) prefZeros * x;
            temp += (long long) (zeros - prefZeros - unknown) * y;
        }
        else if (s[i] == '1')
            prefOnes++;
        else if (s[i] == '0')
            prefZeros++;
        ans = min(ans, temp);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    int x, y;
    cin >> s >> x >> y;
    long long ans = solve((int) s.length(), s, x, y);
    reverse(s.begin(), s.end());
    ans = min(ans, solve((int) s.length(), s, y, x));
    cout << ans << "\n";
    return 0;
}