#include <bits/stdc++.h>

using namespace std;
int n, m;
char p;
string s[100];
set<char> ans;
void add(char a, char b) {
    if (a=='.' || b=='.') return;
    if (a==p && b!=p) ans.insert(b);
    if (a!=p && b==p) ans.insert(a);
}
int main()
{
    cin >> n >> m >> p;
    for (int i=0; i<n; i++) cin >> s[i];
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (i) add(s[i-1][j], s[i][j]);
            if (j) add(s[i][j-1], s[i][j]);
        }
    }
    cout << ans.size() << "\n";
    return 0;
}