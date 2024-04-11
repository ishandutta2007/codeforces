#include <bits/stdc++.h>

using namespace std;
const int c=100002;
int w, n, h, db[c][26];
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> h;
        for (int i=1; i<=n; i++) {
            cin >> s;
            for (int j=0; j<h; j++) {
                db[j][s[j]-'a']++;
            }
        }
        for (int i=1; i<n; i++) {
            cin >> s;
            for (int j=0; j<h; j++) {
                db[j][s[j]-'a']--;
            }
        }
        for (int j=0; j<h; j++) {
            for (int k=0; k<26; k++) {
                if (db[j][k]) {
                    char s='a'+k;
                    cout << s;
                    db[j][k]=0;
                }
            }
        }
        cout.flush() << "\n";
    }
    return 0;
}