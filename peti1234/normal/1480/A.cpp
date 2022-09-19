#include <bits/stdc++.h>

using namespace std;
int w;
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> s;
        for (int i=0; i<s.size(); i++) {
            char c=s[i];
            if (i%2) {
                if (c=='z') {
                    cout << 'y';
                } else {
                    cout << 'z';
                }
            } else {
                if (c=='a') {
                    cout << 'b';
                } else {
                    cout << 'a';
                }
            }
        }
        cout << "\n";
    }
    return 0;
}