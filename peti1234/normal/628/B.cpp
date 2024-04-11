#include <bits/stdc++.h>

using namespace std;
long long ans, x, el, n;
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> s;
    n=s.size();
    for (int i=0; i<n; i++) {
        x=(s[i]-'0');
        if (x%4==0) ans++;
        if (i && (2*el+x)%4==0) {
            ans+=i;
        }
        el=x;
    }
    cout << ans << "\n";
    return 0;
}