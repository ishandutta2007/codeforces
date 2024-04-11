#include <bits/stdc++.h>

using namespace std;
const int c=200005, sok=2e9;
int n, m, ert[c][2];
string s;
int el(int a) {
    return (a ? a-1 : n-1);
}
int kov(int a) {
    return (a<n-1 ? a+1 : 0);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> s;
    for (int i=0; i<n; i++) {
        ert[i][0]=sok, ert[i][1]=sok;
    }
    for (int i=0; i<n; i++) {
        if (s[kov(i)]==s[i] || s[el(i)]==s[i]) {
            if (s[i]=='W') {
                ert[i][0]=0;
            } else {
                ert[i][1]=0;
            }
        }
    }
    for (int k=0; k<2; k++) {
        for (int j=0; j<2; j++) {
            for (int i=0; i<n; i++) {
                ert[kov(i)][j]=min(ert[kov(i)][j], ert[i][j]+1);
            }
            for (int i=n-1; i>=0; i--) {
                ert[el(i)][j]=min(ert[el(i)][j], ert[i][j]+1);
            }
        }
    }
    for (int i=0; i<n; i++) {
        int a=ert[i][0], b=ert[i][1];
        if (min(a, b)>m) {
            if ((s[i]=='B') == (m%2)) {
                cout << 'W';
            } else {
                cout << 'B';
            }
        } else {
            if (a<b) {
                cout << 'W';
            } else {
                cout << 'B';
            }
        }
    }
    cout << "\n";
    return 0;
}