#include <bits/stdc++.h>

using namespace std;
int w, db, n, kul;
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n >> s, db=0, kul=1;
        for (int i=1; i<n; i++) {
            if (s[i]!=s[i-1]) kul++;
            else db=min(db+1, kul);
        }
        cout << (kul+db+1)/2 << "\n";
    }
    return 0;
}