#include <bits/stdc++.h>

using namespace std;

void nxt(int ind, char dir, int m, int &ans1)
{
    ans1 = ind;
    if (dir == 'U')
        ans1 -= m;
    else if (dir == 'R')
        ans1++;
    else if (dir == 'L')
        ans1--;
    else
        ans1 += m;
}

int compress(int r, int c, int m)
{
    return r * m + c;
}

void solve(int m, int ind, vector<int> &visited, vector<char> &board, vector<vector<bool>> &good, vector<bool> &isBlack, vector<pair<int, int>> &pos, int cnt)
{
    int ind2;
    nxt(ind, board[ind], m, ind2);
    if (visited[ind] == -1)
    {
        int comp = pos[ind].first;
        int s = (int) good[comp].size();
        pos[ind] = make_pair(comp, (pos[ind2].second - 1 + s) % s);
        if (isBlack[ind])
            good[comp][pos[ind].second] = true;
        visited[ind] = -1;
    }
    if (visited[ind] == 2 || visited[ind] == -1)
        return;
    if (visited[ind] == 1)
    {
        pos[ind] = make_pair(cnt, (int) good[cnt].size());
        good[cnt].push_back(isBlack[ind]);
    }
    if (visited[ind] == 1 || visited[ind] == 0)
        visited[ind]++;
    solve(m, ind2, visited, board, good, isBlack, pos, cnt);
    if (visited[ind] == 1)
    {
        int comp = pos[ind2].first;
        int s = (int) good[comp].size();
        pos[ind] = make_pair(comp, (pos[ind2].second - 1 + s) % s);
        if (isBlack[ind])
            good[comp][pos[ind].second] = true;
        visited[ind] = -1;
    }
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
        vector<bool> isBlack(n * m);
        vector<char> board(n * m);
        vector<int> visited(n * m);
        vector<pair<int, int>> pos(n * m);
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            for (int j = 0; j < m; j++)
                isBlack[compress(i, j, m)] = s[j] == '0';
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cin >> board[compress(i, j, m)];
        }
        vector<vector<bool>> good;
        int cnt = 0;
        good.push_back(vector<bool>());
        int ans1 = 0;
        for (int i = 0; i < n * m; i++)
        {
                if (visited[i] == 0)
                {
                    solve(m, i, visited, board, good, isBlack, pos, cnt);
                    if (!good[cnt].empty())
                    {
                        ans1 += (int) good[cnt].size();
                        cnt++;
                        good.push_back(vector<bool>());
                    }
                }
        }
        int ans = 0;
        for (int i = 0; i < (int) good.size(); i++)
        {
            for (bool b : good[i])
                ans += b;
        }
        cout << ans1 << " " << ans << "\n";
    }
    return 0;
}