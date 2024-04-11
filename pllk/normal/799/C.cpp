#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int n, c, d;
int b[101010];
int p[101010];
string t[101010];
int u;

int lol(vector<pair<int,int>> v, int w) {
    int e = 0;
    sort(v.begin(),v.end());
    multiset<pair<int,int>> s1, s2;
    for (int i = 0; i < v.size(); i++) {
        int up = v[i].first;
        int ub = v[i].second;
        while (s1.size()) {
            auto z = *s1.rbegin();
            int zp = z.first;
            int zb = z.second;
            if (zp+up <= w) break;
            s1.erase(s1.find({zp,zb}));
            s2.erase(s2.find({zb,zp}));
        }
        if (s2.size()) {
            e = max(e,ub+(*s2.rbegin()).first);
        }
        s1.insert({up,ub});
        s2.insert({ub,up});
    }
    return e;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> c >> d;
    int cb = -1;
    int db = -1;
    for (int i = 1; i <= n; i++) {
        cin >> b[i] >> p[i] >> t[i];
        if (t[i] == "C" && p[i] <= c && b[i] > cb) cb = b[i];
        if (t[i] == "D" && p[i] <= d && b[i] > db) db = b[i];
    }
    if (cb >= 0 && db >= 0) {
        u = cb+db;
    }
    vector<pair<int,int>> v;
    for (int i = 1; i <= n; i++) {
        if (t[i] == "C") v.push_back({p[i],b[i]});
    }
    u = max(u,lol(v,c));
    v.clear();
    for (int i = 1; i <= n; i++) {
        if (t[i] == "D") v.push_back({p[i],b[i]});
    }
    u = max(u,lol(v,d));
    cout << u << "\n";
}