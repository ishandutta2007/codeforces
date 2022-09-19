#include <bits/stdc++.h>

using namespace std;
string s;
int db, pos, pos2, db2, n;
bool baj;
int main()
{
    cin >> s;
    n=s.size();
    pos=n, pos2=n;
    for (char i:s) {
        if (i!='a') {
            db++;
        }
    }
    if (db%2) {
        baj=1;
    }
    for (int i=0; i<n; i++) {
        int ii=s[i];
        if (ii!='a') {
            db2++;
            if (db2==db/2+1) {
                pos=i;
            }
        }
    }
    pos2=pos;
    for (int i=0; i<pos; i++) {
        int x=s[i];
        if (x!='a') {
            if (pos2>=n || x!=s[pos2]) {
                baj=1;
            }
            pos2++;
        }
    }
    if (pos2!=n) {
        baj=1;
    }
    if (baj) {
        cout << ":(\n";
    } else {
        cout << s.substr(0, pos);
    }
    return 0;
}
/*
abb
*/