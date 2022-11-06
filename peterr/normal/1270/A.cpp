#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k1, k2;
        cin >> n >> k1 >> k2;
        bool oneWin = false;
        for (int i = 0; i < k1; i++)
        {
            int x;
            cin >> x;
            if (x == n)
                oneWin = true;
        }
        for (int i = 0; i < k2; i++)
        {
            int x;
            cin >> x;
        }
        if (oneWin)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}