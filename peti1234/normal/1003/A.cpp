#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int n, ans=0;
    cin >> n;
    map<int, int> m;
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        m[x]++;
        ans=max(ans, m[x]);
    }
    cout << ans << "\n";
    return 0;
}