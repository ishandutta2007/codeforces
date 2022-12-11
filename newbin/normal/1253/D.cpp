#include<bits/stdc++.h>
#define ll long long
#define lowbit(x) ((x)&(-(x)))
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
using namespace std;
const int maxn = 2e5 + 50;
int fa[maxn], mx[maxn];
int fnd(int x){
    if(x == fa[x]) return x; return fa[x] = fnd(fa[x]);
}
bool link(int u, int v){
    u = fnd(u), v = fnd(v);
    if(u == v) return 0;
    if(u > v) swap(u, v);
    mx[u] = max(mx[u], mx[v]);
    fa[v] = u;
    return 1;
}
int main()
{
    int n, m;
    cin>>n>>m;
    for(int i = 0; i <= n; ++i) fa[i] = i, mx[i] = i;
    while(m--){
        int u, v; scanf("%d%d", &u, &v);
        link(u, v);
    }
    int ans = 0;
    int rt = 0;
    for(int i = 1; i <= n; ++i){
        if(i > mx[rt]){
            rt = i; continue;
        }
        if(link(rt, i)) ans++;
    }cout<<ans<<endl;
}