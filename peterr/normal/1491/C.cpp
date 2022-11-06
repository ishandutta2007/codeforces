#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5000;
int a[MAXN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        set<int> s;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] > 1)
                s.insert(i);
        }
        /*
        cout << "SET" << endl;
        for (int x : s)
            cout << x << endl;
        */
        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += max(0, a[i] - n);
            a[i] = min(a[i], n);
            while (a[i] > 1)
            {
                ans++;
                int j = i;
                while (j < n)
                {
                    int old = j;
                    auto it = s.lower_bound(j + a[j]);
                    a[old] = max(1, a[old] - 1);
                    if (a[old] == 1)
                        s.erase(old);
                    if (it == s.end())
                        break;
                    j = *it;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}