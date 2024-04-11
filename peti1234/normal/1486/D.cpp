#include <bits/stdc++.h>

using namespace std;
const int c=200002;
int n, k, t[c], kom[c], mini[c], lo=0, hi=1e6, mid;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    while (hi-lo>1) {
        mid=(hi+lo)/2;
        bool jo=0;
        for (int i=1; i<=n; i++) {
            kom[i]=kom[i-1];
            if (t[i]>=mid) {
                kom[i]++;
            } else {
                kom[i]--;
            }
            mini[i]=min(mini[i-1], kom[i]);
            if (i>=k && kom[i]>mini[i-k]) {
                jo=1;
            }
        }
        if (jo) {
            lo=mid;
        } else {
            hi=mid;
        }
    }
    cout << lo << "\n";
    return 0;
}