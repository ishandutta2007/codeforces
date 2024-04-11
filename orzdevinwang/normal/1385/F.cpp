#include<bits/stdc++.h>
using namespace std;
#define L(i, j, k) for(int i = (j), i##E = (k); i <= i##E; i++) 
#define R(i, j, k) for(int i = (j), i##E = (k); i >= i##E; i--) 
#define ll long long 
#define db double
#define mkp make_pair 
const int N = 2e5 + 7;
int T, n, m, DEG[N], deg[N];
priority_queue< pair<int, int> > q;
unordered_map<int, bool> mpa[N], mpb[N]; // mpa  mpb 
bool g[N];
int f[N];
int main() {
    scanf("%d", &T);
    while(T--) {
        int ans = 0;
        scanf("%d%d", &n, &m);
        L(i, 1, n - 1) {
            int u, v; scanf("%d%d", &u, &v);
            mpa[u][v] = 1, mpa[v][u] = 1;
        }
        L(i, 1, n) if(mpa[i].size() == 1) 
            for(auto x : mpa[i]) deg[x.first]++, mpb[x.first][i] = 1;
        L(i, 1, n) if(deg[i] >= m) q.push(mkp(i, deg[i]));
        while(!q.empty()) {
            pair<int, int> p = q.top();
            int u = p.first;
            q.pop();
            if(g[u]) continue; 
            ++ans;
            deg[u] -= m;
            int cnt = 0;
            for(auto x : mpb[u]) {
                f[++cnt] = x.first;
                if(cnt == m) break;
            }
            L(i, 1, cnt) g[f[i]] = 1, mpa[u].erase(f[i]), mpb[u].erase(f[i]);
            if(mpa[u].size() == 1) {
                for(auto x : mpa[u]) {
                    int v = x.first;
                    deg[v] ++, mpb[v][u] = 1; 
                    if(deg[v] == m) q.push(mkp(v, m));
                }
            }
            if(deg[u] >= m) q.push(mkp(u, deg[u]));
        }
        printf("%d\n", ans);
        L(i, 1, n) mpa[i].clear(), mpb[i].clear(), deg[i] = g[i] = 0;
    }
    return 0;
}