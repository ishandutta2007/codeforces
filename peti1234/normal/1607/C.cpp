#include <bits/stdc++.h>

using namespace std;
long long w, n, ans;
vector<long long> sz;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            int x;
            cin >> x;
            sz.push_back(x);
        }
        sort(sz.begin(), sz.end());
        ans=sz[0];
        for (int i=1; i<n; i++) {
            ans=max(ans, sz[i]-sz[i-1]);
        }
        //cout << "valasz................ ";
        cout << ans << "\n";
        sz.clear();
    }
    return 0;
}