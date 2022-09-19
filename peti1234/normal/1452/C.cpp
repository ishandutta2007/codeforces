#include <bits/stdc++.h>

using namespace std;
int w, n, db, x, y;
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> s, n=s.size(), x=0, y=0, db=0;
        for (int i=0; i<n; i++) {
            if (s[i]=='(') x++;
            if (s[i]=='[') y++;
            if (s[i]==')') {
                if (x) x--, db++;
            }
            if (s[i]==']') {
                if (y) y--, db++;
            }
        }
        cout << db << "\n";
    }
    return 0;
}