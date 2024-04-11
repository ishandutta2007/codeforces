#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, s;
    cin >> n >> s;
    if (s >= 2 * n)
    {
        cout << "YES\n";
        for (int i = 0; i < n - 1; i++)
            cout << "1 ";
        cout << s - n + 1 << "\n";
        cout << n << "\n";
    }
    else
    {
        cout << "NO\n";
    }
    return 0;
}