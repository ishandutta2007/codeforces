#include <bits/stdc++.h>

using namespace std;
int w, n;
string s;
int main()
{
    cin >> w;
    while (w--) {
        cin >> s;
        reverse(s.begin(), s.end());
        int a=0, b=0;
        n=s.size();
        for (int i=0; i<n; i++) {
            char c=s[i];
            if (a && (c=='0' || c=='5')) {
                cout << i-1 << "\n";
                break;
            }
            if (b && (c=='2' || c=='7')) {
                cout << i-1 << "\n";
                break;
            }
            if (c=='0') a=1;
            if (c=='5') b=1;
        }
    }
    return 0;
}