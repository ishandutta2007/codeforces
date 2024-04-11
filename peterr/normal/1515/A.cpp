#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100;
pair<int, int> a[MAXN];

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i].first;
            a[i].second = i + 1;
            sum += a[i].first;
        }
        sort(a, a + n);
        if (sum == x)
        {
            cout << "NO\n";
        }
        else
        {
            sum = 0;
            for (int i = 0; i < n; i++)
            {
                sum += a[i].first;
                if (sum == x)
                    swap(a[i], a[i + 1]);
            }
            cout << "YES\n";
            for (int i = 0; i < n; i++)
            {
                cout << a[i].first << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}