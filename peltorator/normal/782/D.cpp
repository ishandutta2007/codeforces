#include <bits/stdc++.h>

using namespace std;

typedef double ld;

vector<pair<pair<char, char>, string>> a[26][26];

set<pair<string, int>> qq;
vector<string> ans;
vector<int> used, f;

vector<vector<int>> g, h;

int main()
{
    cout.precision(100);
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s, t;
        cin >> s >> t;
        s += ' ';
        s += t;
        int x = s[0] - 'A';
        int y = s[1] - 'A';
        qq.insert({s, i});
        a[x][y].push_back({{s[2] - 'A', t[0] - 'A'}, s});
    }
    for (int i = 0; i < 26; i++)
        for (int j = 0; j < 26; j++)
            sort(a[i][j].begin(), a[i][j].end());
    ans.resize(n);
    for (int i = 0; i < 26; i++)
        for (int j = 0; j < 26; j++)
        {
            used.assign(26, 0);
            f.assign(a[i][j].size(), 0);
            for (int k = 0; k < a[i][j].size(); k++)
            {
                if ((k > 0 && a[i][j][k - 1].first.first == a[i][j][k].first.first) || (k + 1 < a[i][j].size() && a[i][j][k + 1].first.first == a[i][j][k].first.first))
                {
                    f[k] = 1;
                    if (used[a[i][j][k].first.second])
                    {
                        cout << "NO";
                        return 0;
                    }
                    used[a[i][j][k].first.second] = 1;
                    auto p = qq.lower_bound({a[i][j][k].second, 0});
                    ans[p->second] = {i, j, a[i][j][k].first.second};
                }
            }
            g.assign(a[i][j].size(), {});
            h.assign(26, {});
            queue<int> q;
            for (int k = 0; k < a[i][j].size(); k++)
                if (!f[k])
                {
                    h[a[i][j][k].first.first].push_back(k);
                    h[a[i][j][k].first.second].push_back(k);
                    if (used[a[i][j][k].first.first] && used[a[i][j][k].first.second])
                    {
                        cout << "NO";
                        return 0;
                    }
                    if (used[a[i][j][k].first.first] || used[a[i][j][k].first.second])
                        q.push(k);
                }
            while (!q.empty())
            {
                int k = q.front();
                q.pop();
                if (used[a[i][j][k].first.first] && used[a[i][j][k].first.second])
                {
                    cout << "NO";
                    return 0;
                }
                f[k] = 1;
                if (used[a[i][j][k].first.first])
                {
                    used[a[i][j][k].first.second] = 1;
                    for (int v : h[a[i][j][k].first.second])
                        if (!f[v])
                            q.push(v);
                    auto p = qq.lower_bound({a[i][j][k].second, 0});
                    ans[p->second] = {i, j, a[i][j][k].first.second};
                }
                else
                {
                    used[a[i][j][k].first.first] = 1;
                    for (int v : h[a[i][j][k].first.first])
                        if (!f[v])
                            q.push(v);
                    auto p = qq.lower_bound({a[i][j][k].second, 0});
                    ans[p->second] = {i, j, a[i][j][k].first.first};
                }
            }
            for (int k = 0; k < a[i][j].size(); k++)
                if (!f[k])
                {
                    vector<int> f1, used1;
                    queue<int> q;
                    f[k] = 1;
                    f1.push_back(k);
                    for (int v : h[a[i][j][k].first.first])
                        if (!f[v])
                            q.push(v);
                    used1.push_back(a[i][j][k].first.first);
                    used[a[i][j][k].first.first] = 1;
                    bool ok = true;
                    while (!q.empty())
                    {
                        int k = q.front();
                        q.pop();
                        if (used[a[i][j][k].first.first] && used[a[i][j][k].first.second])
                        {
                            ok = false;
                            break;
                        }
                        f1.push_back(k);
                        f[k] = 1;
                        if (used[a[i][j][k].first.first])
                        {
                            used[a[i][j][k].first.second] = 1;
                            used1.push_back(a[i][j][k].first.second);
                            for (int v : h[a[i][j][k].first.second])
                                if (!f[v])
                                    q.push(v);
                            auto p = qq.lower_bound({a[i][j][k].second, 0});
                            ans[p->second] = {i, j, a[i][j][k].first.second};
                        }
                        else
                        {
                            used[a[i][j][k].first.first] = 1;
                            used1.push_back(a[i][j][k].first.first);
                            for (int v : h[a[i][j][k].first.first])
                                if (!f[v])
                                    q.push(v);
                            auto p = qq.lower_bound({a[i][j][k].second, 0});
                            ans[p->second] = {i, j, a[i][j][k].first.first};
                        }
                    }
                    if (ok)
                    {
                        auto p = qq.lower_bound({a[i][j][k].second, 0});
                            ans[p->second] = {i, j, a[i][j][k].first.first};
                        continue;
                    }
                    for (int v : f1)
                        f[v] = 0;
                    for (int u : used1)
                        used[u] = 0;
                    f1.clear();
                    used1.clear();
                    while (!q.empty())
                        q.pop();
                    f[k] = 1;
                    f1.push_back(k);
                    for (int v : h[a[i][j][k].first.second])
                        if (!f[v])
                            q.push(v);
                    used1.push_back(a[i][j][k].first.second);
                    used[a[i][j][k].first.second] = 1;
                    ok = true;
                    while (!q.empty())
                    {
                        int k = q.front();
                        q.pop();
                        if (used[a[i][j][k].first.first] && used[a[i][j][k].first.second])
                        {
                            ok = false;
                            break;
                        }
                        f1.push_back(k);
                        f[k] = 1;
                        if (used[a[i][j][k].first.first])
                        {
                            used[a[i][j][k].first.second] = 1;
                            used1.push_back(a[i][j][k].first.second);
                            for (int v : h[a[i][j][k].first.second])
                                if (!f[v])
                                    q.push(v);
                            auto p = qq.lower_bound({a[i][j][k].second, 0});
                            ans[p->second] = {i, j, a[i][j][k].first.second};
                        }
                        else
                        {
                            used[a[i][j][k].first.first] = 1;
                            used1.push_back(a[i][j][k].first.first);
                            for (int v : h[a[i][j][k].first.first])
                                if (!f[v])
                                    q.push(v);
                            auto p = qq.lower_bound({a[i][j][k].second, 0});
                            ans[p->second] = {i, j, a[i][j][k].first.first};
                        }
                    }
                    if (!ok)
                    {
                        cout << "NO";
                        return 0;
                    }
                    auto p = qq.lower_bound({a[i][j][k].second, 0});
                    ans[p->second] = {i, j, a[i][j][k].first.second};
                }
        }
    cout << "YES" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
            cout << (char)(ans[i][j] + 'A');
        cout << endl;
    }
    return 0;
}