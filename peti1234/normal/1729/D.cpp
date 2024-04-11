#include <bits/stdc++.h>

using namespace std;
const int c=100005;
int w, n, a[c], b[c], ans;
vector<int> sz;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) cin >> a[i];
        for (int i=1; i<=n; i++) cin >> b[i], sz.push_back({b[i]-a[i]});
        sort(sz.begin(), sz.end());
        int pos=n-1;
        for (int i=0; i<n; i++) {
            if (i<pos && sz[i]+sz[pos]>=0) {
                ans++, pos--;
            }
        }
        cout << ans << "\n";
        ans=0, sz.clear();
    }
    return 0;
}
/*
1
6
1 4 1 2 4 2
1 3 3 2 3 4
*/