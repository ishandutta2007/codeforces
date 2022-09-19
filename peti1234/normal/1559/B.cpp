#include <bits/stdc++.h>

using namespace std;
int w, n;
string s;
int main()
{
    cin >> w;
    while (w--) {
        cin >> n >> s;
        for (int i=1; i<n; i++) {
            if (s[i]=='?' && s[i-1]!='?') {
                s[i]=(s[i-1]=='B' ? 'R' : 'B');
            }
        }
        for (int i=n-2; i>=0; i--) {
            if (s[i]=='?' && s[i+1]!='?') {
                s[i]=(s[i+1]=='B' ? 'R' : 'B');
            }
        }
        if (s[0]=='?') {
            for (int i=0; i<n; i++) {
                s[i]=(i%2 ? 'R' : 'B');
            }
        }
        cout << s << "\n";
    }
    return 0;
}