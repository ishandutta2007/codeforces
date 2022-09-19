#include <bits/stdc++.h>

using namespace std;
int w, n, db[32], jo;
int main()
{
    cin >> w;
    while(w--) {
        cin >> n, jo=1;
        for (int i=0; i<n; i++) {
            string s; cin >> s;
            for (int j=0; j<s.size(); j++) {
                db[s[j]-'a']++;
            }
        }
        for (int i=0; i<30; i++) {
            if (db[i]%n) jo=0;
            db[i]=0;
        }
        if (jo) cout << "YES\n";
        else cout << "No\n";
    }
    return 0;
}