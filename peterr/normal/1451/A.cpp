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
        int n;
        cin >> n;
        if (n == 1)
        {
            cout << "0\n";
        }
        else if (n == 2)
        {
            cout << "1\n";
        }
        else if (n == 3)
        {
            cout << "2\n";
        }
        else if (n % 2 == 1)
        {
            cout << "3\n";
        }
        else
        {
            cout << "2\n";
        }
    }
    return 0;
}