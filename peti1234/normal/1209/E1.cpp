#include <bits/stdc++.h>

using namespace std;
int q, t[5][101];
vector<pair<int, pair<int, int> > >ma;
int c(int a, int b, int c, int d)
{
    int sum=ma[a].first+ma[b].first+ma[c].first+ma[d].first;
    int af=ma[a].second.first;
    int bf=ma[b].second.first;
    int cf=ma[c].second.first;
    int df=ma[d].second.first;
    int as=ma[a].second.second;
    int bs=ma[b].second.second;
    int cs=ma[c].second.second;
    int ds=ma[d].second.second;
    if ((af+bf+cf+df)%2==0) {
        return sum;
    }
    if(as==bs) {
        if (cs!=ds) {
            return sum;
        }
        if (as!=cs) {
            return 0;
        }

    }
    if ((as==cs && bs==ds) || (as==ds && bs==cs)) {
        return 0;
    }
    return sum;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> q;
    for (int i=1; i<=q; i++) {
        int n, m;
        cin >> n >> m;
        ma.clear();
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                int x;
                cin >> x;
                t[i][j]=x;
                ma.push_back({x, {i, j}});
            }
        }
        sort(ma.rbegin(), ma.rend());
        int sum=0;
        if (n<4 || (n==4 && m==1)) {
            for (int i=0; i<n; i++) {
                sum+=ma[i].first;
            }
        }
        int maxi=0;
        if (n==4 && m>1) {
            maxi=max({c(0, 1, 2, 3), c(0, 1, 2, 4), c(0, 1, 3, 4), c(0, 2, 3, 4), c(1, 2, 3, 4), c(0, 1, 2, 5)});
            sum=maxi;
        }
        cout << sum << "\n";
    }
    return 0;
}