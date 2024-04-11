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
        long long n;
        cin >> n;
        int len = to_string(n).length();
        int ans = (len - 1) * 9;
        long long temp = 1;
        while (to_string(temp).length() < len)
        {
            temp *= 10;
            temp++;
        }
        for (int i = 1; i <= 9; i++)
        {
            ans += temp * i <= n;
        }
        cout << ans << "\n";
    }
    return 0;
}