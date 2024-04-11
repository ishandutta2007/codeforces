#include <bits/stdc++.h>

using namespace std;
int w, n, db, kis, nagy;
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> s;
        n=s.size();
        db=0, kis=-1, nagy=-1;
        for (int i=0; i<n; i++) {
            if (s[i]=='0') {
                db++;
                if (db==1) {
                    kis=i;
                }
                nagy=i;
            }
        }
        if (!db) {
            cout << 0 << "\n";
        } else {
            if (kis+db==nagy+1) {
                cout << 1 << "\n";
            } else {
                cout << 2 << "\n";
            }
        }
    }
    return 0;
}