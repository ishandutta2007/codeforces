#include <bits/stdc++.h>

using namespace std;
int w, n, mini;
vector<int> sz;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        sz.clear(), mini=1e9;
        for (int i=1; i<=n; i++) {
            int x;
            cin >> x;
            sz.push_back(x);
        }
        sort(sz.begin(), sz.end());
        for (int i=1; i<n; i++) {
            mini=min(mini, sz[i]-sz[i-1]);
        }
        for (int i=1; i<n; i++) {
            if (sz[i]-sz[i-1]==mini) {
                cout << sz[i-1] << " ";
                for (int j=i+1; j<n; j++) {
                    cout << sz[j] << " ";
                }
                for (int j=0; j<i-1; j++) {
                    cout << sz[j] << " ";
                }
                cout << sz[i] << "\n";
                break;
            }
        }
    }
    return 0;
}