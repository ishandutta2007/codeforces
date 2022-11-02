#include <bits/stdc++.h>

#define fi first
#define se second
#define DB double
#define U unsigned
#define P std::pair
#define LL long long
#define LD long double
#define pb emplace_back
#define MP std::make_pair
#define SZ(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 1e5 + 5;
const int ha = 1e9 + 7;

inline int qpow(int a,int n=ha-2){
	int res = 1;
	while(n){
		if(n & 1) res = 1ll*res*a%ha;
		a = 1ll*a*a%ha;
		n >>= 1;
	}
	return res;
}

struct DS{
    int f[MAXN],n;

    inline void init(int sz){
        n = sz;FOR(i,0,n) f[i] = i;
    }

    inline int find(int x){
        return x == f[x] ? x : f[x] = find(f[x]);
    }

    inline void merge(int x,int y){
        x = find(x);y = find(y);
        if(x == y) return;
        f[x] = y;
    }

    inline int size(){
        int sz = 0;
        FOR(i,0,n) if(find(i) == i) sz++;
        return sz;
    }
}f1,f2;
std::vector<P<int,int> > e1,e2;

int n,k;
std::vector<int> G1[MAXN],G2[MAXN];

inline int ctoi(char c){
    if(c == 'o') return 1;
    return 0;
}

int col[MAXN];bool vis[MAXN];

inline void dfs1(int v,int fa=0){
    vis[v] = 1;
    for(auto x:G1[v]){
        if(x == fa) continue;
        if(!vis[x]) col[x] = col[v]^1,dfs1(x,v);
        else if(col[x]==col[v]){puts("0");exit(0);}
    }
}

inline void dfs2(int v,int fa=0){
    vis[v] = 1;
    for(auto x:G2[v]){
        if(x == fa) continue;
        if(!vis[x]) col[x] = col[v]^1,dfs2(x,v);
        else if(col[x]==col[v]){puts("0");exit(0);}
    }
}

int main(){
    scanf("%d%d",&n,&k);
    if(n == 1) return puts(k?"1":"2"),0;
    f1.init((n+1)/2);f2.init(n/2);
    FOR(i,1,k){
        int x,y;char str[5];scanf("%d%d%s",&x,&y,str);
        int c = ctoi(str[0]);
        int l = std::abs(x-y)+1,r = l+2*(std::min({x,y,n-x+1,n-y+1})-1);
        if(l&1){
            l = (l+1)>>1;r = (r+1)>>1;
            if(c){// s[l-1] != s[r]
                e1.pb(l-1,r);
            }
            else{// s[l-1] == s[r]
                f1.merge(l-1,r);
            }
        }
        else{
            l >>= 1;r >>= 1;
            if(c){
                e2.pb(l-1,r);
            }
            else{
                f2.merge(l-1,r);
            }
        }
    }
    for(auto x:e1){
        int u = f1.find(x.fi),v = f1.find(x.se);
        if(u == v) return puts("0"),0;
        G1[u].pb(v);G1[v].pb(u);
    }
    for(auto x:e2){
        int u = f2.find(x.fi),v = f2.find(x.se);
        if(u == v) return puts("0"),0;
        G2[u].pb(v);G2[v].pb(u);
    }
    int t = 0;
    FOR(i,0,n) if(i == f1.find(i) && !vis[i]) dfs1(i),++t;
    CLR(vis,0);CLR(col,0);
    FOR(i,0,n) if(i == f2.find(i) && !vis[i]) dfs2(i),++t;
    printf("%d\n",qpow(2,t-2));
    return 0;
}