#include <bits/stdc++.h>

using namespace std;
int w, n, un, ee;
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> s;
        n=s.size();
        un=0, ee=n+1;
        for (int i=1; i<n; i++) {
            if (s[i]=='1' && s[i-1]=='1') {
                ee=min(ee, i);
            }
            if (s[i]=='0' && s[i-1]=='0') {
                un=i;
            }
        }
        cout << (un>ee ? "NO" : "YES") << "\n";
    }
    return 0;
}