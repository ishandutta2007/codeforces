#include <bits/stdc++.h>

using namespace std;
int w, n, t[55];
vector<pair<int, int> > ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
        }
        for (int i=n; i>=1; i--) {
            int maxi=1;
            for (int j=1; j<=i; j++) {
                if (t[j]>t[maxi]) {
                    maxi=j;
                }
            }
            if (maxi!=i) {
                ans.push_back({maxi, i});
                for (int j=maxi; j<i; j++) {
                    swap(t[j], t[j+1]);
                }
            }
        }
        cout << ans.size() << "\n";
        for (auto x:ans) {
            cout << x.first << " " << x.second << " " << 1 << "\n";
        }
        ans.clear();
    }
    return 0;
}