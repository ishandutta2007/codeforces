#include <bits/stdc++.h>

using namespace std;
string s;
int w, n, db, mini, cnt;
int main()
{
    cin >> w;
    while (w--) {
        cin >> n;
        db=0, mini=0, cnt=0;
        cin >> s;
        for (int i=0; i<n; i++) {
            if (s[i]=='M') {
                db++;
                cnt--;
            } else {
                cnt++;
            }
            mini=min(mini, cnt);
        }
        cnt=0;
        for (int i=n-1; i>=0; i--) {
            if (s[i]=='M') {
                cnt--;
            } else {
                cnt++;
            }
            mini=min(mini, cnt);
        }
        cout << (db!=n/3 || mini<0 ? "NO" : "YES") << "\n";
    }
    return 0;
}