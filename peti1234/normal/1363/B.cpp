#include <bits/stdc++.h>

using namespace std;
int w, n, db, maxi, cnt;
bool v[1003];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        db=0, maxi=0, cnt=0;
        string s;
        cin >> s, n=s.size();
        for (int i=0; i<s.size(); i++) {
            v[i+1]=(s[i]=='1');
            db+=v[i+1];
        }
        for (int i=1; i<=n; i++) {
            if (v[i]) cnt++;
            else cnt--;
            maxi=max(maxi, cnt);
        }
        cnt=0;
        for (int i=n; i>=1; i--) {
            if (v[i]) cnt++;
            else cnt--;
            maxi=max(maxi, cnt);
        }
        cout << db-maxi << "\n";
    }
    return 0;
}