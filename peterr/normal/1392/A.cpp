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
        int a;
        cin >> a;
        bool same = true;
        for (int i = 0; i < n - 1; i++)
        {
            int b;
            cin >> b;
            if (b != a)
                same = false;
        }
        if (same)
            cout << n << "\n";
        else
            cout << "1\n";
    }
    return 0;
}