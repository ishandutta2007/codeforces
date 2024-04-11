#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, n;
        cin >> a >> b >> n;
        int cycle = n % 3;
        if (cycle == 0)
            cout << a << endl;
        else if (cycle == 1)
            cout << b << endl;
        else
            cout << (a ^ b) << endl;
    }
    return 0;
}