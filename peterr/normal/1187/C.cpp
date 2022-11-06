#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000;
int a[MAXN];
vector<pair<int, int>> o;
vector<pair<int, int>> z;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int t, l, r;
        cin >> t >> l >> r;
        l--;
        r--;
        if (t)
            o.push_back(make_pair(l, r));
        else
            z.push_back(make_pair(l, r));
    }
    sort(o.begin(), o.end());
    int cur = n;
    int right = 0;
    int p = 0;
    for (int i = 0; i < n; i++)
    {
        while (right < i && p < (int) o.size() && o[p].first <= right)
        {
            right = max(right, o[p].second);
            p++;
        }
        if (right >= i)
            a[i] = cur;
        else
        {
            a[i] = --cur;
            right = i;
        }
    }
    bool ans = true;
    for (pair<int, int> pr : z)
    {
        bool flag = false;
        int l = pr.first;
        int r = pr.second;
        for (int i = l; i < r; i++)
        {
            if (a[i] > a[i + 1])
                flag = true;
        }
        if (!flag)
            ans = false;
    }
    if (ans)
    {
        cout << "YES\n";
        for (int i = 0; i < n; i++)
            cout << a[i] << " \n"[i == n - 1];
    }
    else
        cout << "NO\n";
    return 0;
}