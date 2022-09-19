#include <bits/stdc++.h>

using namespace std;
const int c=5005;
long long w, n, x, t[c], maxi[c], sok=1e12;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> x;
        for (int i=1; i<=n; i++) {
            maxi[i]=-sok;
        }
        for (int i=1; i<=n; i++) {
            cin >> t[i];
        }
        for (int i=1; i<=n; i++) {
            long long sum=0;
            for (int j=i; j<=n; j++) {
                sum+=t[j];
                maxi[j-i+1]=max(maxi[j-i+1], sum);
            }
        }
        for (int db=0; db<=n; db++) {
            long long ans=0;
            for (int i=1; i<=n; i++) {
                ans=max(ans, maxi[i]+x*min(db, i));
            }
            cout << ans << " ";
        }
        cout << "\n";

    }
    return 0;
}