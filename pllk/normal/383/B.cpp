#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

int n, m;
unordered_set<int> s;
unordered_map<int, vector<int> > mm;
vector<int> v;

vector<pair<int, int> > d[2];

int main() {
    cin >> n >> m;
    s.insert(1);
    v.push_back(1);
    mm[1].push_back(n+1);
    s.insert(n);
    v.push_back(n);
    mm[n].push_back(n+1);
    for (int i = 0; i < m; i++) {
        int y, x;
        cin >> x >> y;
        if (!s.count(x)) {
            s.insert(x);
            v.push_back(x);
            mm[x].push_back(n+1);
        }
        if (x-1 >= 1 && !s.count(x-1)) {
            s.insert(x-1);
            v.push_back(x-1);
            mm[x-1].push_back(n+1);
        }
        if (x+1 <= n && !s.count(x+1)) {
            s.insert(x+1);
            v.push_back(x+1);
            mm[x+1].push_back(n+1);
        }
        mm[x].push_back(y);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
        sort(mm[v[i]].begin(), mm[v[i]].end());
    }
    d[0].push_back(make_pair(1, 1));
    int c = 1;
    bool ok = false;
    for (int i = 0; i < v.size(); i++) {
        d[c].clear();
        int vy = 0;
        int q = 0;
        if (d[1-c].size() == 0) break;
        for (int j = 0; j < mm[v[i]].size(); j++) {
            int y1 = vy+1;
            int y2 = mm[v[i]][j]-1;
            vy = mm[v[i]][j];
            while (q+1 < d[1-c].size() && d[1-c][q].second < y1) q++;
            if (d[1-c][q].second < y1 || d[1-c][q].first > y2) continue;
            int uy = max(y1, d[1-c][q].first);
            if (uy > y2) continue;
            d[c].push_back(make_pair(uy, y2));
            //cout << v[i] << " " << uy << " " << y2 << endl;
            if (v[i] == n && y2 == n) ok = true;
        }
        c = 1-c;
    }
    if (ok) cout << n+n-2 << endl;
    else cout << -1 << endl;
}