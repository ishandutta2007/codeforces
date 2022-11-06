#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000;
pair<int, int> pack[MAXN];

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> pack[i].first >> pack[i].second;
        }
        sort(pack, pack + n);
        bool valid = true;
        for (int i = 1; i < n; i++)
        {
            if (pack[i].second < pack[i - 1].second)
                valid = false;
        }
        if (valid)
        {
            cout << "YES" << endl;
            int x, y;
            x = y = 0;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < pack[i].first - x; j++)
                    cout << "R";
                for (int j = 0; j < pack[i].second - y; j++)
                    cout << "U";
                x = pack[i].first;
                y = pack[i].second;
            }
            cout << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}