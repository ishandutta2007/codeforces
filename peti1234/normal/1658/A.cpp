#include <bits/stdc++.h>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        int n, ans=0;
        string s;
        cin >> n >> s;
        for (int i=0; i<n; i++) {
            if (s[i]=='0') {
                if (i>0 && s[i-1]=='0') ans+=2;
                else if (i>1 && s[i-2]=='0') ans++;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}