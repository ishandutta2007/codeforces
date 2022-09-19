#include <bits/stdc++.h>

using namespace std;
int w, n, ans, a, b, db;
string s;
int main()
{
    cin >> w;
    while (w--) {
        cin >> n >> a >> b >> s;
        ans=n*a, db=0;
        if (b>0) {
            ans+=n*b;
        } else {
            for (int i=1; i<n; i++) {
                if (s[i]!=s[i-1]) {
                    db++;
                }
            }
            ans+=(db+3)/2*b;
        }
        cout << ans << "\n";
    }
    return 0;
}