#include <bits/stdc++.h>

using namespace std;
int w, n, db[26];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=2*n+1; i++) {
            string s;
            cin >> s;
            for (auto x:s) {
                db[x-'a']++;
            }
        }
        for (int i=0; i<26; i++) {
            if (db[i]%2) {
                cout << (char)('a'+i) << "\n";
                db[i]=0;
            }
        }
    }
    return 0;
}