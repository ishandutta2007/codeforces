#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
const int MAXX = 1E6;
vector<pair<int, int>> bot;
vector<pair<int, int>> top;
vector<pair<int, int>> l;
vector<pair<int, int>> r;
int bit[MAXX + 1];
vector<int> ends2[MAXX + 1];

void inc(int pos, int amt)
{
    while (pos <= MAXX)
    {
        bit[pos] += amt;
        pos += pos & -pos;
    }
}

int query(int pos)
{
    int ans = 0;
    while (pos)
    {
        ans += bit[pos];
        pos -= pos & -pos;
    }
    return ans;
}

long long solve(vector<pair<int, int>> &bottom, vector<pair<int, int>> &lft)
{
    fill(bit, bit + MAXX + 1, 0);
    for (int i = 1; i < MAXX; i++)
    {
        ends2[i].clear();
    }
    for (pair<int, int> pr : bottom)
    {
        int x = pr.first;
        inc(x, 1);
        ends2[pr.second].push_back(x);
    }
    long long ans = 0;
    int ptr = 0;
    sort(lft.begin(), lft.end());
    for (pair<int, int> pr : lft)
    {
        int y = pr.first;
        int x = pr.second;
        while (ptr + 1 < y)
        {
            ptr++;
            for (int pos : ends2[ptr])
            {
                inc(pos, -1);
            }
        }
        ans += query(x);
    }
    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;
    long long ans = 1;
    for (int i = 0; i < n; i++)
    {
        int y, lx, rx;
        cin >> y >> lx >> rx;
        if (lx == 0)
            l.push_back(make_pair(y, rx));
        else
            r.push_back(make_pair(y, lx));
        if (lx == 0 && rx == MAXX)
            ans++;
    }
    for (int i = 0; i < m; i++)
    {
        int x, ly, ry;
        cin >> x >> ly >> ry;
        if (ly == 0)
            bot.push_back(make_pair(x, ry));
        else
            top.push_back(make_pair(x, ly));
        if (ly == 0 && ry == MAXX)
            ans++;
    }
    ans += solve(bot, l);
    for (int i = 0; i < (int) top.size(); i++)
    {
        top[i].second = MAXX - top[i].second;
    }
    for (int i = 0; i < (int) l.size(); i++)
    {
        l[i].first = MAXX - l[i].first;
    }
    ans += solve(top, l);
    for (int i = 0; i < (int) r.size(); i++)
    {
        r[i].second = MAXX - r[i].second;
    }
    for (int i = 0; i < (int) bot.size(); i++)
    {
        bot[i].first = MAXX - bot[i].first;
    }
    ans += solve(bot, r);
    for (int i = 0; i < (int) r.size(); i++)
    {
        r[i].first = MAXX - r[i].first;
    }
    for (int i = 0; i < (int) top.size(); i++)
    {
        top[i].first = MAXX - top[i].first;
    }
    ans += solve(top, r);
    cout << ans << "\n";
    return 0;
}