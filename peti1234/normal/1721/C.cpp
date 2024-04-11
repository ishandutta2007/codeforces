#include <bits/stdc++.h>

using namespace std;
const int c=200005;
int n, a[c], b[c], kov[c];
void solve() {
    cin >> n;
    for (int i=1; i<=n; i++) cin >> a[i];
    for (int i=1; i<=n; i++) cin >> b[i];
    kov[n+1]=n+1;
    for (int i=n; i>=1; i--) {
        if (a[i]>b[i-1]) kov[i]=i;
        else kov[i]=kov[i+1];
    }
    for (int i=1; i<=n; i++) {
        int lo=0, hi=i, mid;
        while (hi-lo>1) {
            mid=(hi+lo)/2;
            if (b[mid]>=a[i]) hi=mid;
            else lo=mid;
        }
        cout << b[hi]-a[i] << " ";
    }
    cout << "\n";
    for (int i=1; i<=n; i++) {
        cout << b[kov[i+1]-1]-a[i] << " ";
    }
    cout << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        solve();
    }
    return 0;
}
/*
1
5
1 0 0 3 3
2 3 2 1 0
*/