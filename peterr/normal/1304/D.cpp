#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
int ans1[MAXN];
int ans2[MAXN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string s;
        cin >> n >> s;
        int ptr = -1;
        int cur = n;
        while (ptr < n - 1)
        {
            ptr++;
            int cnt = 1;
            while (ptr < n - 1 && s[ptr] == '<')
            {
                ptr++;
                cnt++;
            }
            for (int i = 0; i < cnt; i++)
            {
                ans1[ptr - i] = cur--;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (i > 0)
                cout << " ";
            cout << ans1[i];
        }
        cout << "\n";
        int up, down;
        up = down = 0;
        for (int i = 0; i < n - 1; i++)
            if (s[i] == '<')
                up++;
            else
                down++;
        ans2[0] = down + 1;
        ptr = 0;
        up = down + 2;
        down = 1;
        while (ptr < n - 1)
        {
            if (s[ptr] == '<')
                ans2[++ptr] = up++;
            else
            {
                int cnt = 1;
                ptr++;
                while (ptr < n - 1 && s[ptr] == '>')
                {
                    ptr++;
                    cnt++;
                }
                for (int i = 0; i < cnt; i++)
                {
                    ans2[ptr - i] = down++;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (i > 0)
                cout << " ";
            cout << ans2[i];
        }
        cout << "\n";
    }
    return 0;
}