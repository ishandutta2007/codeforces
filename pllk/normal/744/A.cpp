#include <iostream>
#include <vector>

using namespace std;

int n, m, k;
int c[1111];
vector<int> v[1111];

int z[1111];
int un, um;
int r;
int h;
int tn, tm;

void haku(int s) {
    if (z[s]) return;
    z[s] = 1;
    un++;
    um += v[s].size();
    for (int i = 0; i < v[s].size(); i++) haku(v[s][i]);
}

int main() {
    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++) cin >> c[i];
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int pn = 0;
    for (int i = 1; i <= k; i++) {
        un = um = 0;
        haku(c[i]);
        pn = max(pn,un);
        um /= 2;
        r += un*(un-1)/2-um;
        tn += un;
        tm += um;
    }
    int zn = n-tn;
    int zm = m-tm;
    r += zn*(zn-1)/2-zm;
    for (int i = 1; i <= n; i++) {
        if (z[i]) continue;
        r += pn;
    }
    cout << r << "\n";
}