#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200;
string a[MAXN + 1];

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            a[i] = "#" + a[i];
        }
        vector<pair<int, int>> v1, v2;
        if (a[1][2] == '1')
            v1.push_back(make_pair(1, 2));
        else
            v2.push_back(make_pair(1, 2));
        if (a[2][1] == '1')
            v1.push_back(make_pair(2, 1));
        else
            v2.push_back(make_pair(2, 1));

        if (a[n][n - 1] == '0')
            v1.push_back(make_pair(n, n - 1));
        else
            v2.push_back(make_pair(n, n - 1));
        if (a[n - 1][n] == '0')
            v1.push_back(make_pair(n - 1, n));
        else
            v2.push_back(make_pair(n - 1, n));
        if (v1.size() > v2.size())
            swap(v1, v2);
        cout << (int) v1.size() << "\n";
        for (pair<int, int> pr : v1)
        {
            cout << pr.first << " " << pr.second << "\n";
        }
    }
    return 0;
}