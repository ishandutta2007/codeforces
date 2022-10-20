#include <bits/stdc++.h>
#define Task "E"
#define fi freopen(Task".inp", "r", stdin)
#define fo freopen(Task".out", "w", stdout)

using namespace std;

int n, m, dx, dy;
int sl[1000010], coo[1000010];

int main() {
    ios_base::sync_with_stdio(0);
    //fi, fo;
    cin >> n >> m >> dx >> dy;
    coo[0] = 0;
    int cur = dx, cur2 = dy;
    while(cur) {
        coo[cur] = cur2;
        cur =(cur + dx) % n;
        cur2 = (cur2 + dy) % n;
    }
    int gtmax = 0;
    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        int kc;
        if(v < coo[u]) kc = n - (coo[u] - v);
        else kc = v - coo[u];
        sl[kc]++;
        if(sl[gtmax] < sl[kc]) gtmax = kc;
    }
    cout << 0 << " " << gtmax;
    return 0;
}