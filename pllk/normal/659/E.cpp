#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> v[101010];

int z[101010];
int cn, cm;

void haku(int s) {
    if (z[s]) return;
    z[s] = 1;
    cn++;
    for (int i = 0; i < v[s].size(); i++) {
        haku(v[s][i]);
        cm++;
    }
}

int c;

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        if (z[i]) continue;
        cn = 0;
        cm = 0;
        haku(i);
        cm /= 2;
        if (cn == cm+1) c++;
    }
    cout << c << "\n";
}