#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100;
string board[MAXN];

void flip(int i, int j)
{
    if (board[i][j] == '1')
        board[i][j] = '0';
    else
        board[i][j] = '1';
}

void doFlips(vector<pair<int, int>> &v)
{
    int s = (int) v.size();
    for (int i = 0; i < 3; i++)
    {
        int r = v[s - 1 - i].first;
        int c = v[s - 1 - i].second;
        flip(r, c);
    }
}

bool dfs(vector<pair<int, int>> &v, int d, int n, int m)
{
    bool valid = true;
    for (int i = n - 2; i <= n - 1; i++)
    {
        for (int j = m - 2; j <= m - 1; j++)
        {
            if (board[i][j] == '1')
                valid = false;
        }
    }
    if (valid)
        return true;
    if (d > 4)
        return false;
    v.push_back(make_pair(n - 1, m - 1));
    v.push_back(make_pair(n - 2, m - 1));
    v.push_back(make_pair(n - 1, m - 2));
    doFlips(v);
    if (dfs(v, d + 1, n, m))
        return true;
    doFlips(v);
    v.pop_back();
    v.pop_back();
    v.pop_back();
    v.push_back(make_pair(n - 2, m - 1));
    v.push_back(make_pair(n - 2, m - 2));
    v.push_back(make_pair(n - 1, m - 1));
    doFlips(v);
    if (dfs(v, d + 1, n, m))
        return true;
    doFlips(v);
    v.pop_back();
    v.pop_back();
    v.pop_back();
    v.push_back(make_pair(n - 2, m - 2));
    v.push_back(make_pair(n - 2, m - 1));
    v.push_back(make_pair(n - 1, m - 2));
    doFlips(v);
    if (dfs(v, d + 1, n, m))
        return true;
    doFlips(v);
    v.pop_back();
    v.pop_back();
    v.pop_back();
    v.push_back(make_pair(n - 1, m - 2));
    v.push_back(make_pair(n - 2, m - 2));
    v.push_back(make_pair(n - 1, m - 1));
    doFlips(v);
    if (dfs(v, d + 1, n, m))
        return true;
    doFlips(v);
    v.pop_back();
    v.pop_back();
    v.pop_back();
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            cin >> board[i];
        }
        vector<pair<int, int>> ans;
        for (int i = 0; i < n - 2; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == '1')
                {
                    ans.push_back(make_pair(i, j));
                    ans.push_back(make_pair(i + 1, j));
                    if (j < m - 1)
                        ans.push_back(make_pair(i + 1, j + 1));
                    else
                        ans.push_back(make_pair(i + 1, j - 1));
                    doFlips(ans);
                }
            }
        }
        for (int i = 0; i < m - 2; i++)
        {
            char c1 = board[n - 2][i];
            char c2 = board[n - 1][i];
            if (c1 == '1' && c2 == '1')
            {
                ans.push_back(make_pair(n - 1, i));
                ans.push_back(make_pair(n - 2, i));
                ans.push_back(make_pair(n - 2, i + 1));
                doFlips(ans);
            }
            else if (c1 == '1')
            {
                ans.push_back(make_pair(n - 2, i));
                ans.push_back(make_pair(n - 1, i + 1));
                ans.push_back(make_pair(n - 2, i + 1));
                doFlips(ans);
            }
            else if (c2 == '1')
            {
                ans.push_back(make_pair(n - 1, i));
                ans.push_back(make_pair(n - 1, i + 1));
                ans.push_back(make_pair(n - 2, i + 1));
                doFlips(ans);
            }
        }
        dfs(ans, 1, n, m);
        cout << (int) ans.size() / 3 << "\n";
        for (int i = 0; i < (int) ans.size(); i += 3)
        {
            for (int j = 0; j < 3; j++)
            {
                int r = ans[i + j].first + 1;
                int c = ans[i + j].second + 1;
                cout << r << " " << c << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}