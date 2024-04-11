#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 220
// 44

using namespace std;

const int MAXN = 22;
const int MAXM = (1 << 23);

int arr[MAXM + 1];

bool ok[2 * MAXM + 1];
bool vis[2 * MAXM + 1];
int ans = 0, n, m;

void dfs(int nod, bool type) {
    if(vis[nod + type * (1 << n)])
        return ;
    vis[nod + type * (1 << n)] = 1;
    if(type == 0) {
        dfs(nod, 1);
    }
    else {
        int mask = 0;
        for(int bit = 0; bit <= n; bit++) {
            if(nod & (1 << bit))
                continue;
            dfs(nod | (1 << bit), 1);
            mask += (1 << bit);
        }
        if(ok[mask])
            dfs(mask, 0);
    }
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, x;
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(i = 1; i <= m; i++) {
        cin >> arr[i];
        ok[arr[i]] = 1;
    }
    for(i = 1; i <= m; i++) {
        if(!vis[arr[i]]) {
            ans++;
            dfs(arr[i], 0);
        }
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}