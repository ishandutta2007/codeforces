#include<bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 2e5 + 77;

int pr[MAXN][26];

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int q;
    cin >> q;
    int n = s.size();
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < 26; ++j)
        {
            if (s[i] == 'a' + j)
            {
                pr[i + 1][j] = pr[i][j] + 1;
            }
            else
            {
                pr[i + 1][j] = pr[i][j];
            }
        }
    }
    for (int _ = 0; _ < q; ++_)
    {
        int l, r;
        cin >> l >> r;
        --l;
        if (s[l] != s[r - 1] || r - l == 1)
        {
            cout << "Yes" << endl;
            continue;
        }
        else
        {
            int cnt = 0;
            for (int i = 0; i < 26; ++i)
            {
                if (pr[r][i] - pr[l][i] > 0)
                {
                    ++cnt;
                }
            }
            if (cnt > 2)
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
        }
    }
    return 0;
}