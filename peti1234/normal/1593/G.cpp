#include <bits/stdc++.h>

using namespace std;
const int c=1000005;
int w, n, q, pref[c][2];
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> s;
        n=s.size();
        for (int i=0; i<n; i++) {
            pref[i+1][0]=pref[i][0], pref[i+1][1]=pref[i][1];
            if (s[i]=='[' || s[i]==']') pref[i+1][i%2]++;
        }
        cin >> q;
        for (int i=1; i<=q; i++) {
            int l, r;
            cin >> l >> r;
            int a=pref[r][0]-pref[l-1][0], b=pref[r][1]-pref[l-1][1];
            cout << abs(a-b) << "\n";
        }
    }
    return 0;
}