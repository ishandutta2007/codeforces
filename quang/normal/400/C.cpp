#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)
#define MAX
#define N

using namespace std;

int n ,m, x, y, z, p;

void Quay(int &u, int &v, int &nn, int &mm) {
    int uu = u;
    u = v;
    v = nn - uu + 1;
    swap(nn, mm);
}

void Dao(int &u, int &v, int &nn, int &mm) {
    v = mm - v + 1;
}

void Xuli(int u, int v) {
    int nn = n, mm = m;

    for(int i = 1; i <= x; i++) Quay(u, v, nn, mm);
    if(y) Dao(u, v, nn, mm);
    if(z != 0)
        for(int i = 1; i <= 4 - z; i++) Quay(u, v, nn, mm);
    cout << u << " " << v << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
   // fi, fo;
    cin >> n >> m >> x >> y >> z >> p;
    x %= 4, y %= 2, z %= 4;
    while(p--) {
        int u, v;
        cin >> u >> v;
        Xuli(u, v);
    }
    return 0;
}