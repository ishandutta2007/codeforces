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

const int MAXN = 500+5;
int n,a[MAXN][MAXN],tot;
std::vector<P<int,int> > edge;
int val[MAXN<<2];
bool vis[MAXN<<2];

inline int work(std::vector<int> S){
    if(SZ(S) == 1){
        val[S[0]] = a[S[0]][S[0]];
        return S[0];
    }
    int mx = 0;
    FOR(i,0,SZ(S)-1) FOR(j,0,i-1) mx = std::max(mx,a[S[i]][S[j]]);
    std::vector<int> tmp;
    for(auto x:S) vis[x] = 0;
    FOR(i,0,SZ(S)-1){
        bool flag = 1;
        for(auto x:tmp) flag &= (a[x][S[i]] == mx);
        if(flag) tmp.pb(S[i]),vis[S[i]] = 1;
    }
    int v = ++tot;val[v] = mx;
    for(auto x:tmp){
        std::vector<int> vec;vec.pb(x);
        for(auto y:S) if(!vis[y] && a[x][y] < mx) vec.pb(y);
        int son = work(vec);
        edge.pb(son,v);
    }
    return v;
}

int main(){
    scanf("%d",&n);tot = n;
    FOR(i,1,n) FOR(j,1,n) scanf("%d",&a[i][j]);
    std::vector<int> S;
    FOR(i,1,n) S.pb(i);
    int rt = work(S);
    printf("%d\n",tot);
    FOR(i,1,tot) printf("%d%c",val[i]," \n"[i==tot]);
    printf("%d\n",rt);
    for(auto x:edge) printf("%d %d\n",x.fi,x.se);
    return 0;
}