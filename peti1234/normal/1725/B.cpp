#include <bits/stdc++.h>

using namespace std;
const int c=100005;
long long n, d, t[c], db, ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> d;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    sort(t+1, t+n+1);
    reverse(t+1, t+n+1);
    for (int i=1; i<=n; i++) {
        db+=(d/t[i]);
        if (i+db<=n) ans++;
    }
    cout << ans << "\n";
    return 0;
}