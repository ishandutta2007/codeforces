#include <bits/stdc++.h>

using namespace std;
const int c=1000002;
int n, kezd, veg, ans[c];
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> s;
    n=s.size(), kezd=1, veg=n;
    for (int i=0; i<n; i++) {
        if (s[i]=='r') {
            ans[kezd++]=i+1;
        } else {
            ans[veg--]=i+1;
        }
    }
    for (int i=1; i<=n; i++) {
        cout << ans[i] << "\n";
    }
    return 0;
}