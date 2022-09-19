#include <bits/stdc++.h>

using namespace std;
const int c=1000002;
long long w, n, a[c], b[c], pos, ert, mini, el;
bool r;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n, pos=0, ert=0, mini=0, el=0, r=0;
        for (int i=1; i<=n; i++) cin >> a[i];
        for (int i=1; i<=n; i++) cin >> b[i];
        for (int i=1; i<=n; i++) {
            ert+=b[i]-a[i];
            if (ert<mini) pos=i, mini=ert;
        }
        for (int i=1; i<=n; i++) {
            pos%=n, pos++;
            if (b[pos]+el<a[pos]) r=1;
            el=min(b[pos], b[pos]+el-a[pos]);
        }
        if (r) cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}
/*
1 3
3 3 3
2 3 4
*/