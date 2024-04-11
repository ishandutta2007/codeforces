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
        if (n == 1)
            cout << "9\n";
        else if (n == 2)
            cout << "98\n";
        else
        {
            cout << "989";
            n -= 3;
            int cur = 0;
            for (int i = 0; i < n; i++)
            {
                cout << cur;
                cur++;
                if (cur == 10)
                    cur = 0;
            }
            cout << "\n";
        }
    }
    return 0;
}