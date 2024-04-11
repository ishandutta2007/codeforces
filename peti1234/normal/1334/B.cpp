#include <bits/stdc++.h>

using namespace std;
long long w, n, x, sum, ans;
vector<long long> sz;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n >> x;
        ans=0, sum=0, sz.clear();
        for (int i=1;i<=n; i++) {
            int a;
            cin >> a;
            sz.push_back(a);
        }
        sort(sz.rbegin(), sz.rend());
        for (int i=0; i<n; i++) {
            sum+=sz[i];
            if (sum/(i+1)>=x) ans=i+1;
        }
        cout << ans << "\n";
    }
    return 0;
}
// Knnyen ment.