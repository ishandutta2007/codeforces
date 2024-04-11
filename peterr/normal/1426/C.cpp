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
        int a = 1;
        int b = 1;
        int ans = 0;
        while (a * b < n)
        {
            if (a == b)
                a++;
            else
                b++;
            ans++;
        }
        cout << ans << "\n";
    }
    return 0;
}