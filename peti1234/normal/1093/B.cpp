#include <bits/stdc++.h>

using namespace std;
int x;
int main()
{
    cin >> x;
    for (int i=1; i<=x; i++) {
        bool c=false;
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        for (int i=1; i<s.size(); i++) {
            if (s[i]!=s[i-1]) {
                c=true;
            }
        }
        if (c) {
            cout << s << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}