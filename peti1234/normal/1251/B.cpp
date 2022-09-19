#include <bits/stdc++.h>

using namespace std;
int w, n, o, db;
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        o=0, db=0;
        for (int i=0; i<n; i++) {
            cin >> s;
            int si=s.size();
            o+=si%2;
            for (int i=0; i<si; i++) {
                db+=(s[i]=='0');
            }
        }
        //cout << "valasz: ";
        cout << (o || (db%2==0) ? n : n-1) << "\n";
    }
    return 0;
}