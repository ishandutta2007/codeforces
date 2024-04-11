#include <bits/stdc++.h>

using namespace std;
const int c=10015, gy=300;
long long ans;
int n, k;
vector<pair<int, pair<int, int> > > sz;
vector<int> s[c], spec[c];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i=1; i<=n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        sz.push_back({b, {a, c}});
    }
    sort(sz.rbegin(), sz.rend());
    for (auto p:sz) {
        int pos=p.second.first, kezd=pos-p.first, veg=pos+p.first, f=p.second.second;
        for (int i=max(1, f-k); i<=f+k; i++) {
            for (auto x:spec[i]) {
                if (kezd<=x && x<=veg) {
                    ans++;
                }
            }
            ans+=upper_bound(s[i].begin(), s[i].end(), veg)-lower_bound(s[i].begin(), s[i].end(), kezd);
        }
        spec[f].push_back(pos);
        if (spec[f].size()==gy) {
            for (auto x:spec[f]) {
                s[f].push_back(x);
            }
            spec[f].clear();
            sort(s[f].begin(), s[f].end());
        }
    }
    cout << ans << "\n";
    return 0;
}