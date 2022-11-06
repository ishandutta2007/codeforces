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
        int a, b, c;
        cin >> a >> b;
        for (int i = 0; i < n - 3; i++)
        {
            int trash;
            cin >> trash;
        }
        cin >> c;
        if (a + b <= c)
            cout << 1 << " " << 2 << " " << n << "\n";
        else
            cout << "-1\n";
    }
    return 0;
}