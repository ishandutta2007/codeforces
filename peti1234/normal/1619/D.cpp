#include <bits/stdc++.h>

using namespace std;
int w, n, m, db[100005], id[100005];
vector<pair<int, pair<int, int> > > sz;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> m;
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                int x;
                cin >> x;
                sz.push_back({x, {i, j}});
            }
        }
        sort(sz.rbegin(), sz.rend());
        int cnt=0, jo=0;
        for (auto x:sz) {
            int ert=x.first, a=x.second.first, b=x.second.second;
            if (!id[b]) {
                cnt++;
                id[b]=1;
            }
            db[a]++;
            if (db[a]>1) jo=1;

            if (jo && cnt==m) {
                cout << ert << "\n";
                break;
            }
        }

        sz.clear();
        for (int i=0; i<=max(n, m); i++) {
            db[i]=0, id[i]=0;
        }
    }
    return 0;
}