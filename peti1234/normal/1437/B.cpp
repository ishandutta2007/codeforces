#include <bits/stdc++.h>

using namespace std;
int w, n, db;
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n, db=1;
        cin >> s;
        for (int i=1; i<n; i++) db+=(s[i]==s[i-1]);
        cout << db/2 << "\n";
    }
    return 0;
}