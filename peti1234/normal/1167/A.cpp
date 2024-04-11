#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i=1; i<=t; i++) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        bool v=false;
        for (int i=0; i<n-10; i++) {
            if (s[i]=='8') {
                v=true;
            }
        }
        if (v) {
            cout << "YES";
        } else {
            cout << "NO";
        }
        cout << endl;
    }
    return 0;
}