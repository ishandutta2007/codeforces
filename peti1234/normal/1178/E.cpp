#include <bits/stdc++.h>

using namespace std;
int n;
string s, ans;
int main()
{
    cin >> s;
    n=s.size();
    for (int i=0; i<n/2; i+=2) {
        if (i+1>=n/2) {
            cout << ans << s[i];
            reverse(ans.begin(), ans.end());
            cout << ans << "\n";
            return 0;
        }
        int v=n-i-2;
        if (s[i]==s[v] || s[i]==s[v+1]) {
            ans+=s[i];
        } else {
            ans+=s[i+1];
        }
    }
    cout << ans;
    reverse(ans.begin(), ans.end());
    cout << ans << "\n";
    return 0;
}