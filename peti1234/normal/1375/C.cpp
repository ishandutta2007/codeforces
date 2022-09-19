#include <bits/stdc++.h>

using namespace std;
int w, n, t[300005], mini;
bool f;
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) cin >> t[i];
        if (t[n]<t[1]) cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}