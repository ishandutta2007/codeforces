#include <bits/stdc++.h>

using namespace std;
int w, n, p;
vector<pair<int, int> > a, b;
int t[502];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n, p=0, a.clear(), b.clear();
        for (int i=1; i<=n; i++) cin >> t[i];
        for (int i=1; i<=n/2; i++) {
            int x=t[i], y=t[n+1-i];
            if (x>y) swap(x, y);
            a.push_back({x, y});
        }
        if (n%2) a.push_back({0, t[(n+1)/2]});
        for (int i=1; i<=n; i++) cin >> t[i];
        for (int i=1; i<=n/2; i++) {
            int x=t[i], y=t[n+1-i];
            if (x>y) swap(x, y);
            b.push_back({x, y});
        }
        if (n%2) b.push_back({0, t[(n+1)/2]});
        sort(a.begin(), a.end()), sort(b.begin(), b.end());
        for (int i=0; i<a.size(); i++) if (a[i].first!=b[i].first || a[i].second!=b[i].second) p=1;
        if (p) cout << "No\n";
        else cout << "Yes\n";
    }
    return 0;
}