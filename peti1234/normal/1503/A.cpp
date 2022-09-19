#include <bits/stdc++.h>

using namespace std;
int w, n;
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> s;
        int odb=0;
        for (int i=0; i<n; i++) {
            if (s[i]=='0') {
                odb++;
            }
        }
            if (odb%2 || s[0]=='0' || s[n-1]=='0') {
                cout << "NO\n";
            } else {
                cout << "YES\n";
                string a, b;
                int x=0, y=0, hat=(n-odb)/2;
                for (int i=0; i<n; i++) {
                    if (s[i]=='0') {
                        if (y%2) {
                            a+=')', b+='(';
                        } else {
                            a+='(', b+=')';
                        }
                        y++;
                    } else {
                        if (x<hat) {
                            a+='(', b+='(';
                        } else {
                            a+=')', b+=')';
                        }
                        x++;
                    }
                }
                cout << a << "\n" << b << "\n";

            }
    }
    return 0;
}