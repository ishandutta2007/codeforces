#include <bits/stdc++.h>

using namespace std;
const int c=200005;
long long w, n, m, mini, maxi, sum, cnt, pos[c], ert[c];
vector<pair<int, int> > sz;
void pb(int a, int b) {
    sz.push_back({a, b});
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> m;
        for (int i=1; i<=n; i++) {
            cin >> pos[i] >> ert[i];
            pb(pos[i]-ert[i], 1), pb(pos[i], -1), pb(pos[i], -1), pb(pos[i]+ert[i], 1);
        }
        sort(sz.begin(), sz.end());
        mini=1e12, maxi=-1e12;
        for (int i=0; i<4*n; i++) {
            int pos=sz[i].first;
            if (i) sum+=cnt*(pos-sz[i-1].first);
            //cout << "fontos " << pos << " " << sum << "\n";
            if (sum>m) {
                mini=min(mini, pos-sum+m);
                maxi=max(maxi, pos+sum-m);
            }
            cnt+=sz[i].second;
        }
        //cout << "valasz.......... ";
        for (int i=1; i<=n; i++) {
            cout << (pos[i]-ert[i]<=mini && maxi<=pos[i]+ert[i] ? 1 : 0);
        }
        cout << "\n";


        sum=0;
        sz.clear();
    }
    return 0;
}
/*
1
6 12
4 5
1 6
12 5
5 5
9 7
8 3
*/