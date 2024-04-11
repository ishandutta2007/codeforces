#include <bits/stdc++.h>

using namespace std;
const int c=300002;
int w, n, b, j, db;
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n >> s, db=0, b=0, j=0;
        for (int i=0; i<n; i++) {
            if (s[i]=='<') b=1;
            if (s[i]=='>') j=1;
        }
        for (int i=0; i<n; i++) {
            if (s[i]!='-' && s[(i+1)%n]!='-') db++;
        }
        if (!b || !j) db=0;
        cout << n-db << "\n";
    }
    return 0;
}