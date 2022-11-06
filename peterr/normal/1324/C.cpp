#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
int pre[MAXN + 2];

bool check(string& s, int d, int n)
{
    int cur = 0;
    while (pre[min(n + 1, cur + d)] != cur)
    {
        cur = pre[min(n + 1, cur + d)];
    }
    return cur == n + 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int n = (int) s.length();
        s = " " + s;
        for (int i = 1; i <= n; i++)
        {
            if (s[i] == 'R')
                pre[i] = i;
            else
                pre[i] = pre[i - 1];
        }
        pre[n + 1] = n + 1;
        int ans = 0;
        for (int jump = 2E5; jump > 0; jump /= 2)
        {
            while (!check(s, ans + jump, n))
                ans += jump;
        }
        cout << ans + 1 << "\n";
    }
    return 0;
}