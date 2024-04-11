#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int you;
        cin >> you;
        int sum = 0;
        for (int i = 1; i < n; i++)
        {
            int x;
            cin >> x;
            sum += x;
        }
        cout << min(m, you + sum) << endl;
    }
    return 0;
}