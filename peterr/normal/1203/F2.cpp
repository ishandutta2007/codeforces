#include <bits/stdc++.h>

using namespace std;

struct Project
{
    int rating, change;
};

const int MAXN = 100;
const int MAXR = 30000;
Project pos[MAXN];
Project neg[MAXN];
int dp[MAXR * 2 + 5];

int main()
{
    int n, r;
    cin >> n >> r;
    int len1 = 0, len2 = 0;
    for (int i = 0; i < n; i++)
    {
        Project p;
        cin >> p.rating >> p.change;
        if (p.change >= 0)
            pos[len1++] = p;
        else
            neg[len2++] = p;
    }
    sort(pos, pos + len1, [] (Project p1, Project p2) {return p1.rating < p2.rating;});
    int ans = 0;
    for (int i = 0; i < len1; i++)
    {
        if (r >= pos[i].rating)
        {
            r += pos[i].change;
            ans++;
        }
    }
    if (len2 > 0)
    {
        sort(neg, neg + len2, [] (Project p1, Project p2) {return p1.rating + p1.change < p2.rating + p2.change;});
        int maxCount = 0;
        for (int i = len2 - 1; i >= 0; i--)
        {
            for (int j = 0; j <= r; j++)
            {
                if (j >= neg[i].rating + neg[i].change && j - neg[i].change <= r)
                    dp[j] = max(dp[j], 1 + dp[j - neg[i].change]);
                maxCount = max(maxCount, dp[j]);
            }
        }
        ans += maxCount;
    }
    cout << ans << endl;
    return 0;
}