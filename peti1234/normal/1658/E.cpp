#include <bits/stdc++.h>

using namespace std;
int n, k, dx[4]={1, 1, -1, -1}, dy[4]={1, -1, 1, -1};
pair<int, int> jo[4];
vector<pair<int, pair<int, int> > > sz;
set<pair<int, int> > s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            int x;
            cin >> x;
            sz.push_back({x, {i, j}});
        }
    }
    sort(sz.rbegin(), sz.rend());
    for (int i=0; i<4; i++) {
        jo[i]=sz[0].second;
        s.insert(sz[0].second);
    }
    for (int i=1; i<n*n; i++){
        pair<int, int> p=sz[i].second;
        //cout << "fontos " << p.first << " " << p.second << "\n";
        bool spec=1;
        for (int j=0; j<4; j++) {
            if (abs(p.first-jo[j].first)+abs(p.second-jo[j].second)>k) {
                spec=0;
            }
        }
        if (spec) {
            s.insert({p});
            for (int j=0; j<4; j++) {
                if (p.first*dx[j]+p.second*dy[j]>jo[j].first*dx[j]+jo[j].second*dy[j]) {
                    jo[j]=p;
                }
            }
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cout << (s.find({i, j})==s.end() ? "G" : "M");
        }
        cout << "\n";
    }
    return 0;
}