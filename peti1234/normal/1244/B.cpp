#include <bits/stdc++.h>

using namespace std;
int w, n, ans;
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        ans=n;
        cin >> s;
        for (int i=0; i<n; i++) {
            if (s[i]=='1') {
                ans=max(ans, 2*max(i+1, n-i));
            }
        }
        cout << ans << "\n";
    }
    return 0;
}