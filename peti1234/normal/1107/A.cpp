#include <bits/stdc++.h>

using namespace std;
int q;
int main()
{
    cin >> q;
    for (int i=1; i<=q; i++) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        if (n==2 && s[0]>=s[1]) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            cout << 2 << endl;
            cout << s[0] << " ";
            for (int j=1; j<s.size(); j++) {
                cout << s[j];
            }
            cout << endl;
        }
    }
    return 0;
}