#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<pair<int,int>> v1, v2;
int uu[20];

int main() {
    cin >> n >> m;
    v1.resize(n);
    v2.resize(m);
    for (int i = 0; i < n; i++) {
        cin >> v1[i].first >> v1[i].second;
        if (v1[i].first > v1[i].second) swap(v1[i].first,v1[i].second);
    }
    for (int i = 0; i < m; i++) {
        cin >> v2[i].first >> v2[i].second;
        if (v2[i].first > v2[i].second) swap(v2[i].first,v2[i].second);
    }
    for (auto x : v1) {
        for (auto y : v2) {
            int a = x.first;
            int b = x.second;
            int c = y.first;
            int d = y.second;
            int z[20] = {0};
            z[a]++;
            z[b]++;
            z[c]++;
            z[d]++;
            int u = 0;
            bool ok = 1;
            for (int i = 1; i <= 9; i++) {
                if (z[i] == 2) {
                    if (u != 0) ok = 0;
                    u = i;
                }
                if (z[i] == 1) continue;
            }
            if (!ok || u == 0) continue;
            uu[u] = 1;
            int c1 = 0;
            for (auto z : v1) {
                if (z != y && c != u && (z.first == c || z.second == c)) c1++;
                if (z != y && d != u && (z.first == d || z.second == d)) c1++;
            }
            int c2 = 0;
            for (auto z : v2) {
                if (z != x && a != u && (z.first == a || z.second == a)) c2++;
                if (z != x && b != u && (z.first == b || z.second == b)) c2++;
            }
            if (c1 || c2) {
                cout << "-1\n";
                return 0;
            }
        }
    }
    int cc = 0;
    int vv;
    for (int i = 1; i <= 9; i++) {
        if (uu[i]) {cc++; vv = i;}
    }
    if (cc == 1) {
        cout << vv << "\n";
    } else {
        cout << "0\n";
    }
}