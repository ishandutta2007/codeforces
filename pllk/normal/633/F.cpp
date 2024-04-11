#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

typedef long long ll;

int n;
int a[101010];
vector<int> v[101010];
vector<pair<int,int>> z;

map<int,map<int,ll>> d1;
map<int,map<int,ll>> d2;

pair<ll,int> e1[101010][3];
pair<ll,int> e2[101010][3];

void laske(int s, int e) {
    if (d1[s].count(e)) return;
    ll p1 = 0, p2 = 0, p3 = 0;
    vector<int> x;
    for (int i = 0; i < v[s].size(); i++) {
        int u = v[s][i];
        if (u == e) continue;
        laske(u, s);
        if (d1[u][s] > e1[s][0].first) e1[s][0] = {d1[u][s],u};
        sort(e1[s], e1[s]+3);
        if (d2[u][s] > e2[s][0].first) e2[s][0] = {d2[u][s],u};
        sort(e2[s], e2[s]+3);
        v[s][i] = v[s][v[s].size()-1];
        v[s].pop_back();
        i--;
    }
    if (e1[s][2].second == e) {
        d1[s][e] = a[s]+e1[s][1].first;
    } else {
        d1[s][e] = a[s]+e1[s][2].first;
    }
    if (e2[s][2].second == e) {
        d2[s][e] = e2[s][1].first;
    } else {
        d2[s][e] = e2[s][2].first;
    }
    if (e1[s][2].second == e) {
        d2[s][e] = max(d2[s][e], a[s]+e1[s][0].first+e1[s][1].first);
    } else if (e1[s][1].second == e) {
        d2[s][e] = max(d2[s][e], a[s]+e1[s][0].first+e1[s][2].first);
    } else {
        d2[s][e] = max(d2[s][e], a[s]+e1[s][1].first+e1[s][2].first);
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n-1; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
        z.push_back({a,b});
    }
    ll p = 0;
    for (int i = 0; i < z.size(); i++) {
        int a = z[i].first;
        int b = z[i].second;
        laske(a,b);
        laske(b,a);
        ll u = d2[a][b]+d2[b][a];
        p = max(p,u);
    }
    cout << p << "\n";
}