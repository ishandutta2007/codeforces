#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 220
// 44

using namespace std;

const int MAXN = (int) 1e6 + 5;

int coord[MAXN + 1];
int a[MAXN + 1];

bool vis[MAXN + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int n, m, k, i, x;
    ios::sync_with_stdio(false);
    //cin >> n >> m >> k;
    scanf("%d%d%d" ,&n,&m,&k);
    for(i = 1; i <= m; i++) {
        //cin >> x;
        scanf("%d" ,&x);
        vis[x] = 1;
    }
    for(i = 1; i <= k; i++) {
        //cin >> a[i];
        scanf("%d" ,&a[i]);
    }
    for(i = 1; i < n; i++) {
        if(vis[i] == 0) {
            coord[i] = i;
        }
        else {
            coord[i] = coord[i - 1];
        }
    }
    if(vis[0]) {
        cout << -1;
        return 0;
    }
    ll ans = 1e18;
    for(i = 1; i <= k; i++) {
        int pos = 0;
        int cnt = 1;
        x = 0;
        while(x + i < n) {
            cnt++;
            if(coord[x] + i < n && x == coord[x + i]) {
                break;
            }
            x = coord[x + i];
        }
        if(x + i >= n) {
            ans = min(ans, 1LL * a[i] * cnt);
        }
    }
    if(ans == 1e18) {
        ans = -1;
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}