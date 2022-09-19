#include <bits/stdc++.h>

using namespace std;
const int c=300002;
int n, t[c], kk, nk, ps, pn;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n, kk=(n+1)/2, nk=(n+2)/2;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    ps=max(t[kk], t[nk]);
    if (n%2==0) {
        pn=min(t[kk], t[nk]);
    }
    for (int i=0; i<n-1; i++) {
        int s=(i+n%2)/2;
        if ((n-i)%2) {
            pn=max({pn, min(t[kk-s-1], t[kk-s]), min(t[nk+s], t[nk+s+1])});
            cout << pn << " ";
        } else {
            ps=max({ps, t[kk-s], t[nk+s]});
            cout << ps << " ";
        }
    }
    cout << ps << " ";
    return 0;
}