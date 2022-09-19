#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        string s;
        int n;
        cin >> n >> s;
        int pos=0;
        while (pos<n) {
            int ert=0;
            if (pos+2<n && s[pos+2]=='0' && (pos+3==n || s[pos+3]!='0')) {
                ert=10*(s[pos]-'0')+(s[pos+1]-'0');
                pos+=3;
            } else {
                ert=(s[pos]-'0');
                pos++;
            }
            char f='a'+ert-1;
            cout << f;
        }
        cout << "\n";
    }
    return 0;
}
/*
1
7
1111100
*/