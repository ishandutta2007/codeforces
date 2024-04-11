#include <bits/stdc++.h>

using namespace std;
int w, n, db, pal;
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> s;
        db=0, pal=1;
        for (int i=0; i<n; i++) {
            if (s[i]=='0') {
                db++;
            }
            if (s[i]!=s[n-i-1]) {
                pal=0;
            }
        }
        if (pal) {
            if (db%2==1 && db!=1) {
                cout << "ALICE\n";
            } else {
                cout << "BOB\n";
            }
        } else {
            if (db==2 && n%2 && s[n/2]=='0') {
                cout << "DRAW\n";
            } else {
                cout << "ALICE\n";
            }
        }
    }
    return 0;
}