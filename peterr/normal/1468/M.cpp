#include <bits/stdc++.h>

using namespace std;

const int MAXM = 2E5;
const int MAXN = 1E5;
const int SQRT = 450;
vector<int> a[MAXN + 1];
vector<int> where[MAXM];

pair<int, int> solve(int n, int m)
{
    vector<int> member(m, false);
    for (int i = 1; i <= n; i++)
    {
        if ((int) a[i].size() >= SQRT)
        {
            fill(member.begin(), member.end(), false);
            for (int x : a[i])
                member[x] = true;
            for (int j = 1; j <= n; j++)
            {
                if (i == j)
                    continue;
                bool match = false;
                for (int y : a[j])
                {
                    if (member[y])
                    {
                        if (match)
                            return {i, j};
                        match = true;
                    }
                }
            }
        }
    }
    fill(member.begin(), member.end(), false);
    vector<int> used;
    for (int i = 0; i < m; i++)
    {
        if (where[i].empty())
            continue;
        for (int ind : where[i])
        {
            for (int x : a[ind])
            {
                if (x <= i)
                    continue;
                if (member[x])
                    return {member[x], ind};
                member[x] = ind;
                used.push_back(x);
            }
        }
        for (int x : used)
            member[x] = false;
        used.clear();
    }
    return {-1, -1};
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        map<int, int> encode;
        for (int i = 1; i <= n; i++)
        {
            int k;
            cin >> k;
            a[i] = vector<int>(k);
            for (int j = 0; j < k; j++)
            {
                int x;
                cin >> x;
                if (!encode.count(x))
                    encode[x] = (int) encode.size();
                a[i][j] = encode[x];
            }
            sort(a[i].begin(), a[i].end());
            a[i].resize(distance(a[i].begin(), unique(a[i].begin(), a[i].end())));
            /*
            cout << "arr " << i << " ";
            for (int y : a[i])
                cout << y << " ";
            cout << endl;
            */
        }
        for (int i = 0; i < (int) encode.size(); i++)
            where[i].clear();
        for (int i = 1; i <= n; i++)
        {
            if ((int) a[i].size() >= SQRT)
                continue;
            for (int x : a[i])
                where[x].push_back(i);
        }
        pair<int, int> ans = solve(n, (int) encode.size());
        if (ans.first == -1)
            cout << "-1\n";
        else
            cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}