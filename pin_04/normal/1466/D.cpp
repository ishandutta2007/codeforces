#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("file.inp","r",stdin);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector <int> a(n);
        vector <int> deg(n, 0);
        for (int &x : a)
            cin >> x;

        unsigned long long sum = 0;

        for (int x : a)
            sum += x;

        for (int i = 1; i < n; i++)
        {
            int u,v;
            cin >> u >> v;
            u--;
            v--;
            deg[u]++;
            deg[v]++;
        }

        vector <int> s(0);

        for (int i = 0; i < n; i++)
        for (int j = 1; j < deg[i]; j++)
        {
            s.push_back(a[i]);
        }
        sort(s.begin(), s.end(), greater <int> ());

        for (int x : s)
        {
            cout << sum << " ";
            sum += x;
        }
        cout << sum << "\n";
    }
    return 0;
}