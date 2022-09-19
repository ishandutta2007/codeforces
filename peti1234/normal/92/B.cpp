#include <bits/stdc++.h>

using namespace std;
int n, db, ut;
string s;
int main()
{
    cin >> s, n=s.size();
    for (int i=0; i<n; i++) if (s[i]=='1') db++, ut=i;
    if (ut==0) cout << n-1;
    else cout << n+ut-db+2 << "\n";
    return 0;
}