#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back
#define cmin(a, b) (a = min(a, b))
#define SZ(x) int((x).size())

using namespace std;

const int N = 1e4 + 5;

int n, k, l, a[105], dis[20][N], f[1 << 20];
bool need[N];

int main() {
#ifdef local
    freopen("in", "r", stdin);
#endif
    cin >> n >> k >> l;
    int x;
    while(k--) scanf("%d", &x), need[x] ^= 1, need[x + 1] ^= 1;
    vector<int> pos;
    rep(i, 1, n + 1) if(need[i]) pos.pb(i);
    rep(i, 1, l) scanf("%d", &a[i]);
    mem(dis, 63);
    For(i, 0, SZ(pos)) {
        dis[i][pos[i]] = 0;
        queue<int> q; q.push(pos[i]);
        while(SZ(q)) {
            int u = q.front(); q.pop();
            rep(j, 1, l) for(int k : {-1, 1}) {
                int v = u + a[j] * k;
                if(v > 0 && v <= n + 1 && dis[i][v] == 0x3f3f3f3f)
                    dis[i][v] = dis[i][u] + 1, q.push(v);
            }
        }
    }
    mem(f, 63), f[0] = 0;
    For(S, 0, 1 << SZ(pos)) {
        int i = __builtin_ctz(~S);
        For(j, i + 1, SZ(pos)) if(~S >> j & 1)
            cmin(f[S | 1 << i | 1 << j], f[S] + dis[i][pos[j]]);
    }
    int ans = f[(1 << SZ(pos)) - 1];
    cout << (ans < 0x3f3f3f3f ? ans : -1);
}