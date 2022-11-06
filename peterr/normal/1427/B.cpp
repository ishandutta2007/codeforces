#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        int n, k;
        cin >> n >> k >> s;
        vector<int> gaps;
        int ind = 0;
        int total = 0;
        if (s[0] == 'W')
            gaps.push_back(0);
        while (ind < (int) s.length())
        {
            while (ind < n && s[ind] == 'W')
            {
                ind++;
            }
            int cnt = 0;
            while (ind < n && s[ind] == 'L')
            {
                total++;
                ind++;
                cnt++;
            }
            gaps.push_back(cnt);
        }
        int ans = s[0] == 'W';
        for (int i = 1; i < n; i++)
        {
            if (s[i] == 'L')
                continue;
            ans++;
            if (s[i - 1] == 'W')
                ans++;
        }
        int flips = min(k, total);
        ans += flips * 2;
        if (flips && total == n)
        {
            ans--;
        }
        gaps.pop_back();
        if (!gaps.empty())
        {
            reverse(gaps.begin(), gaps.end());
            gaps.pop_back();
        }
        if (!gaps.empty())
        {
            sort(gaps.begin(), gaps.end());
            reverse(gaps.begin(), gaps.end());
            while (!gaps.empty() && k >= gaps.back())
            {
                k -= gaps.back();
                ans++;
                gaps.pop_back();
            }
        }
        cout << ans << "\n";
    }
    return 0;
}