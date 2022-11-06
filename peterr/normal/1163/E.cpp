#include <bits/stdc++.h>

using namespace std;

const int MAXX = 18;
const int MAXN = 2E5;
int a[MAXN];
bool valid[1 << MAXX];
vector<int> base;
vector<int> ans;

bool check(int k, int n)
{
    int big = 1 << k;
    fill(valid, valid + big, true);
    base.clear();
    valid[0] = false;
    for (int i = 0; i < n; i++)
    {
        int x = a[i];
        if (x >= big)
            continue;
        if (!valid[x])
            continue;
        base.push_back(x);
        vector<int> v;
        for (int i = 0; i < big; i++)
        {
            if (!valid[i])
                v.push_back(i ^ x);
        }
        for (int y : v)
            valid[y] = false;
    }
    return (int) base.size() == k;
}

void solve(int ind)
{
    if (ind < 0)
        return;
    if (ind == 0)
    {
        ans.push_back(ans.back() ^ base[ind]);
        return;
    }
    solve(ind - 1);
    ans.push_back(ans.back() ^ base[ind]);
    solve(ind - 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int x = MAXX;
    while (!check(x, n))
        x--;
    ans.push_back(0);
    solve(x - 1);
    cout << x << "\n";
    for (int i = 0; i < (int) ans.size(); i++)
    {
        cout << ans[i] << " \n"[i == (int) ans.size() - 1];
    }
    return 0;
}