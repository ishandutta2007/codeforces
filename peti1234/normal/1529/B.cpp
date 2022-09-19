#include <bits/stdc++.h>

using namespace std;
int w, n, mini, ans;
vector<int> sz;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        mini=2e9, ans=0, sz.clear();
        for (int i=0; i<n; i++) {
            int x;
            cin >> x;
            sz.push_back(x);
        }
        sort(sz.begin(), sz.end());
        if (sz[0]>0) {
            cout << 1 << "\n";
            continue;
        }
        if (sz[n-1]<=0) {
            cout << n << "\n";
            continue;
        }
        for (int i=1; i<n; i++) {
            mini=min(mini, sz[i]-sz[i-1]);
            if (sz[i]>0) {
                ans=i;
                break;
            }
        }
        cout << ans+(mini>=sz[ans]) << "\n";
    }
    return 0;
}