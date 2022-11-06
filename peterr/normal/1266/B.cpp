#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long x;
        cin >> x;
        int mod = (int) (x % 14);
        if (x > 14 && mod >= 1 && mod <= 6)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}