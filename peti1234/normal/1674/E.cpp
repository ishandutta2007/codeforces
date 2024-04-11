#include <bits/stdc++.h>

using namespace std;
long long n, t[200005], ans=2e9, pos=1;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        if (t[i]<t[pos]) pos=i;
    }
    for (int i=1; i<=n; i++) {
        if (i!=pos) {
            ans=min(ans, (t[pos]+1)/2+(t[i]+1)/2);
        }
        if (i>1) {
            ans=min(ans, max({(t[i-1]+1)/2, (t[i]+1)/2, (t[i-1]+t[i]+2)/3}));
        }
        if (i>2) {
            ans=min(ans, min(t[i], t[i-2])+(abs(t[i]-t[i-2])+1)/2);
        }
    }
    cout << ans << "\n";
    return 0;
}