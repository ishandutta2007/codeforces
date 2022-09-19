#include <bits/stdc++.h>

using namespace std;
int n, a, b, k, x, ans;
vector<int> sz;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> a >> b >> k;
    for (int i=1; i<=n; i++) {
        cin >> x;
        x%=(a+b);
        if (!x) {
            x=a+b;
        }
        sz.push_back((x-1)/a);
    }
    sort(sz.begin(), sz.end());
    for (int i=0; i<n; i++) {
        if (k>=sz[i]) {
            ans++;
            k-=sz[i];
        }
    }
    cout << ans << "\n";
    return 0;
}