#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int INF = 1e9;
const int MAXN = (int) 2e5;

int to[MAXN + 1], c[MAXN + 1];
int vis[MAXN + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 1; i <= n; i++) {
        cin >> c[i];
    }
    for(i = 1; i <= n; i++) {
        cin >> to[i];
    }
    ll ans = 0;
    int now = 0;
    for(i = 1; i <= n; i++) {
        if(vis[i] == 0) {
            now++;
            int nod = i;
            while(vis[nod] == 0) {
                vis[nod] = now;
                nod = to[nod];
            }
            if(vis[nod] == now) {
                int aux = nod;
                int cur = INF;
                do {
                    cur = min(cur, c[nod]);
                    nod = to[nod];
                }while(aux != nod);
                ans += cur;
            }
        }
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}