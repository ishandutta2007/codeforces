#include <bits/stdc++.h>

using namespace std;
int n, db, w;
string s, sol;
int main()
{
    cin >> w;
    while(w--) {
        cin >> n >> s; db=0, sol.clear();
        for (int i=0; i<n; i++) {
            int x=s[i]-'0';
            if (x%2 && db<2) sol+=s[i], db++;
        }
        if (db<2) cout << -1;
        else cout << sol;
        cout << "\n";
    }
    return 0;
}