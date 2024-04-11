#include <bits/stdc++.h>

using namespace std;

const long long INF = 1E18 + 5;
const int MAXN = 3E4;
const int MAXC = 4;
const int MAXQ = 3E5;
long long dp[MAXN + 1][MAXC + 1];
long long skip[MAXN][MAXC + 1];
int p[MAXN];
vector<pair<int, int>> swaps;
long long cnt = 0;

long long querySkip(int l, int r, int c)
{
    return skip[r][c] - (l ? skip[l - 1][c] : 0);
}

int clamp(int x, int lo, int hi)
{
    if (x < lo)
        return lo;
    if (x > hi)
        return hi;
    return x;
}

int getElement(int pos)
{
    for (pair<int, int> pr : swaps)
    {
        if (clamp(pos, pr.first, pr.second) == pos)
        {
            pos = pr.second - (pos - pr.first);
            break;
        }
    }
    return p[pos];
}

int solve(int ind, long long k, int pos, int c, int n)
{
    cnt++;
    if (pos >= n)
    {
        return getElement(ind);
    }
    if (querySkip(pos, pos, c) <= k && querySkip(pos, pos, c) + dp[n - pos - 1][c] > k)
    {
        int newpos = pos;
        for (int jump = n; jump; jump >>= 1)
        {
            while (newpos + jump < n && querySkip(pos, newpos + jump, c) <= k && querySkip(pos, newpos + jump, c) + dp[n - (newpos + jump) - 1][c] > k)
                newpos += jump;
        }
        return solve(ind, k - querySkip(pos, newpos, c), newpos + 1, c, n);
    }
    vector<pair<int, int>> candidates;
    for (int i = 0; i <= c && i + pos < n; i++)
    {
        candidates.push_back({p[pos + i], pos + i});
    }
    sort(candidates.begin(), candidates.end());
    for (pair<int, int> pr : candidates)
    {
        int newc = c - (pr.second - pos);
        long long num = dp[n - pr.second - 1][newc];
        if (k < num)
        {
            if (pr.second != pos)
                swaps.push_back({pos, pr.second});
            return solve(ind, k, pr.second + 1, newc, n);
        }
        k -= num;
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    fill(dp[0], dp[0] + MAXC + 1, 1);
    for (int i = 1; i <= MAXN; i++)
    {
        for (int j = 0; j <= MAXC; j++)
        {
            dp[i][j] = dp[i - 1][j];
            for (int k = 1; k + 1 <= i && k <= j; k++)
            {
                dp[i][j] += dp[i - k - 1][j - k];
            }
            dp[i][j] = min(dp[i][j], INF);
            //cout << i << " " << j << " " << dp[i][j] << endl;
        }
    }
    int t;
    cin >> t;
    while (t--)
    {
        int n, c, q;
        cin >> n >> c >> q;
        for (int i = 0; i < n; i++)
        {
            cin >> p[i];
        }
        vector<bool> smaller(c + 1);
        for (int i = 0; i < n; i++)
        {
            fill(smaller.begin(), smaller.end(), false);
            for (int j = 1; j <= c; j++)
            {
                skip[i][j] = i ? skip[i - 1][j] : 0;
                if (i + j < n && p[i + j] < p[i])
                    smaller[j] = true;
                for (int z = 1; z <= j; z++)
                {
                    if (!smaller[z])
                        continue;
                    skip[i][j] += dp[n - i - z - 1][j - z];
                }
                //cout << "skip " << i << " " << j << " " << skip[i][j] << endl;
            }
        }
        for (int i = 0; i < q; i++)
        {
            swaps.clear();
            int pos;
            long long k;
            cin >> pos >> k;
            k--;
            pos--;
            if (k < dp[n][c])
                cout << solve(pos, k, 0, c, n) << "\n";
            else
                cout << "-1\n";
        }
        //cout << "cnt " << cnt << endl;
    }
    return 0;
}