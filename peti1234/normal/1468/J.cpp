#include <bits/stdc++.h>

using namespace std;
const int c=200002;
int w, n, m, k, ki[c], koz;
vector<pair<int, pair<int, int> > > el;
long long ans;
int holvan(int a) {
    if (!ki[a]) {
        return a;
    }
    int x=holvan(ki[a]);
    ki[a]=x;
    return x;
}
bool unio(int a, int b) {
    a=holvan(a), b=holvan(b);
    if (a!=b) {
        ki[a]=b;
        return true;
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n >> m >> k, koz=1e9;
        el.clear(), ans=0;
        for (int i=1; i<=n; i++) {
            ki[i]=0;
        }
        for (int i=1; i<=m; i++) {
            int a, b, c; cin >> a >> b >> c;
            koz=min(koz, abs(c-k));
            el.push_back({max(0, c-k), {a, b}});
        }
        sort(el.begin(), el.end());
        for (int i=0; i<m; i++) {
            int a=el[i].second.first, b=el[i].second.second, c=el[i].first;
            if (unio(a, b)) {
                ans+=c;
            }
        }
        if (!ans) {
            ans+=koz;
        }
        cout << ans << "\n";
    }
    return 0;
}