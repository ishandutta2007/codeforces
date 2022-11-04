#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MAXN = (int) 3e5;

vector <int> g[MAXN + 1];
int weight[MAXN + 1];
bool ok[MAXN + 1];

int x, y;

void dfs(int nod) {
    weight[nod] = 1;
    for(auto it : g[nod]) {
        if(weight[it] == 0) {
            dfs(it);
            weight[nod] += weight[it];
            ok[nod] |= ok[it];
        }
    }
    ok[nod] |= (nod == y);
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int n, i, a, b;
    ios::sync_with_stdio(false);
    cin >> n >> x >> y;
    for(i = 1; i < n; i++) {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(x);
    ll ans = 1LL * n * (n - 1);
    int cnt = 0;
    for(auto it : g[x]) {
        if(ok[it] == 0) {
            cnt += weight[it];
        }
    }
    //printf("%d " ,cnt);
    cout << ans - 1LL * (cnt + 1) * weight[y];
    //cin.close();
    //cout.close();
    return 0;
}