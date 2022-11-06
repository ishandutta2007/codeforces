#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
int a[MAXN];
int ans[MAXN];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    multiset<int> m;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        m.insert(x);
    }
    for (int i = 0; i < n; i++)
    {
        int key = n - a[i];
        auto it = m.lower_bound(key);
        if (it == m.end())
            it = m.lower_bound(0);
        ans[i] = (a[i] + *it) % n;
        m.erase(it);
    }
    for (int i = 0; i < n; i++)
    {
        if (i > 0)
            cout << " ";
        cout << ans[i];
    }
    cout << endl;
    return 0;
}