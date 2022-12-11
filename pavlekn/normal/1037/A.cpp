#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    int ans = 1;
    int x = 2;
    for (int i = 0; (x - 1) < n; ++i)
    {
        x *= 2;
        ++ans;
    }
    cout << ans << endl;
}