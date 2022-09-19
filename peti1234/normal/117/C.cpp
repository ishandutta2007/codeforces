#include <bits/stdc++.h>

using namespace std;
const int c=5002;
int n, db[c], ert, pos;
string s;
bool v[c], t[c][c];
vector<int> a, b;
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);
    cin >> n, ert=n-1;
    for (int i=1; i<=n; i++) {
        cin >> s;
        for (int j=0; j<n; j++) {
            if (s[j]=='1') t[i][j+1]=1, db[i]++;
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (db[j]==ert) {
                v[j]=1, ert--;
            }
        }
    }
    if (ert==-1) {
        cout << -1 << "\n";
    }
    for (int i=1; i<=n; i++) {
        if (!v[i] && db[i]>db[pos]) {
            pos=i;
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (i!=j && i!=pos && j!=pos && t[pos][i] && t[i][j] && t[j][pos]) {
                cout << pos << " " << i << " " << j << "\n";
                return 0;
            }
        }
    }
    return 0;
}