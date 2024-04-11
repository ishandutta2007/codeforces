#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> used;
vector<pair<int, int>> a, b, ans;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    a.resize(n - 1);
    int x;
    cin >> x;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> a[i].first;
        a[i].second = i + 2;
    }
    sort(a.rbegin(), a.rend());
    int last = -1;
    b.push_back({x, 1});
    for (int i = 0; i < b.size(); i++)
    {
        for (int j = last + 1; j <= min(n - 2, last + b[i].first); j++)
        {
            ans.push_back({b[i].second, a[j].second});
            b.push_back(a[j]);
        }
        last += b[i].first;
    }
    if (last < n - 2)
    {
        cout << -1;
        return 0;
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i].first << " " << ans[i].second << endl;
    return 0;
}