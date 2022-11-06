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
        int n, m;
        cin >> n >> m;
        if (n == 1)
            cout << "0\n";
        else if (n == 2)
        {
            cout << m << "\n";
        }
        else
            cout << 2 * m << "\n";
    }
    return 0;
}