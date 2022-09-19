#include <bits/stdc++.h>

using namespace std;
int w, n, x, y, mini, e, k, h;
string s;
void add(int a, int b) {
    if (s[a]=='1') e+=b;
    if (s[a]=='2') k+=b;
    if (s[a]=='3') h+=b;
}
int main()
{
    cin >> w;
    while(w--) {
        cin >> s, s+='0', n=s.size(), e=0, k=0, h=0, x=0, y=0, mini=n+1;
        while(x<n) {
            while(y<n && (!e || !k || !h)) add(y, 1), y++;
            if (y>=n) break;
            mini=min(mini, y-x), add(x, -1), x++;
        }
        mini%=n+1;
        cout << mini << "\n";
    }
    return 0;
}