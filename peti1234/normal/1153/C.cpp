#include <bits/stdc++.h>

using namespace std;
int n;
string s;
int op=0;
int cl=0;
int main()
{
    cin >> n;
    cin >> s;
    if (n%2==1) {
        cout << ":(" << "\n";
        return 0;
    }
    for (int i=0; i<n; i++) {
        if (s[i]=='(') {
            op++;
        }
        if (s[i]==')') {
            cl++;
        }
    }
    if (op>n/2 || cl>n/2) {
        cout << ":(" << "\n";
        return 0;
    }
    int x=0, y=0;
    for (int i=0; i<n; i++) {
        if (s[i]=='(') {
            x++;
        }
        if (s[i]==')') {
            y++;
        }
        if (s[i]=='?') {
            if (op<n/2) {
                x++;
                s[i]='(';
                op++;
            } else {
                y++;
                s[i]=')';
            }
        }
        if (x<=y && i+1!=n) {
            cout << ":(" << endl;
            return 0;
        }
    }
    cout << s << endl;
    return 0;
}