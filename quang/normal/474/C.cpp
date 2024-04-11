#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)

using namespace std;

const int MAX = 12345678;

int n, res;
int x[4], y[4], a[4], b[4];
int x2[4], y2[4];

bool Square() {
    vector <long long> dis;
    for(int i = 0; i < 4; i++)
        for(int j = i + 1; j < 4; j++)
            dis.push_back((1ll * x2[i] - x2[j]) * (1ll * x2[i] - x2[j]) + (1ll * y2[i] - y2[j]) * (1ll * y2[i] - y2[j]));
    sort(dis.begin(), dis.end());
    if(dis[0] == 0) return 0;
    for(int i = 1; i <= 3; i++)
        if(dis[i] != dis[0]) return 0;
    for(int i = 4; i <= 5; i++)
        if(dis[i] != dis[0] * 2) return 0;
    return 1;
}

void Xoay(int u, int sl) {
    int xx = x[u] - a[u], yy = y[u] - b[u];
    if(sl == 0) {
        x2[u] = x[u];
        y2[u] = y[u];
    }
    if(sl == 1) {
        x2[u] = a[u] - yy;
        y2[u] = b[u] + xx;
    }
    if(sl == 2) {
        x2[u] = a[u] - xx;
        y2[u] = b[u] - yy;
    }
    if(sl == 3) {
        x2[u] = a[u] + yy;
        y2[u] = b[u] - xx;
    }
}

void Go(int u, int sl) {
    if(u >= 4) {
        if(Square())
            res = min(res, sl);
        return;
    }
    for(int i = 0; i < 4; i++) {
        Xoay(u, i);
        Go(u + 1, sl + i);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
   // fi, fo;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < 4; j++) cin >> x[j] >> y[j] >> a[j] >> b[j];
        res = MAX;
        Go(0, 0);
        if(res == MAX) cout << -1;
        else cout << res;
        cout << endl;
    }
    return 0;
}