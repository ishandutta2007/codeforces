#include <bits/stdc++.h>

using namespace std;
long long n, w, ans, t[100005], maxi;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        ans=0, maxi=0;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
            if (1<i && i<n){
                ans+=((t[i]+1)/2);
                maxi=max(maxi, t[i]);
            }
        }
        if (n==3 && t[2]%2 || maxi==1) {
            cout << -1 << "\n";
        } else {
            cout << ans << "\n";
        }
    }
    return 0;
}