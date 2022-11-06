#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, d;
        cin >> n >> d;
        vector<int> v;
        bool good = true;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            v.push_back(x);
            if (x > d)
                good = false;
        }
        sort(v.begin(), v.end());
        good |= v[0] + v[1] <= d;
        if (good)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}