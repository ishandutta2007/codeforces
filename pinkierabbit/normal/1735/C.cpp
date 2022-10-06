#include <bits/stdc++.h>

#define rep(i,l,r) for (int i = l; i <= r; i++)
#define per(i,r,l) for (int i = r; i >= l; i--)
#define fi first
#define se second
#define prt std::cout
#define gin std::cin
#define edl std::endl

namespace wxy{

const int N = 1e5 + 50;

char str[N];

int ans[N],nxt[26],pre[26];

int fa[26],sz[26];

int get(int x) {
    return fa[x] == x ? x : fa[x] = get(fa[x]);
}

void merge(int x,int y) {
    x = get(x); y = get(y);
    if (x == y) return ;
    fa[x] = y; sz[y] += sz[x]; 
}

inline void solve(){
    int n; scanf("%d",&n); scanf("%s",str+1); rep(i,0,25) nxt[i] = pre[i] = -1,fa[i] = i,sz[i] = 1;
    rep(i,1,n) {
        rep(j,0,25) {
            if (j == (str[i] - 'a') || (nxt[j] != -1 && nxt[j] != (str[i] - 'a'))) continue;
            if (nxt[j] == (str[i] - 'a')) {
                ans[i] = j; break;
            }
            if (pre[str[i] - 'a'] != -1 && pre[str[i] - 'a'] != j) continue;
            if (sz[get(j)] != 26 && get(str[i] - 'a') == get(j)) continue;
            ans[i] = j; nxt[j] = (str[i] - 'a'); pre[str[i] - 'a'] = j; merge(j,nxt[j]);
            break;
        }
    }
    rep(i,1,n) prt << (char)('a'+ans[i]);
    puts("");
}

inline void main(){
    #ifndef ONLINE_JUDGE
        freopen("in.in","r",stdin);
        freopen("out.out","w",stdout);
    #endif
    int t; scanf("%d",&t); while (t --) solve();
}

}signed main(){wxy::main(); return 0;}