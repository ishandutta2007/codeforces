#include <bits/stdc++.h>

using namespace std;
int n, q, l, r, pref[100005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >>pref[i];
        pref[i]+=pref[i-1];
    }
    cin >> q;
    while (q--) {
        cin >> l >> r;
        cout << (pref[r]-pref[l-1])/10 << "\n";
    }
    return 0;
}