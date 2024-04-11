#include <bits/stdc++.h>

using namespace std;
const int c=105;
long long w, n, pos[c], ert[c], o=0;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) cin >> pos[i];
        for (int i=1; i<=n; i++) cin >> ert[i];
        long long veg=pos[n], kezd=pos[n], ans=0;
        for (int i=n; i>=0; i--) {
            if (pos[i]<=kezd) {
                ans+=(veg-kezd)*(veg-kezd+1)/2;
                veg=pos[i];
            }
            kezd=min(kezd, pos[i]-ert[i]);
        }

        cout << ans << "\n";
    }
    return 0;
}