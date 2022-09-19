#include <bits/stdc++.h>

using namespace std;
int w, n, t[200005];
bool ch(int pos) {
    int kezd=1, veg=n;
    while (kezd<=veg) {
        while (t[kezd]==t[pos]) kezd++;
        while (t[veg]==t[pos]) veg--;
        if (t[kezd]!=t[veg]) return 0;
        kezd++, veg--;
    }
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) cin >> t[i];
        int kezd=1, veg=n;
        while (kezd<=veg) {
            if (t[kezd]==t[veg]) kezd++, veg--;
            else break;
        }
        cout << ((ch(kezd) || ch(veg)) ? "YES" : "NO") << "\n";
    }
    return 0;
}