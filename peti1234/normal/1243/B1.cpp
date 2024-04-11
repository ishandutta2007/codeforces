#include <bits/stdc++.h>

using namespace std;
int w, n, db, pos1, pos2;
string a, b;
int main()
{
    cin >> w;
    while (w--) {
        cin >> n;
        db=0, pos1=0, pos2=0;
        cin >> a >> b;
        for (int i=0; i<n; i++) {
            if (a[i]!=b[i]) {
                db++;
                if (db==1) {
                    pos1=i;
                } else {
                    pos2=i;
                }
            }
        }
        cout << (db==2 && a[pos1]==a[pos2] && b[pos1]==b[pos2] ? "Yes" : "No") << "\n";
    }
    return 0;
}