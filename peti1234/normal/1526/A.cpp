#include <bits/stdc++.h>

using namespace std;
int w, n;
vector<int> sz;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        sz.clear();
        for (int i=0; i<2*n; i++) {
            int x;
            cin >> x;
            sz.push_back(x);
        }
        sort(sz.begin(), sz.end());
        for (int i=0; i<n; i++) {
            cout << sz[i] << " " << sz[2*n-1-i] << " ";
        }
        cout << "\n";
    }
    return 0;
}