#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

#ifndef local
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#endif

using namespace std;

const int N = 1e3 + 8;

int d[N], fa[N];
bool vis[N];

int find(int x) {
    return fa[x] ? fa[x] = find(fa[x]) : x;
}
void solve() {
    int n;
    cin >> n;
    rep(i, 1, n) cin >> d[i], fa[i] = vis[i] = 0;
    while(1) {
        int mx = 0, u = 0;
        rep(i, 1, n) if(!vis[i] && d[i] > mx) mx = d[i], u = i;
        if(!u) {
            cout << "! ";
            rep(j, 1, n) cout << find(j) << ' ';
            cout << endl;
            break;
        }
        vis[u] = 1;
        int v;
        rep(i, 1, d[u]) {
            cout << "? " << u << endl;
            cin >> v;
            if(vis[v]) { fa[u] = find(v); break; }
            else fa[v] = u, vis[v] = 1;
        }
    }
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T;
    for(cin >> T; T--; solve());
}