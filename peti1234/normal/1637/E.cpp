#include <bits/stdc++.h>

using namespace std;
const int c=300005;
int w, n, m;
vector<int> sz[c];
map<int, int> db;
set<int> s;
set<pair<int, int> > rossz, proba;
priority_queue<pair<long long, pair<int, int> > > q;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> m;
        for (int i=1; i<=n; i++) {
            int x;
            cin >> x;
            db[x]++;
        }
        for (auto p:db) {
            sz[p.second].push_back(p.first);
            s.insert(p.second);
        }
        for (int i=1; i<=m; i++) {
            int a, b;
            cin >> a >> b;
            if (a>=b) {
                swap(a, b);
            }
            rossz.insert({a, b});
        }
        for (auto p:s) {
            sort(sz[p].rbegin(), sz[p].rend());
        }

        long long ans=0;
        for (auto i:s) {
            for (auto j:s) {
                if (i>j) continue;
                long long db=i+j;
                int si=sz[i].size(), sj=sz[j].size();
                q.push({sz[i][0]+sz[j][0], {0, 0}});
                //cout << "kezd " << db << " " << i << " " << j << "\n";
                bool jo=0;
                while (q.size()>0) {
                    long long sum=q.top().first;
                    int a=q.top().second.first, b=q.top().second.second, aa=sz[i][a], bb=sz[j][b];
                    //cout << "proba " << aa << " " << bb << "\n";
                    q.pop();
                    if (aa>bb) swap(aa, bb);
                    if (jo || proba.find({aa, bb})!=proba.end()) continue;
                    proba.insert({aa, bb});
                    if (aa!=bb && rossz.find({aa, bb})==rossz.end()) {
                        ans=max(ans, db*sum);
                        //cout << "fontos " << aa << " " << bb << "\n";
                        jo=1;
                    }
                    if (!jo && a+1<si) q.push({sz[i][a+1]+sz[j][b], {a+1, b}});
                    if (!jo && b+1<sj) q.push({sz[i][a]+sz[j][b+1], {a, b+1}});
                }
            }
        }
        cout << ans << "\n";

        // nullazas
        rossz.clear(), proba.clear();
        for (auto p:s) {
            sz[p].clear();
        }
        s.clear();
        db.clear();
    }
    return 0;
}
/*
1
6 1
6 3 6 7 3 3
3 6
*/