#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5000;
int a[MAXN + 1];

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        map<int, vector<int>> m;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            m[a[i]].push_back(i);
        }
        if ((int) m.size() == 1)
        {
            cout << "NO\n";
        }
        else
        {
            cout << "YES\n";
            for (int i = 1; i <= n; i++)
            {
                if (a[i] != a[1])
                {
                    cout << "1 " << i << "\n";
                }
            }
            int ind = 1;
            while (a[ind] == a[1])
                ind++;
            for (int i = 2; i <= n; i++)
            {
                if (a[i] == a[1])
                {
                    cout << ind << " " << i << "\n";
                }
            }
        }
    }
    return 0;
}