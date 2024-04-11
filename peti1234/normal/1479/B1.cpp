#include <bits/stdc++.h>

using namespace std;
const int c=100002;
int n, t[c], kov[c], ut[c], a, b, ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        kov[ut[t[i]]]=i;
        ut[t[i]]=i;
    }
    for (int i=1; i<=n; i++) {
        if (!kov[i]) {
            kov[i]=n+1;
        }
    }
    kov[0]=n+1;
    for (int i=1; i<=n; i++) {
        if (t[i]!=t[a] || t[i]!=t[b]) {
            ans++;
        }
        if (t[a]!=t[i] && (t[b]==t[i] || kov[a]<kov[b])) {
            a=i;
        } else {
            b=i;
        }
        if (t[a]==t[i]) {
            a=i;
        }
        if (t[b]==t[i]) {
            b=i;
        }
    }
    cout << ans << "\n";
    return 0;
}