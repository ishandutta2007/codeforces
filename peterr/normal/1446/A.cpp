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
        int n;
        long long w;
        cin >> n >> w;
        vector<int> v;
        long long cur = 0;
        for (int i = 1; i <= n; i++)
        {
            int x;
            cin >> x;
            if (x >= (w + 1) / 2 && x <= w)
            {
                cur = x;
                v.clear();
                v.push_back(i);
            }
            else if (x <= w && cur + x <= w)
            {
                cur += x;
                v.push_back(i);
            }
        }
        if (cur >= (w + 1) / 2)
        {
            cout << (int) v.size() << "\n";
            for (int x : v)
                cout << x << " ";
            cout << "\n";
        }
        else
            cout << "-1\n";
    }
    return 0;
}