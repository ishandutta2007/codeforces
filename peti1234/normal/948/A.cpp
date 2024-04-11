#include <bits/stdc++.h>

using namespace std;
int r, c;
int t[502][502];
int main()
{
    cin >> r >> c;
    for (int i=1; i<=r;i++) {
        string s;
        cin >> s;
        for (int j=0;j<s.size(); j++) {
            if (s[j]=='S') {
                t[i][j+1]=1;
            }
            if (s[j]=='W') {
                t[i][j+1]=2;
            }
        }
    }
    for (int i=1; i<=r; i++) {
        for (int j=1; j<=c; j++) {
            if (t[i][j]==0) {
                t[i][j]=3;
            }
            if (t[i][j]==1) {
                if (t[i+1][j]==2 || t[i-1][j]==2 ||t[i][j+1]==2 ||t[i][j-1]==2 ) {
                    cout << "No" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "Yes" << endl;
    for (int i=1; i<=r; i++) {
        for (int j=1;j<=c; j++) {
            int x=t[i][j];
            if (x==1) {
                cout << 'S';
            }
            if (x==2) {
                cout << 'W';
            }
            if (x==3) {
                cout << 'D';
            }
        }
        cout << endl;
    }
    return 0;
}