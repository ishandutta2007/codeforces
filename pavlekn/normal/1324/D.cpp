#include <bits/stdc++.h>

using namespace std;

#include<ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> b[i];
        a[i] -= b[i];
    }
    int ans = 0;
    ordered_set ss;
    for (int i = 0; i < n; ++i)
    {
        ans += ss.order_of_key({a[i], -1});
        ss.insert({-a[i], i});
    }
    cout << ans << endl;
    return 0;
}