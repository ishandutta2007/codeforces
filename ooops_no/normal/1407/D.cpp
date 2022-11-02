#include<iostream>
#include<vector>
#include<map>
#include<cmath>
#include<algorithm>
#include<string>
#include<set>
#include<deque>

using namespace std;

#define pb push_back
#define ld long double

const int N = 3e5 + 10;
pair<int,int> po[30][N], po1[30][N];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    deque<pair<int,int>> q;
    vector<int> go(n), go1(n), lastt(n), last1(n);
    map<int,int> dp;
    for (int i = 0; i < n; i++){
        dp[i] = 2e9;
    }
    dp[-1] = 2e9;
    q.pb({2e9, -1});
    for (int i = n - 1; i > -1; i--)
    {
        while(v[i] > q.back().first)
        {
            go[q.back().second] = i;
            q.pop_back();
        }
        q.pb({v[i], i});
    }
    while(q.size() > 1)
    {
        go[q.back().second] = -1;
        q.pop_back();
    }
    for (int i = n - 1; i > -1; i--){
        while(v[i] >= q.back().first){
            lastt[q.back().second] = i;
            q.pop_back();
        }
        q.pb({v[i], i});
    }
    while(q.size() > 1){
        lastt[q.back().second] = -1;
        q.pop_back();
    }
    q.clear();
    q.pb({-2e9, -1});
    for (int i = n - 1; i > -1; i--){
        while(v[i] <= q.back().first){
            last1[q.back().second] = i;
            q.pop_back();
        }
        q.pb({v[i], i});
    }
    while(q.size() > 1){
        last1[q.back().second] = -1;
        q.pop_back();
    }
    for (int i = n - 1; i > -1; i--)
    {
        while(v[i] < q.back().first)
        {
            go1[q.back().second] = i;
            q.pop_back();
        }
        q.pb({v[i], i});
    }
    while(q.size() > 1)
    {
        go1[q.back().second] = -1;
        q.pop_back();
    }
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            dp[i] = 0;
        }
        else
        {
            if (go[i] == i - 1)
            {
                dp[i] = dp[i - 1] + 1;
            }
            else
            {
                int last = max(lastt[i], 0), now = i - 1, ans = dp[i - 1];
                for (int j = 29; j >= 0; j--)
                {
                    if (po[j][now].first >= last)
                    {
                        ans = min(ans, po[j][now].second);
                        now = po[j][now].first;
                    }
                }
                dp[i] = min(dp[i], ans + 1);
            }
            if (go1[i] == i - 1){
                dp[i] = min(dp[i - 1] + 1, dp[i]);
            }
            else{
                int last = max(last1[i], 0), now = i - 1, ans = dp[i - 1];
                for (int j = 29; j >= 0; j--){
                    if (po1[j][now].first >= last){
                        ans = min(ans, po1[j][now].second);
                        now = po1[j][now].first;
                    }
                }
                dp[i] = min(dp[i], ans + 1);
            }
        }
        po[0][i] = {go[i], dp[go[i]]};
        for (int j = 1; j < 30; j++)
        {
            if (po[j - 1][i].first == -1 || po[j - 1][po[j - 1][i].first].first == -1){
                po[j][i] = {-1, 2e9};
                continue;
            }
            po[j][i] = {po[j - 1][po[j - 1][i].first].first, min(po[j - 1][i].second, po[j - 1][po[j - 1][i].first].second)};
        }
        po1[0][i] = {go1[i], dp[go1[i]]};
        for (int j = 1; j < 30; j++)
        {
            if (po1[j - 1][i].first == -1 || po1[j - 1][po1[j - 1][i].first].first == -1){
                po1[j][i] = {-1, 2e9};
                continue;
            }
            po1[j][i] = {po1[j - 1][po1[j - 1][i].first].first, min(po1[j - 1][i].second, po1[j - 1][po1[j - 1][i].first].second)};
        }
    }
    cout << dp[n - 1];
    return 0;
}