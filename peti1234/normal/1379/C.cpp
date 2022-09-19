#include <bits/stdc++.h>

using namespace std;
int w, n, m, pos;
long long sum, maxi, q;
vector<pair<int, int> > sz;
vector<int> t;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> m >> n, pos=0, maxi=0, sum=0, sz.clear(), t.clear();
        for (int i=1; i<=n; i++) {
            int x, y; cin >> x >> y;
            t.push_back(x), sz.push_back({y, x});
        }
        sort(t.rbegin(), t.rend()), sort(sz.rbegin(), sz.rend());
        for (int i=0; i<n; i++) {
            long long fi=sz[i].first, se=sz[i].second; q=0;
            while(pos<n && t[pos]>=fi) {
                sum+=t[pos], pos++;
                if (pos==m) maxi=max(maxi, sum);
            }
            if (fi>se) q=se-fi;
            if (m>pos) maxi=max(maxi, sum+(m-pos)*fi+q);
        }
        cout << maxi << "\n";
    }
    return 0;
}