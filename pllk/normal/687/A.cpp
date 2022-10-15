#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

int n, m;
vector<int> v[101010];
int c[101010];
vector<int> r[5];

void haku(int s, int x) {
    if (c[s] == x) return;
    if (c[s] == 3-x) {
        cout << "-1\n";
        exit(0);
    }
    r[x].push_back(s);
    c[s] = x;
    for (int i = 0; i < v[s].size(); i++) {
        haku(v[s][i], 3-x);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        if (c[i] != 0) continue;
        haku(i,1);
    }
    cout << r[1].size() << "\n";
    for (int i = 0; i < r[1].size(); i++) cout << r[1][i] << " ";
    cout << "\n";
    cout << r[2].size() << "\n";
    for (int i = 0; i < r[2].size(); i++) cout << r[2][i] << " ";
    cout << "\n";
}