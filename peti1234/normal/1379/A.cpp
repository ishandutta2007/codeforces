#include <bits/stdc++.h>

using namespace std;
int w, n, jo, db;
string s, sol, p="abacaba";
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n >> s, jo=0;
        for (int i=0; i<n-6; i++) {
            sol.clear(), db=0;
            for (int j=0; j<n; j++) {
                if (s[j]!='?') sol+=s[j];
                else if (j-i>=0 && j-i<7) sol+=p[j-i];
                else sol+='d';
            }
            for (int j=0; j<n-6; j++) {
                bool h=0;
                for (int k=0; k<7; k++) if (sol[j+k]!=p[k]) h=1;
                if (!h) db++;
            }
            if (db==1 && !jo) {
                jo=1;
                cout << "Yes\n" << sol << "\n";
            }
        }
        if (!jo) cout << "No\n";
    }
    return 0;
}