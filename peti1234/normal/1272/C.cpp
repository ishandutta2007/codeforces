#include <bits/stdc++.h>

using namespace std;
int n, m;
long long ans, db;
string s;
set<char> k;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    cin >> s;
    for (int i=1; i<=m; i++) {
        char c;
        cin >> c;
        k.insert(c);
    }
    for (int i=0; i<n; i++) {
        if (k.find(s[i])!=k.end()) {
            db++;
        } else {
            ans+=db*(db+1)/2;
            db=0;
        }
    }
    ans+=db*(db+1)/2;
    cout << ans << "\n";
    return 0;
}