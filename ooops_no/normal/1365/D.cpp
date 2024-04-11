#include<vector>
#include<map>
#include<algorithm>
#include<set>
#include<iostream>
#include<string>
#include<set>
#include<queue>
#include<random>
//#include<unordered_set>

using namespace std;

/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> st;*/

#pragma GCC optimize("Ofast")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")

#define pb push_back
#define ld long double
#define int long long

mt19937 rnd(51);

int n, m;
char v[60][60];

bool check(int i, int j)
{
    return i >= 0 && i < n && j >= 0 && j < m && (v[i][j] == '.' || v[i][j] == '#');
}

bool check1(int i, int j)
{
    return i >= 0 && i < n && j >= 0 && j < m;
}

void solve()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] == 'B')
            {
                if (check(i - 1, j))
                {
                    v[i - 1][j] = '#';
                }
                if (check(i + 1, j))
                {
                    v[i + 1][j] = '#';
                }
                if (check(i, j + 1))
                {
                    v[i][j + 1] = '#';
                }
                if (check(i, j - 1))
                {
                    v[i][j - 1] = '#';
                }
            }
        }
    }
    vector<vector<bool>> used(n, vector<bool> (m));
    if (v[n - 1][m - 1] != '#')
    {
        deque<pair<int,int>> q;
        q.push_back({n - 1, m - 1});
        while(!q.empty())
        {
            int i = q.front().first, j = q.front().second;
            q.pop_front();
            used[i][j] = 1;
            if (check1(i - 1, j) && !used[i - 1][j] && v[i - 1][j] != '#')
            {
                used[i - 1][j] = 1;
                q.push_back({i - 1, j});
            }
            if (check1(i + 1, j) && !used[i + 1][j] && v[i + 1][j] != '#')
            {
                used[i + 1][j] = 1;
                q.push_back({i + 1, j});
            }
            if (check1(i, j - 1) && !used[i][j - 1] && v[i][j - 1] != '#')
            {
                used[i][j - 1] = 1;
                q.push_back({i, j - 1});
            }
            if (check1(i, j + 1) && !used[i][j + 1] && v[i][j + 1] != '#')
            {
                used[i][j + 1] = 1;
                q.push_back({i, j + 1});
            }
        }
    }
    bool x = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] == 'B' && used[i][j])
            {
                x = 0;
            }
            if (v[i][j] == 'G' && !used[i][j])
            {
                x = 0;
            }
        }
    }
    if (x)
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}