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
        if (n <= 3)
        {
            cout << "-1\n";
            continue;
        }
        int cur = (n % 2 == 0 ? 2 : 1);
        while (cur <= n)
        {
            cout << cur << " ";
            cur += 2;
        }
        cur -= 5;
        cout << cur << " ";
        cur += 2;
        cout << cur << " ";
        cur -= 4;
        while (cur >= 1)
        {
            cout << cur << " ";
            cur -= 2;
        }
        cout << endl;
    }
    return 0;
}