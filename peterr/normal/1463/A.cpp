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
        int a, b, c;
        cin >> a >> b >> c;
        int sum = a + b + c;
        if (a > b)
            swap(a, b);
        if (b > c)
            swap(b, c);
        if (a > b)
            swap(a, b);
        int shots = c - a + b - a;
        int en = (shots + 5) / 6 - 1;
        if (en >= a)
            cout << "NO\n";
        else
        {
            if (sum % 9 == 0)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
    return 0;
}