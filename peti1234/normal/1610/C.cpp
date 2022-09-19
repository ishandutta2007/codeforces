#include <bits/stdc++.h>

using namespace std;
int w, n, r[200005], p[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) cin >> r[i] >> p[i];
        int lo=0, hi=n+1, mid;
        while (hi-lo>1) {
            mid=(hi+lo)/2;
            int pos=0;
            for (int i=1; i<=n; i++) {
                if (p[i]>=pos && r[i]>=mid-1-pos) {
                    pos++;
                }
            }
            if (pos>=mid) lo=mid;
            else hi=mid;
        }
        cout << lo << "\n";
    }
    return 0;
}