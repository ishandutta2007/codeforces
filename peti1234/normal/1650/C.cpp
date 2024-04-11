#include <bits/stdc++.h>

using namespace std;
const int c=200005;
long long w, n, m, sum, pos[c], t[c];
vector<pair<int, int> > r1, r2;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> m;
        for (int i=1; i<=m; i++) {
            cin >> pos[i] >> t[i];
            r1.push_back({t[i], i});
        }
        sort(r1.begin(), r1.end());
        for (int i=0; i<2*n; i++) {
            int id=r1[i].second;
            sum+=t[id];
            r2.push_back({pos[id], id});
        }
        sort(r2.begin(), r2.end());

        cout << sum << "\n";
        for (int i=0; i<n; i++) {
            cout << r2[i].second << " " <<r2[2*n-1-i].second << "\n";
        }

        sum=0;
        r1.clear(), r2.clear();
    }
    return 0;
}