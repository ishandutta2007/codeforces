#include <bits/stdc++.h>

using namespace std;
const int c=1<<18;
int w, n, q, po=1, t[c], kezd[c], veg[c];
vector<int> sz[c], s;
void solve(int a, int l, int r) {
    if (kezd[a]>r || veg[a]<l) return;
    if (l<=kezd[a] && veg[a]<=r) {
        for (auto x:sz[a]) {
            //cout << "fontos " << a << " " << kezd[a] << " " << veg[a] << " " << x << "\n";
            s.push_back(x);
        }
        return;
    }
    solve(2*a, l, r), solve(2*a+1, l, r);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
        }
        while (po<=n) po*=2;
        for (int i=po; i<2*po; i++) {
            kezd[i]=i-po, veg[i]=i-po;
            if (1<=i-po && i-po<=n) {
                sz[i].push_back(t[i-po]);
            }
        }
        for (int i=po-1; i>=1; i--) {
            kezd[i]=kezd[2*i], veg[i]=veg[2*i+1];
            for (auto x:sz[2*i]) sz[i].push_back(x);
            for (auto x:sz[2*i+1]) sz[i].push_back(x);
            sort(sz[i].begin(), sz[i].end());
            while (sz[i].size()>31) sz[i].pop_back();
        }
        for (int i=1; i<2*po; i++) {
            //cout << i << " " << kezd[i] << " " << veg[i] << " " << sz[i].size() << "\n";
        }
        cin >> q;
        while (q--) {
            int l, r;
            cin >> l >> r;
            solve(1, l, r);
            sort(s.begin(), s.end());
            int si=min(31, (int)s.size());
            int mini=1<<30;
            for (int i=0; i<si; i++) {
                for (int j=i+1; j<si; j++) {
                    mini=min(mini, s[i]|s[j]);
                }
            }
            cout << mini << "\n";
            s.clear();
        }

        for (int i=0; i<2*po; i++) {
            t[i]=0, kezd[i]=0, veg[i]=0;
            sz[i].clear();
        }
        po=1;
    }
    return 0;
}
/*
1
4
0 2 1 1073741823
1
3 4
*/