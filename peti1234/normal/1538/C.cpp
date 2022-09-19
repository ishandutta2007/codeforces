#include <bits/stdc++.h>

using namespace std;
int w, n, l, r, t[200002];
long long ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> l >> r;
        ans=0;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
        }
        sort(t+1, t+n+1);
        for (int i=1; i<=n; i++) {
            int lo=i, hi=n+1, mid, s;
            while (hi-lo>1) {
                mid=(hi+lo)/2;
                if (t[i]+t[mid]>r) {
                    hi=mid;
                } else {
                    lo=mid;
                }
            }
            s=lo, lo=i, hi=n+1;
            while (hi-lo>1) {
                mid=(hi+lo)/2;
                if (t[i]+t[mid]<l) {
                    lo=mid;
                } else {
                    hi=mid;
                }
            }
            ans+=s-lo;
        }
        cout << ans << "\n";
    }
    return 0;
}