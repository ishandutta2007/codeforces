#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
vector<int> groups[MAXN + 2];
int a[MAXN + 1];
int translate[MAXN + 1];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    int good = 0;
    for (int i = 1; i <= m; i++)
    {
        translate[i] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        int t;
        cin >> t;
        a[i] = t;
        groups[t].push_back(i);
        if (a[i - 1] == t)
            good++;
    }
    cout << n - 1 - good << "\n";
    for (int i = 0; i < m - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        int x2 = translate[x];
        int y2 = translate[y];
        if (groups[x2].size() < groups[y2].size())
        {
            swap(x2, y2);
        }
        for (int b : groups[y2])
        {
            if (a[b - 1] == x2)
                good++;
            if (a[b + 1] == x2)
                good++;
            groups[x2].push_back(b);
            //a[b] = x2;
        }
        translate[x] = x2;
        for (int b : groups[y2])
        {
            a[b] = x2;
        }
        /*
        for (int i = 1; i <= n; i++)
        {
            cout << "key: " << i << " " << a[i] << "\n";
        }
        for (int i = 1; i <= m; i++)
        {
            cout << "t: " << i << " " << translate[i] << "\n";
        }
        */
        cout << n - 1 - good << "\n";
    }
    return 0;
}