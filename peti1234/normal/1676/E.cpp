#include <bits/stdc++.h>

using namespace std;
const int c=200005;
long long n, q, t[c], pref[c];
int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        cin >> n >> q;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
        }
        sort(t+1, t+n+1);
        reverse(t+1, t+n+1);
        for (int i=1; i<=n; i++) {
            pref[i]=pref[i-1]+t[i];
        }
        while (q--) {
            long long x;
            cin >> x;
            long long lo=0, hi=n+1, mid;
            while (hi-lo>1) {
                mid=(hi+lo)/2;
                if (pref[mid]>=x) hi=mid;
                else lo=mid;
            }
            cout << (hi==n+1 ? -1 : hi) << "\n";
        }
    }
    return 0;
}