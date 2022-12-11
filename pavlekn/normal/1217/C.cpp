#include<bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int _ = 0; _ < t; ++_)
    {
        string s;
        cin >> s;
        int n = s.size();
        vector<int> pr(n + 1);
        pr[0] = 0;
        for (int i = 0; i < n; ++i)
        {
            pr[i + 1] = pr[i] + (s[i] - '0');
        }
        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < min(n + 1, i + 20); ++j)
            {
                int cur = 1;
                int cnt = 0;
                for (int k = j - 1; k >= i; --k)
                {
                    if (s[k] == '1')
                    {
                        cnt += cur;
                    }
                    cur *= 2;
                }
                if (cnt >= j - i && cnt <= j && pr[i] - pr[j - cnt] == 0 && s[i] == '1')
                {
                    ++ans;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}