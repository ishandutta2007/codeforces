#include<bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 2e5 + 7;
int INF = 3e16;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int _ = 0; _ < t; ++_)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        int sum = 0;
        int xx = 0;
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
            xx ^= a[i];
            sum += a[i];
        }
        if ((sum + INF) % 2ll)
        {
            ++INF;
        }
        xx ^= INF;
        sum += INF;
        xx *= 2ll;
        cout << 3 << endl;
        cout << INF << " " << (xx - sum) / 2ll << " " << (xx - sum) / 2ll << endl;
    }
    return 0;
}