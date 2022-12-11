#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

vector<pair<int, int>> ans;

vector<int> a;
vector<int> pos;
int n;

void ch(int i, int j)
{
    if (i == j)
    {
        return;
    }
    swap(a[i], a[j]);
    swap(pos[a[i]], pos[a[j]]);
    ans.push_back({i + 1, j + 1});
    return;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    a.resize(n);
    pos.resize(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        --a[i];
        pos[a[i]] = i;
    }
    for (int i = 0; i < n; ++i)
    {
        if (i == pos[i])
        {
            continue;
        }
        int j = pos[i];
        if (i == 0 && j == n - 1)
        {
            ch(0, n - 1);
            continue;
        }
        else if (i == 0)
        {
            if (j * 2 >= n)
            {
                ch(0, j);
            }
            else
            {
                ch(j, n - 1);
                ch(0, n - 1);
            }
            continue;
        }
        else if (j == n - 1)
        {
            if ((n - i - 1) * 2 >= n)
            {
                ch(i, j);
            }
            else
            {
                ch(0, j);
                ch(0, i);
                ch(0, n - 1);
            }
            continue;
        }
            if (j * 2 >= n)
            {
                if (j != 0)
                {
                    ch(0, j);
                }
                if (i * 2 >= n)
                {
                    ch(0, i);
                    ch(0, j);
                }
                else
                {
                    ch(0, n - 1);
                    ch(i, n - 1);
                    ch(0, j);
                }
            }
            else
            {
                if (j != n - 1)
                {
                    ch(j, n - 1);
                }
                if ((n - i - 1) * 2 >= n)
                {
                    ch(i, n - 1);
                    ch(j, n - 1);
                }
                else
                {
                    ch(0, n - 1);
                    ch(0, i);
                    ch(j, n - 1);
                }
            }
    }
    cout << ans.size() << endl;
    for (auto el : ans)
    {
        cout << el.first << " " << el.second << "\n";
    }
    cout << endl;
    return 0;
}