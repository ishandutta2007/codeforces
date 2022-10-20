#include <bits/stdc++.h>
#define Task "B"
#define fi freopen(Task".inp", "r", stdin)
#define fo freopen(Task".out", "w", stdout)

using namespace std;

const int N = 200100;

int n;
int pre[1000100], next[1000010], used[1000010], res[N];

int main() {
    ios_base::sync_with_stdio(0);
    //fi, fo;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int u, v;
        cin >> u >> v;
        next[u] = v;
        pre[v] = u;
    }
    int vt = next[0], cnt = 2;
    while(vt) {
        used[vt] = 1;
        res[cnt] = vt;
        vt = next[vt];
        cnt += 2;
    }
    for(int i = 1; i <= 1000001; i++)
        if(!used[i] && pre[i]) {
            vt = i;
            break;
        }
    while(1) {
        int y = pre[vt];
        if(!y) break;
        vt = pre[vt];
    }
    cnt = 1;
    while(vt) {
        res[cnt] = vt;
        cnt += 2;
        vt = next[vt];
    }
    for(int i = 1; i <= n; i++) cout << res[i] << " ";

    return 0;
}