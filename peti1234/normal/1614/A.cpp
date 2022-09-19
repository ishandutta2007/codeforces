#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    long long w, n, l, r, k, x;
    cin >> w;
    while (w--) {
        cin >> n >> l >> r >> k;
        vector<long long> sz;
        int cnt=0;
        for (int i=1; i<=n; i++) {
            long long x;
            cin >> x;
            sz.push_back(x);
        }
        sort(sz.begin(), sz.end());
        for (auto x:sz) {
            if (l<=x && x<=r && x<=k) k-=x, cnt++;
        }
        cout << cnt << "\n";
    }
    return 0;
}