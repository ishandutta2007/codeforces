#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int prev;
        cin >> prev;
        bool ans = false;
        int ind;
        for (int i = 0; i < n - 1; i++)
        {
            int x;
            cin >> x;
            if (abs(prev - x) >= 2)
            {
                ans = true;
                ind = i + 2;
            }
            prev = x;
        }
        if (ans)
        {
            cout << "YES" << endl;
            cout << ind - 1 << " " << ind << endl;
        }
        else
            cout << "NO" << endl;

    }
    return 0;
}