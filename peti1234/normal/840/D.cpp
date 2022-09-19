#include <bits/stdc++.h>

using namespace std;
const int c=300002;
int n, q, db[c], t[c], l=1, r, sol[c], kezd[c], veg[c], sp[c];
vector<pair<int, int> > sz;
int main()
{
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    ios_base::sync_with_stdio(false), cin.tie(0);
    cin >> n >> q;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    for (int i=1; i<=q; i++) {
        long long a, b, k, ert; cin >> a >> b >> k, ert=(a/400)*c+b;
        sz.push_back({ert, i});
        kezd[i]=a, veg[i]=b, sp[i]=k;
    }
    sort(sz.begin(), sz.end());
    for (int i=0; i<q; i++) {
        int ki=sz[i].second, a=kezd[ki], b=veg[ki];
        while (r<b) {
            r++;
            db[t[r]]++;
        }
        while (l>a) {
            l--;
            db[t[l]]++;
        }
        while (r>b) {
            db[t[r]]--;
            r--;
        }
        while (l<a) {
            db[t[l]]--;
            l++;
        }
        int mini=c;
        for (int j=1; j<=100; j++) {
            int x=uniform_int_distribution<int>(a, b)(rng);
            if (sp[ki]*db[t[x]]>b-a+1) {
                mini=min(mini, t[x]);
            }
        }
        if (mini==c) {
            mini=-1;
        }
        sol[ki]=mini;
    }
    for (int i=1; i<=q; i++) {
        cout << sol[i] << "\n";
    }
    return 0;
}