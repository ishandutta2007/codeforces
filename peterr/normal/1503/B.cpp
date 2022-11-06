#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> a;
    vector<pair<int, int>> b;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if ((i + j) & 1)
                a.push_back({i, j});
            else
                b.push_back({i, j});
        }
    }
    while (a.size() && b.size())
    {
        int q;
        cin >> q;
        if (q != 1)
        {
            cout << "1 " << a.back().first << " " << a.back().second << endl;
            a.pop_back();
        }
        else
        {
            cout << "2 " << b.back().first << " " << b.back().second << endl;
            b.pop_back();
        }
    }
    while (a.size())
    {
        int q;
        cin >> q;
        if (q != 1)
            cout << "1 ";
        else
            cout << "3 ";
        cout << a.back().first << " " << a.back().second << endl;
        a.pop_back();
    }
    while (b.size())
    {
        int q;
        cin >> q;
        if (q != 2)
            cout << "2 ";
        else
            cout << "3 ";
        cout << b.back().first << " " << b.back().second << endl;
        b.pop_back();
    }
    return 0;
}