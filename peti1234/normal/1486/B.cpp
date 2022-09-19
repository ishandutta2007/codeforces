#include <bits/stdc++.h>

using namespace std;
int w, n;
vector<long long> x, y;
long long ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        x.clear(), y.clear();
        for (int i=1; i<=n; i++) {
            int a, b; cin >> a >> b;
            x.push_back(a), y.push_back(b);
        }
        sort(x.begin(), x.end()), sort(y.begin(), y.end());
        if (n%2) {
            ans=1;
        } else {
            ans=(x[n/2]-x[n/2-1]+1)*(y[n/2]-y[n/2-1]+1);
        }
        cout << ans << "\n";
    }
    return 0;
}