#include <bits/stdc++.h>

using namespace std;

#define int long long

const int INF = 1e18 + 118;

int pw[30];
int cnt[30];

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, val;
    cin >> n >> val;
    pw[0] = 1;
    for (int i = 1; i < 30; ++i)
    {
        pw[i] = pw[i - 1] * 2;
    }
    string s;
    cin >> s;
    val -= pw[s[n - 1] - 'a'];
    val += pw[s[n - 2] - 'a'];
    val = abs(val);
    int cur = 0;
    string ss;
    for (int i = 0; i < n - 2; ++i)
    {
        ss.push_back(s[i]);
    }
    for (auto el : ss)
    {
        cur += pw[el - 'a'];
        ++cnt[el - 'a'];
    }
    int r = 29;
    int it = 0;
    while (cur > val && it < n)
    {
        ++it;
        for (int i = r; i >= 0; --i)
        {
            if (cur - 2 * pw[i] >= val && cnt[i])
            {
                --cnt[i];
                cur -= 2 * pw[i];
            }
            else
            {
                --r;
            }
        }
    }
    if (cur != val)
    {
        cout << "No" << endl;
    }
    else
    {
        cout << "Yes" << endl;
    }
    return 0;
}