#include <bits/stdc++.h>

using namespace std;
long long w, n, h;
vector<long long> sz;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> h;
        for (int i=1; i<=n; i++) {
            int x;
            cin >> x;
            sz.push_back(x);
        }
        sort(sz.rbegin(), sz.rend());
        long long s=sz[0]+sz[1];
        if (sz[0]>=h) {
            cout << 1 << "\n";
        } else {
            cout << min((h+s-1)/s*2, (h-sz[0]+s-1)/s*2+1) << "\n";
        }
        sz.clear();
    }
    return 0;
}