#include <bits/stdc++.h>

using namespace std;
int n, k, t[100005], ert=1e9;
void solve() {
    cin >> n >> k;
    vector<pair<int, int> > sz;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        sz.push_back({t[i], i});
    }
    //cout << "valasz....................... ";
    if (k==n) {
        cout << ert << "\n";
        return;
    }
    sort(sz.begin(), sz.end());
    for (int i=0; i<k-1; i++) {
        t[sz[i].second]=ert;
    }
    int val=sz[k-1].first, kov=sz[k].first, kis=0, nagy=0, pos=sz[k-1].second;
    if (pos>1) {
        kis=max(kis, t[pos-1]);
    }
    if (pos<n) {
        kis=max(kis, t[pos+1]);
    }
    for (int i=1; i<n; i++) {
        kis=max(kis, min(t[i], t[i+1]));
        nagy=max(nagy, max(t[i], t[i+1]));
    }
    cout << max(min(2*val, nagy), min(2*kov, kis)) << "\n";
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
3 2
1 9 84
*/