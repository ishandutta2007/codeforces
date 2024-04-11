#include <bits/stdc++.h>

using namespace std;
const int c=200005;
int n, q, pref[c][2];
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> q;
    cin >> s;
    for (int i=2; i<=n; i++) {
        pref[i][0]=pref[i-1][0], pref[i][1]=pref[i-1][1];
        if (s[i-1]=='0' && s[i-2]=='0') pref[i][0]++;
        if (s[i-1]=='1' && s[i-2]=='1') pref[i][1]++;
    }
    for (int i=1; i<=q; i++) {
        int l, r;
        cin >> l >> r;
        cout << max(pref[r][0]-pref[l][0], pref[r][1]-pref[l][1])+1 << "\n";
    }
    return 0;
}