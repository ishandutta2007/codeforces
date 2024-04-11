#include <bits/stdc++.h>

using namespace std;
int n, d, ans;
vector<pair<int, pair<int, int> > > sz;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> d;
    for (int i=1; i<=n; i++) {
        int a, b;
        cin >> a >> b;
        sz.push_back({max(a, b), {a, b}});
    }
    sort(sz.begin(), sz.end());
    for (auto x:sz) {
        int a=x.second.first, b=x.second.second;
        if (a>=d) {
            ans++;
            d=max(d, b);
        }
    }
    cout << ans << "\n";
    return 0;
}