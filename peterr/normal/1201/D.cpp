#include <bits/stdc++.h>

using namespace std;

const long long INF = 1E18 + 5;
const int MAXN = 2E5;
pair<int, int> tre[MAXN + 1];
vector<pair<int, long long>> dp[MAXN + 1];
int cols[MAXN];
int n;
int lastRow = 0;

void insertt(pair<int, long long> p, vector<pair<int, long long>> &v)
{
    bool found = false;
    for (int i = 0; i < v.size(); i++)
    {
        if (p.first == v[i].first)
        {
            found = true;
            v[i].second = min(v[i].second, p.second);
        }
    }
    if (!found)
        v.push_back(p);
}

int dist(int row, int startCol, int endCol, bool lastt)
{
    int ans = abs(startCol - tre[row].first) + (tre[row].second - tre[row].first) + !lastt * abs(tre[row].second - endCol);
    ans = min(ans, abs(startCol - tre[row].second) + (tre[row].second - tre[row].first) + !lastt * abs(tre[row].first - endCol));
    return ans;
}

void update(int row, int col)
{
    long long ans = INF;
    for (pair<int, long long> p : dp[row - 1])
    {
        ans = min(ans, p.second + 1 + dist(row, p.first, col, row == lastRow));
    }
    insertt({col, ans}, dp[row]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m, k, q;
    cin >> n >> m >> k >> q;
    for (int i = 1; i <= n; i++)
    {
        tre[i].first = m + 1;
        tre[i].second = 0;
    }
    for (int i = 0; i < k; i++)
    {
        int r, c;
        cin >> r >> c;
        tre[r].first = min(tre[r].first, c);
        tre[r].second = max(tre[r].second, c);
        lastRow = max(lastRow, r);
    }
    for (int i = 0; i < q; i++)
    {
        cin >> cols[i];
    }
    sort(cols, cols + q);
    int curRow = 1;
    /*
    while (tre[curRow].second == 0)
    {
        dp[curRow].push_back({cols[0], cols[0] + curRow - 2});
        curRow++;
    }
    */
    if (tre[curRow].second == 0)
        dp[curRow].push_back({cols[0], cols[0] + curRow - 2});
    else
    {
        int right = tre[curRow].second;
        int index = lower_bound(cols, cols + q, right) - cols;
        if (index < q)
            insertt({cols[index], right + (curRow != lastRow) * abs(right - cols[index]) - 1}, dp[curRow]);
        if (index == q || (index - 1 >= 0 && cols[index] != right))
            insertt({cols[index - 1], right + (curRow != lastRow) * abs(right - cols[index - 1]) - 1}, dp[curRow]);
    }
    curRow++;
    while (curRow <= n)
    {
        if (tre[curRow].second == 0)
        {
            for (pair<int, long long> p : dp[curRow - 1])
            {
                dp[curRow].push_back({p.first, p.second + 1});
            }
        }
        else
        {
            int left = tre[curRow].first;
            int right = tre[curRow].second;
            int index = lower_bound(cols, cols + q, left) - cols;
            if (index < q)
                update(curRow, cols[index]);
            if (index == q || (index - 1 >= 0 && cols[index] != left))
                update(curRow, cols[index - 1]);
            index = lower_bound(cols, cols + q, right) - cols;
            if (index < q)
                update(curRow, cols[index]);
            if (index == q || (index - 1 >= 0 && cols[index] != right))
                update(curRow, cols[index - 1]);
        }
        curRow++;
    }
    /*
    cout << "test" << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << "row "  << i << endl;
        for (pair<int, long long> p : dp[i])
        {
            cout << p.first << " " << p.second << endl;
        }
    }
    */
    long long ans = INF;
    for (pair<int, long long> p : dp[lastRow])
        ans = min(ans, p.second);
    cout << ans << endl;
    return 0;
}