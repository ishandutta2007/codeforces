#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        int n, m;
        cin >> n >> m;
        vector<int> sz;
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                sz.push_back(max(i-1, n-i)+max(j-1, m-j));
            }
        }
        sort(sz.begin(), sz.end());
        for (auto x:sz) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}