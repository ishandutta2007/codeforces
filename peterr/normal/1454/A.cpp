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
        for (int i = 2; i <= n; i++)
            cout << i << " ";
        cout << 1 << "\n";
    }
    return 0;
}