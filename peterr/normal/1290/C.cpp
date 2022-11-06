#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3E5;
vector<int> switches[MAXN];
int parent[2 * MAXN];
int s[2 * MAXN];
bool valid[2 * MAXN];
int cost[2 * MAXN];

int getRoot(int x)
{
    if (parent[x] != x)
        parent[x] = getRoot(parent[x]);
    return parent[x];
}

void mge(int a, int b)
{
    int r1 = getRoot(a);
    int r2 = getRoot(b);
    if (r1 == r2)
        return;
    if (s[r1] > s[r2])
        swap(r1, r2);
    parent[r1] = r2;
    s[r2] += s[r1];
    valid[r2] &= valid[r1];
    cost[r2] += cost[r1];
}

int getCost(int r)
{
    if (valid[r])
        return cost[r];
    return 10 * MAXN;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    string lamps;
    cin >> n >> k >> lamps;
    for (int i = 0; i < 2 * k; i++)
    {
        parent[i] = i;
        s[i] = 1;
        valid[i] = true;
        cost[i] = i & 1;
    }
    for (int i = 0; i < k; i++)
    {
        int c;
        cin >> c;
        for (int j = 0; j < c; j++)
        {
            int x;
            cin >> x;
            x--;
            switches[x].push_back(i);
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int numSwitches = (int) switches[i].size();
        if (numSwitches == 0)
            cout << ans << "\n";
        else if (numSwitches == 1)
        {
            int a = switches[i][0];
            int r1 = getRoot(2 * a);
            int r2 = getRoot(2 * a + 1);
            if (lamps[i] == '1')
                swap(r1, r2);
            if (valid[r1])
            {
                valid[r1] = false;
                if (cost[r1] < cost[r2])
                {
                    ans += cost[r2] - cost[r1];
                }
            }
            cout << ans << "\n";
        }
        else
        {
            int a = switches[i][0];
            int b = switches[i][1];
            int a0 = getRoot(2 * a);
            int a1 = getRoot(2 * a + 1);
            int b0 = getRoot(2 * b);
            int b1 = getRoot(2 * b + 1);
            if (lamps[i] == '1')
                swap(b1, b0);
            if (a0 == b1)
                cout << ans << "\n";
            else
            {
                ans -= min(getCost(a0), getCost(a1));
                ans -= min(getCost(b0), getCost(b1));
                mge(a0, b1);
                mge(a1, b0);
                ans += min(getCost(getRoot(a0)), getCost(getRoot(a1)));
                cout << ans << "\n";
            }
        }
    }
    return 0;
}