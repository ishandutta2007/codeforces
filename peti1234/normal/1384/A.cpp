#include <bits/stdc++.h>

using namespace std;
int n, w, x;
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    for (int i=0; i<52; i++) s+='a';
    cin >> w;
    while(w--) {
        cin >> n;
        cout << s << "\n";
        while(n--) {
            cin >> x;
            if (s[x]=='a') s[x]='b';
            else s[x]='a';
            cout << s << "\n";
        }
    }
    return 0;
}