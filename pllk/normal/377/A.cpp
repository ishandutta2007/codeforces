#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, k;
string d[555];

struct ruutu {
    int y, x, matka;
};

queue<struct ruutu> jono;
vector<pair<int, int> > v;

void jonoon(int y, int x, int matka) {
    if (y < 0 || y >= n) return;
    if (x < 0 || x >= m) return;
    if (d[y][x] == '#') return;
    if (d[y][x] == 'Y') return;
    d[y][x] = 'Y';
    struct ruutu uusi = {y, x, matka};
    jono.push(uusi);
    v.push_back(make_pair(y, x));
}

void haku(int y, int x) {
    jonoon(y, x, 0);
    while (!jono.empty()) {
        struct ruutu nyky = jono.front();
        jono.pop();
        jonoon(nyky.y-1, nyky.x, nyky.matka+1);
        jonoon(nyky.y+1, nyky.x, nyky.matka+1);
        jonoon(nyky.y, nyky.x-1, nyky.matka+1);
        jonoon(nyky.y, nyky.x+1, nyky.matka+1);
    }
}

int main() {
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) cin >> d[i];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (d[i][j] == '.') {
                haku(i, j);
                goto ohi;
            }
        }
    }
    ohi:
    if (k == 0) goto lol;
    for (int i = v.size()-1; i >= 0; i--) {
        d[v[i].first][v[i].second] = 'X';
        k--;
        if (k == 0) break;
    }
    lol:
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (d[i][j] == '#') cout << "#";
            else if (d[i][j] == 'X') cout << "X";
            else cout << ".";
        }
        cout << endl;
    }
}