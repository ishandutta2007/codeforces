#include <bits/stdc++.h>

using namespace std;
int w, n, db;
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n >> s, db=0;
        for (int i:s) {
            if (i==')') db++;
            else db=0;
        }
        if (2*db>n) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}