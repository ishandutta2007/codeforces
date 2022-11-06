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
            cout << -1 << "\n";
        else
        {
            stringstream ss;
            ss << 2;
            for (int i = 0; i < n - 1; i++)
            {
                ss << 3;
            }
            cout << ss.str() << "\n";
        }

    }
    return 0;
}