#include <bits/stdc++.h>

using namespace std;
long long ans[200005], w, n, sum;
vector<pair<long long, int> > sz;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            long long x;
            cin >> x;
            sz.push_back({x, i});
        }
        sort(sz.rbegin(), sz.rend());
        for (int i=0; i<n; i++) {
            long long db=sz[i].first, pos=sz[i].second;
            sum+=db*(i/2+1)*2;
            if (i%2==0) ans[pos]=i/2+1;
            else ans[pos]=-(i/2+1);
        }

        cout << sum << "\n";
        for (int i=0; i<=n; i++) cout << ans[i] << " ";
        cout << "\n";

        sum=0;
        sz.clear();
    }
    return 0;
}