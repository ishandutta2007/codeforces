#include <bits/stdc++.h>

using namespace std;
int w, n, k, t[105][2], ans;
bool v[205];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> k;
        for (int i=1; i<=k; i++) {
            cin >> t[i][0] >> t[i][1];
            if (t[i][0]>t[i][1]) {
                swap(t[i][0], t[i][1]);
            }
            v[t[i][0]]=1, v[t[i][1]]=1;
        }
        for (int i=1; i<=k; i++) {
            for (int j=1; j<=k; j++) {
                if (t[i][0]>t[j][0] && t[i][1]>t[j][1] && t[j][1]>t[i][0]) {
                    ans++;
                }
            }
            int db=0;
            for (int j=t[i][0]+1; j<t[i][1]; j++) {
                if (!v[j]) {
                    db++;
                }
            }
            ans+=min(db, 2*(n-k)-db);
        }
        ans+=(n-k)*(n-k-1)/2;

        cout << ans << "\n";
        for (int i=1; i<=2*n; i++) {
            v[i]=0;
        }
        ans=0;
    }
    return 0;
}