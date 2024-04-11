#include <bits/stdc++.h>

using namespace std;
int n, m;
string s[100];
bool baj;
int main()
{
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        cin >> s[i];
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (i>0 && s[i][j]==s[i-1][j]) {
                baj=1;
            }
            if (j>0 && s[i][j]!=s[i][j-1]) {
                baj=1;
            }
        }
    }
    cout << (baj ? "NO" : "YES") << "\n";
    return 0;
}