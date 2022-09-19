#include <bits/stdc++.h>

using namespace std;
int n, a, b, c;
string s;
int main()
{
    cin >> n >> s;
    for (int i=0; i<n; i++) {
        if (s[i]=='B') {
            a++;
        }
        if (s[i]=='G') {
            b++;
        }
        if (s[i]=='R') {
            c++;
        }
    }
    sort(s.begin(), s.end());
    if (s[0]==s[n-1]) {
        cout << s[0] << "\n";
        return 0;
    }
    if (a && b && c) {
        cout << "BGR\n";
        return 0;
    }
    if (a!=n-1) {
        cout << "B";
    }
    if (b!=n-1) {
        cout << "G";
    }
    if (c!=n-1) {
        cout << "R";
    }
    return 0;
}