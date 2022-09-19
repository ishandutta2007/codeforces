#include <bits/stdc++.h>

using namespace std;
const int c=5000005;
bool v[c];
int w, cnt[c], ert[c], n, m;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> w;
    while (w--) {
        cin >> n >> m;
        int maxi=0, ans=maxi, mini=m, pos=m;
        for (int i=1; i<=n; i++) {
            int x;
            cin >> x;
            v[x]=1;
            cnt[x]=1;
            mini=min(mini, x);
            maxi=max(maxi, x);
        }
        ans=maxi-mini;
        for (int i=1; i<=m; i++) {
            ert[i]=i;
        }
        for (int i=sqrt(m); i>=1; i--) {
            for (int j=i*i; j<=m; j+=i) {
                if (v[j]) cnt[ert[j]]--;
                ert[j]=min(ert[j], ert[j/i]);
                if (v[j]) cnt[ert[j]]++;
            }
            while (!cnt[pos]) pos--;
            if (i<=mini) ans=min(ans, pos-i);
        }
        cout << ans << "\n";

        for (int i=1; i<=m; i++) {
            v[i]=0, cnt[i]=0, ert[i]=0;
        }
    }
    return 0;
}