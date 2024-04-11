#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        bool flag = 0;
        for (int i = 0; i < n; i++)
        {
            int y;
            cin >> y;
            if (y < (x + 1) / 2)
                cout << "0 ";
            else if (y > x / 2)
                cout << "1 ";
            else
            {
                cout << flag << " ";
                flag = !flag;
            }
        }
        cout << "\n";
    }
    return 0;
}