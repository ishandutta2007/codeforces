#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int n, q;
vector<int> v[303030];
int c[303030];

void haku1(int s, int e) {
    c[s]++;
    for (int i = 0; i < v[s].size(); i++) {
        if (v[s][i] == e) continue;
        haku1(v[s][i],s);
        c[s] += c[v[s][i]];
    }
}

set<pair<int,int>> z;
int r[303030];

void haku2(int s, int e) {
    z.insert({c[s],s});
    int x = c[s];
    int y = 0;
    vector<pair<int,int>> u;
    for (int i = 0; i < v[s].size(); i++) {
        if (v[s][i] == e) continue;
        y = max(y,c[v[s][i]]);
        u.push_back({-c[v[s][i]],v[s][i]});
    }
    while (z.size() > 0) {
        auto f = z.rbegin();
        int a, b;
        if (f->first%2 == 0) {a = f->first/2; b = f->first/2;}
        if (f->first%2 == 1) {a = f->first/2+1; b = f->first/2;}
        if (x >= a && y <= b) {
            r[f->second] = s;
            z.erase(*f);
        } else {
            break;
        }
    }
    sort(u.begin(),u.end());
    for (int i = 0; i < u.size(); i++) {
        haku2(u[i].second,s);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for (int i = 2; i <= n; i++) {
        int x;
        cin >> x;
        v[x].push_back(i);
    }
    haku1(1,0);
    haku2(1,0);
    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;
        cout << r[x] << "\n";
    }
}