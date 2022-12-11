#include<bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    map<int, int> used;
    int j = n;
    while (j > 0 && !used[a[j - 1]])
    {
        ++used[a[j - 1]];
        --j;
    }
    int ans = j;
    for (int i = 0; i < n; ++i)
    {
        while (j < n && used[a[i]])
        {
            --used[a[j]];
            ++j;
        }
        if (used[a[i]])
        {
            break;
        }
        else
        {
            ++used[a[i]];
            ans = min(ans, j - i - 1);
        }
    }
    cout << ans << endl;
}