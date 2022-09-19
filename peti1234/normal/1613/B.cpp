#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int w, n;
    cin >> w;
    while (w--) {
        cin >> n;
        vector<int> sz;
        for (int i=0; i<n; i++) {
            int x;
            cin >> x;
            sz.push_back(x);
        }
        sort(sz.begin(), sz.end());
        for (int i=1; i<=n/2; i++) {
            cout << sz[i] << " " << sz[0] << "\n";
        }
    }
    return 0;
}