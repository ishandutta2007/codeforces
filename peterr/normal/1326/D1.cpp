#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5000;
int b[MAXN];
int e[MAXN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        fill(b, b + MAXN, 0);
        fill(e, e + MAXN, 0);
        string s;
        cin >> s;
        int n = (int) s.length();
        for (int i = 0; i < n; i++)
        {
            if (i < (n + 1) / 2)
                b[i] = max(b[i], 1);
            if (i >= n / 2)
                e[i] = max(e[i], 1);
            for (int j = 1; i - j >= 0 && i + j < n; j++)
            {
                if (s[i - j] != s[i + j])
                    break;
                if (2 * (i - j) + 2 * j + 1 <= n)
                    b[i - j] = max(b[i - j], 2 * j + 1);
                if (2 * (n - (i + j) - 1) + 2 * j + 1 <= n)
                    e[i + j] = max(e[i + j], 2 * j + 1);
            }
        }
        for (int i = 0; i < n - 1; i++)
        {
            if (s[i] != s[i + 1])
                continue;
            if (2 * i + 2 <= n)
                b[i] = max(b[i], 2);
            if (2 * (n - (i + 1) - 1) + 2 <= n)
                e[i + 1] = max(e[i + 1], 2);
            for (int j = 1; i - j >= 0 && i + 1 + j < n; j++)
            {
                if (s[i - j] != s[i + 1 + j])
                    break;
                if (2 * (i - j) + 2 * j + 2 <= n)
                    b[i - j] = max(b[i - j], 2 * j + 2);
                if (2 * (n - (i + 1 + j) - 1) + 2 * j + 2 <= n)
                    e[i + 1 + j] = max(e[i + 1 + j], 2 * j + 2);
            }
        }
        /*
        for (int i = 0; i < n; i++)
            cout << i << " " << b[i] << endl;
        */
        int best = max(b[0], e[n - 1]);
        int ind = -1;
        for (int i = 0; i < n / 2; i++)
        {
            if (s[i] != s[n - i - 1])
                break;
            if (i == n + 1)
            {
                best = 2 * n;
                ind = n - 1;
            }
            else
            {
                int m = max(b[i + 1], e[n - i - 2]);
                if ((i + 1) * 2 + m > best)
                {
                    best = (i + 1) * 2 + m;
                    ind = i;
                }
            }
        }
        string ans = "";
        if (ind >= 0)
        {
            ans += s.substr(0, ind + 1);
            if (ind < n - 1)
            {
                if (b[ind + 1] > e[n - ind - 2])
                {
                    ans += s.substr(ind + 1, b[ind + 1]);
                }
                else
                    ans += s.substr(n - ind - 2 - e[n - ind - 2] + 1, e[n - ind - 2]);
            }
            ans += s.substr(n - ind - 1, ind + 1);
        }
        else
        {
            if (b[0] > e[n - 1])
                ans = s.substr(0, b[0]);
            else
                ans = s.substr(n - e[n - 1], e[n - 1]);
        }
        cout << ans << "\n";
    }
    return 0;
}