#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, min1 = 101, ans = 0, x, a;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> x;
        min1 = min(min1, x);
        ans += min1 * a;
    }
    cout << ans;
    return 0;
}