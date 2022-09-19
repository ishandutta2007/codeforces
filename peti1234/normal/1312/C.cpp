#include <bits/stdc++.h>

using namespace std;
int w;
long long t[102], n, k, sum, sok=1e16;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n >> k, sum=1;
        for (int i=1; i<=n; i++) cin >> t[i];
        while(sum<=sok) {
            for (int i=1; i<=n; i++) if (t[i]%(sum*k)) {
                t[i]-=sum;
                break;
            }
            sum*=k;
        }
        bool v=0;
        for (int i=1; i<=n; i++) if (t[i]) v=1;
        if (v) cout << "NO" << "\n";
        else cout << "YES" << "\n";
    }
    return 0;
}