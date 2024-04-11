#include <bits/stdc++.h>

using namespace std;
int w, n;
vector<int> sz;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        sz.clear();
        cin >> n;
        for (int i=0; i<2*n; i++) {
            int x;
            cin >> x;
            sz.push_back(x);
        }
        sort(sz.begin(), sz.end());
        cout << sz[n]-sz[n-1] << "\n";
    }
    return 0;
}