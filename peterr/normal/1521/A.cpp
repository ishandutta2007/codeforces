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
        int a, b;
        cin >> a >> b;
        if (b == 1)
        {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        cout << a << " " << (long long) 2 * b * a - a << " " << (long long) 2 * a * b << "\n";
    }
    return 0;
}