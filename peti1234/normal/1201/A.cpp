#include <bits/stdc++.h>

using namespace std;
int n, m, db[10005][5], sum;
int main()
{
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        string s;
        cin >> s;
        for (int j=0; j<m; j++) {
            int ert=s[j]-'A';
            db[j][ert]++;
        }
    }
    for (int i=0; i<m; i++) {
        int x;
        cin >> x;
        int maxi=0;
        for (int j=0; j<5; j++) {
            maxi=max(maxi, db[i][j]);
        }
        sum+=maxi*x;
    }
    cout << sum << "\n";
    return 0;
}