#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)

using namespace std;

const int N = 100010;

int a, b, n;
pair <int, int> p[N];
int par[N], can[2][N];

int Getpar(int u) {
    return (par[u] == u)? u : (par[u] = Getpar(par[u]));
}

void Join(int x, int y) {
    x = Getpar(x);
    y = Getpar(y);
    par[x] = y;
    can[0][y] &= can[0][x];
    can[1][y] &= can[1][x];
}

int main(){
    ios_base::sync_with_stdio(0);
    //fi, fo;
    cin >> n >> a >> b;
    for(int i = 1; i <= n; i++) {
        par[i] = i;
        can[1][i] = can[0][i] = 1;
        cin >> p[i].first;
        p[i].second = i;
    }
    sort(p + 1, p + n + 1);
    p[0] = make_pair(-1000000001, 0);
    p[n + 1] = make_pair(1000000001, 0);
    for(int i = 1; i <= n; i++) {
        int vt;
        vt = lower_bound(p, p + 2 + n, make_pair(a - p[i].first, -1)) - p;
        if(p[vt].first == a - p[i].first)
            Join(p[i].second, p[vt].second);
        else can[0][Getpar(p[i].second)] = 0;
        vt = lower_bound(p, p + n + 2, make_pair(b - p[i].first, -1)) - p;
        if(p[vt].first == b - p[i].first)
            Join(p[i].second, p[vt].second);
        else can[1][Getpar(p[i].second)] = 0;
    }
    for(int i = 1; i <= n; i++)
    if(par[i] == i && !can[0][i] && !can[1][i]) {
        cout << "NO";
        return 0;
    }
    cout << "YES\n";
    for(int i = 1; i <= n; i++) cout << can[1][Getpar(i)] << " " ;
    return 0;
}