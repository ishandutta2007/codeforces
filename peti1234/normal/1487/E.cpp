#include <bits/stdc++.h>

using namespace std;
const int k=5, c=150002;
int p=4, t[k], ert[k][c];
bool v[k][c];
vector<pair<int, int> > s;
vector<pair<int, int> > uj;
set<int> el[k][c], akt;
int main()
{
    ios_base::sync_with_stdio(false);
    for (int i=1; i<=p; i++) {
        cin >> t[i];
    }
    for (int i=1; i<=p; i++) {
        for (int j=1; j<=t[i]; j++) {
            cin >> ert[i][j];
            if (i==1) {
                s.push_back({ert[i][j], j});
            }
        }
    }
    for (int i=1; i<p; i++) {
        int m; cin >> m;
        for (int j=1; j<=m; j++) {
            int a, b; cin >> a >> b;
            el[i][a].insert(b);
        }
    }
    for (int i=1; i<p; i++) {
        sort(s.begin(), s.end());
        for (int j=1; j<=t[i+1]; j++) {
            akt.insert(j);
        }
        for (auto j:s) {
            uj.clear();
            int val=j.first, id=j.second;
            for (auto it:akt) {
                if (el[i][id].find(it)==el[i][id].end()) {
                    uj.push_back({it, val});
                }
            }
            for (auto p:uj) {
                int id=p.first, val=p.second;
                ert[i+1][id]+=val;
                v[i+1][id]=1;
                akt.erase(id);
            }
        }
        s.clear();
        akt.clear();
        for (int j=1; j<=t[i+1]; j++) {
            if (v[i+1][j]) {
                s.push_back({ert[i+1][j], j});
            }
        }
    }
    if (s.size()==0) {
        cout << -1 << "\n";
    }
    else {
        sort(s.begin(), s.end());
        cout << s[0].first << "\n";
    }
    return 0;
}
/*
1 1 1 1
1
1
1
1
0
0
0
*/