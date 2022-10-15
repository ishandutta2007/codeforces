#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long int

using namespace std;

int g[1000][1000];
bool b[1000][1000];

vector<pair<int, int> > v;
vector<pair<int, int> > u;

int n, t;

int kk;

void muuta(int x, int y, int m) {
    kk++;
    g[x][y] += m;
    if (!b[x][y] && g[x][y] >= 4) {
        v.push_back(make_pair(x, y));
        b[x][y] = true;
    }
}

int main() {
    cin >> n >> t;
    g[500][500] = n;
    if (n >= 4) {
        b[500][500] = true;
        v.push_back(make_pair(500, 500));
    }
    while (true) {
        bool c = false;
        for (int i = 0; i < v.size(); i++) {
            int k = g[v[i].first][v[i].second]/4;
            if (k == 0) continue;
            c = true;
            muuta(v[i].first, v[i].second, -4*k);
            muuta(v[i].first-1, v[i].second, k);
            muuta(v[i].first+1, v[i].second, k);
            muuta(v[i].first, v[i].second-1, k);
            muuta(v[i].first, v[i].second+1, k);
        }
        if (!c) break;
    }
    for (int i = 0; i < t; i++) {
        ll x, y;
        cin >> x >> y;
        if (x>100 || y>100 || x<-100 || y<-100) cout << 0 << endl;
        else cout << g[500+x][500+y] << endl;
    }
}