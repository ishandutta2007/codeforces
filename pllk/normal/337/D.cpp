#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

#define P -999999999

using namespace std;

int n, m, d;
vector<int> p[100000];
int v[100000];
int k[100000][2];
map<int, map<int, int> > x;
int c;

int laske(int s, int y) {
    vector<int> t;
    if (v[s]) t.push_back(0);
    else t.push_back(P);
    for (int i = 0; i < p[s].size(); i++) {
        if (p[s][i] == y) continue;
        int q = laske(p[s][i], s)+1;
        x[s][p[s][i]] = q;
        t.push_back(q);
    }
    sort(t.rbegin(), t.rend());
    if (t.size() == 1) {
        k[s][0] = t[0];
        k[s][1] = t[0];
    } else {
        k[s][0] = t[0];
        k[s][1] = t[1];
    }
    return t[0];
}

void haku(int s, int y, int w) {
    int z = max(w+1, k[s][0]);
    if (z <= d) c++;
    for (int i = 0; i < p[s].size(); i++) {
        if (p[s][i] == y) continue;
        if (x[s][p[s][i]] == k[s][0]) z = max(w+1, k[s][1]);
        else z = max(w+1, k[s][0]);
        haku(p[s][i], s, z);
    }
}

int main() {
    cin >> n >> m >> d;
    for (int i = 0; i < m; i++) {
        int a;
        cin >> a;
        v[a-1] = 1;
    }
    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        p[a-1].push_back(b-1);
        p[b-1].push_back(a-1);
    }
    laske(0, -1);
    haku(0, -1, P);
    cout << c << endl;
}