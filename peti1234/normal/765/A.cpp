#include <bits/stdc++.h>

using namespace std;
int n;
string k;
string t[101];
string p;
int a, b;
int main()
{
    cin >> n;
    cin >> k;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    p=k;
    for (int i=1; i<=n; i++) {
        if (t[i][0]==p[0] && t[i][1]==p[1] && t[i][2]==p[2]) {
            a++;
        }
        if (t[i][5]==p[0] && t[i][6]==p[1] && t[i][7]==p[2]) {
            b++;
        }
    }
    if (a==b) {
        cout << "home" << endl;
    } else {
        cout << "contest" << endl;
    }
    return 0;
}