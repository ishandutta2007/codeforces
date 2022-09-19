#include <bits/stdc++.h>

using namespace std;
int w, n, k, sum, a[32], b[32];
vector<int> sz;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n >> k, sum=0, sz.clear();
        for (int i=1; i<=n; i++) cin >> a[i], sum+=a[i];
        for (int i=1; i<=n; i++) cin >> b[i];
        sort(a+1, a+n+1), sort(b+1, b+n+1);
        for (int i=1; i<=n; i++) sz.push_back(b[n+1-i]-a[i]);
        for (int i=0; i<k; i++) sum+=max(0, sz[i]);
        cout << sum << "\n";
    }
    return 0;
}