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
        int sum = 0;
        bool odd, even;
        odd = even = false;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            sum += x;
            if (x % 2 == 0)
                even = true;
            else
                odd = true;
        }
        if (sum % 2 != 0)
            cout << "YES" << endl;
        else
        {
            if (odd && even)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
    return 0;
}