#include <bits/stdc++.h>

using namespace std;
int w, n, sum, kul, el, ut, db;
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n >> s, sum=0, kul=0, el=0, ut=n-1, db=1;
        for (int i=1; i<n; i++) if (s[i]!=s[i-1]) kul++;
        if (kul==0) cout << (n+2)/3 << "\n";
        else {
            while(s[el]==s[0]) el++;
            while(s[ut]==s[0]) ut--;
            sum+=(el+n-1-ut)/3;
            for (int i=el+1; i<=ut; i++) {
                if (s[i]!=s[i-1]) sum+=db/3, db=0;
                db++;
            }
            sum+=db/3;
            cout << sum << "\n";
        }
    }
    return 0;
}