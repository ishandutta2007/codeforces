#include <bits/stdc++.h>

using namespace std;

const int MAXN = 500;
string dp1[MAXN + 1];
string dp2[MAXN + 1];

void relax(string& a, const string& b)
{
    if (a.empty() || b < a)
        a = b;
}

char improve(char c, int k)
{
    if (c == 'a')
        return c;
    else if (c == 'a' + k - 1)
        return 'a';
    return (char) (c - 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        string s;
        cin >> n >> k >> s;
        fill(dp1, dp1 + n + 1, "");
        fill(dp2, dp2 + n + 1, "");
        dp1[1] = improve(s[0], k);
        dp2[1] = s[0];
        for (int i = 1; i <= n - 1; i++)
        {
            relax(dp1[i + 1], dp1[i] + improve(s[i], k));
            relax(dp1[i + 1], dp1[i].substr(0, i - 1) + s[i] + dp1[i][i - 1]);
            relax(dp2[i + 1], dp1[i] + s[i]);

            relax(dp1[i + 1], dp2[i].substr(0, i - 1) + improve(s[i], k) + dp2[i][i - 1]);
            if (i >= 2)
                relax(dp1[i + 1], dp2[i].substr(0, i - 2) + s[i] + dp2[i][i - 2] + dp2[i][i - 1]);
            relax(dp1[i + 1], dp2[i] + s[i]);
        }
        cout << dp1[n] << "\n";
    }
    return 0;
}