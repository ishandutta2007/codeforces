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
        int one = 0;
        int two = 0;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            if (x == 1)
                one++;
            else
                two++;
        }
        if (one & 1)
            cout << "NO\n";
        else if ((two & 1) && one == 0)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
    return 0;
}