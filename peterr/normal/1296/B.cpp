#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long s;
        long long ans = 0;
        cin >> s;
        while (s >= 10)
        {
            ans += s - s % 10;
            s = s % 10 + s / 10;
        }
        ans += s;
        cout << ans << endl;
    }
    return 0;
}