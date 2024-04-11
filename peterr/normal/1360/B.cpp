#include <bits/stdc++.h>

using namespace std;

const int MAXN = 50;
int s[MAXN];

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int ans = 10000;
        for (int i = 0; i < n; i++)
        {
            cin >> s[i];
            for (int j = 0; j < i; j++)
                ans = min(ans, abs(s[i] - s[j]));
        }
        cout << ans << "\n";
    }
    return 0;
}