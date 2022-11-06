#include <bits/stdc++.h>

using namespace std;

const int MOD = 1E9 + 7;
const int MAXN = 2E5;
pair<int, int> dolls[MAXN + 1];
int dp[MAXN + 1];
int ways[MAXN + 1];
int pre[MAXN + 1];
pair<int, int> seg[2 * MAXN + 2];

int add(int a, int b)
{
    a += b;
    if (a >= MOD)
        return a - MOD;
    return a;
}

pair<int, int> query(int l, int r)
{
    l += MAXN + 1;
    r += MAXN + 1;
    pair<int, int> ans = make_pair(seg[l].first, 0);
    while (l <= r)
    {
        if (l & 1)
        {
            if (seg[l].first == ans.first)
                ans.second = add(ans.second, seg[l].second);
            else if (seg[l].first < ans.first)
                ans = seg[l];
            l++;
        }
        if (~r & 1)
        {
            if (seg[r].first == ans.first)
                ans.second = add(ans.second, seg[r].second);
            else if (seg[r].first < ans.first)
                ans = seg[r];
            r--;
        }
        l >>= 1;
        r >>= 1;
    }
    return ans;
}

void upd(int pos, int x, int w)
{
    pos += MAXN + 1;
    seg[pos] = make_pair(x, w);
    pos >>= 1;
    while (pos)
    {
        if (seg[pos * 2].first == seg[pos * 2 + 1].first)
            seg[pos] = make_pair(seg[pos * 2].first, add(seg[pos * 2].second, seg[pos * 2 + 1].second));
        else if (seg[pos * 2].first < seg[pos * 2 + 1].first)
            seg[pos] = seg[pos * 2];
        else
            seg[pos] = seg[pos * 2 + 1];
        pos >>= 1;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i < 2 * MAXN + 2; i++)
        seg[i] = make_pair(2E9 + 100, 0);
    for (int i = 1; i <= n; i++)
        cin >> dolls[i].first >> dolls[i].second;
    sort(dolls + 1, dolls + n + 1);
    dp[0] = 0;
    ways[0] = 1;
    pre[1] = dolls[1].second;
    for (int i = 2; i <= n; i++)
        pre[i] = max(pre[i - 1], dolls[i].second);
    for (int i = 1; i <= n; i++)
    {
        int ind = 0;
        for (int jump = n / 2 + 1; jump > 0; jump /= 2)
        {
            while (ind + jump < i && dolls[ind + jump].first <= dolls[i].second)
                ind += jump;
        }
        int bound = pre[ind];
        int left = 0;
        for (int jump = n / 2 + 1; jump > 0; jump /= 2)
        {
            while (left + jump < i && dolls[left + jump].first <= bound)
                left += jump;
        }
        left++;
        int right = 0;
        for (int jump = n / 2 + 1; jump > 0; jump /= 2)
        {
            while (right + jump < i && dolls[right + jump].first <= dolls[i].second)
                right += jump;
        }
        if (right < left)
        {
            dp[i] = dolls[i].second - dolls[i].first;
            ways[i] = 1;
        }
        else
        {
            pair<int, int> q = query(left, right);
            dp[i] = q.first + (dolls[i].second - dolls[i].first);
            ways[i] = q.second;
        }
        upd(i, dp[i], ways[i]);
    }
    int sp = 2E9 + 5;
    int ans = 0;
    for (int i = n; i >= 1 && dolls[i].first > pre[n]; i--)
    {
        int waste = dp[i] + dolls[i].first;
        if (waste < sp)
        {
            sp = waste;
            ans = ways[i];
        }
        else if (waste == sp)
        {
            ans = add(ans, ways[i]);
        }
    }
    cout << ans << endl;
    return 0;
}