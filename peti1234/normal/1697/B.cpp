#include <bits/stdc++.h>

using namespace std;
const int c=200005;
long long n, q, t[c], pref[c];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    sort(t+1, t+n+1);
    reverse(t+1, t+n+1);
    for (int i=1; i<=n; i++) {
        pref[i]=pref[i-1]+t[i];
    }
    while (q--) {
        int x, y;
        cin >> x >> y;
        cout << pref[x]-pref[x-y] << "\n";
    }
    return 0;
}