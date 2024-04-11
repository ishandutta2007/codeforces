#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        n--;
        if (n <= 1)
        {
            cout << "1\n";
        }
        else
        {
            n -= 2;
            cout << n / x + 2 << "\n";
        }
    }
    return 0;
}