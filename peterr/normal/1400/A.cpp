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
        string s;
        cin >> n >> s;
        string ans = "";
        for (int i = 0; i < n; i++)
        {
            ans += s[2 * i];
        }
        cout << ans << "\n";
    }
    return 0;
}