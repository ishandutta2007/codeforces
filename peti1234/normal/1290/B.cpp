#include <bits/stdc++.h>

using namespace std;
int kom[200002][32], n, q, db, x, y;
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> s, n=s.size();
    for (int i=0; i<n; i++) kom[i+1][s[i]-'a']++;
    for (int i=1; i<=n; i++) for (int j=0; j<27; j++) kom[i][j]+=kom[i-1][j];
    cin >> q;
    while(q--) {
        cin >> x >> y, db=0;
        for (int i=0; i<27; i++) db+=((kom[y][i]-kom[x-1][i])!=0);
        if (x==y || db>=3 || (db==2 && s[x-1]!=s[y-1])) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}