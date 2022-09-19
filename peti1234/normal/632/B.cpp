#include <bits/stdc++.h>

using namespace std;
const int c=500005;
long long n, t[c], sum, ert, ans;
bool v[c];
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        sum+=t[i];
    }
    for (int i=1; i<=n; i++) {
        char c;
        cin >> c;
        v[i]=(c=='A');
        if (c=='B') ert+=t[i];
    }
    ans=max(ert, sum-ert);
    for (int i=1; i<=n; i++) {
        if (v[i]) ert+=t[i];
        else ert-=t[i];
        ans=max({ans, ert, sum-ert});
    }
    cout << ans << "\n";
    return 0;
}