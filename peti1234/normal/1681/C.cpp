#include <bits/stdc++.h>

using namespace std;
int w, n, a[105], b[205];
vector<pair<int, int> > ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            cin >> a[i];
        }
        for (int i=1; i<=n; i++) {
            cin >> b[i];
        }
        for (int i=1; i<=n; i++) {
            for (int j=i+1; j<=n; j++) {
                if (a[i]>a[j] || a[i]==a[j] && b[i]>b[j]) {
                    swap(a[i], a[j]);
                    swap(b[i], b[j]);
                    ans.push_back({i, j});
                }
            }
        }
        bool baj=0;
        for (int i=1; i<n; i++) {
            if (a[i]>a[i+1] || b[i]>b[i+1]) {
                baj=1;
            }
        }
        if (baj) {
            cout << -1 << "\n";
        } else {
            cout << ans.size() << "\n";
            for (auto p:ans) {
                cout << p.first << " " << p.second << "\n";
            }
        }
        ans.clear();
    }
    return 0;
}
/*
1
4
2 3 1 2
2 3 2 3
*/