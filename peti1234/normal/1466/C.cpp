#include <bits/stdc++.h>

using namespace std;
int w, n, db;
string s;
int main()
{
    cin >> w;
    while(w--) {
        cin >> s, n=s.size(), db=0;
        for (int i=1; i<n; i++) {
            if (s[i]==s[i-1] || (i>1 && s[i]==s[i-2])) {
                db++;
                s[i]='.';
            }
        }
        cout << db << "\n";
    }
    return 0;
}