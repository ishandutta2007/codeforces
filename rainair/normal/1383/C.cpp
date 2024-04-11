#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdlib>
#include <cstdio>
#include <bitset>
#include <vector>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <map>
#include <set>

#define fi first
#define se second
#define db double
#define U unsigned
#define P std::pair<int,int>
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 1e5 + 5;

char A[MAXN],B[MAXN];
int n;
int G[21];
int fa[21];

inline int find(int x){
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

inline void merge(int x,int y){
    x = find(x);y = find(y);
    if(x == y) return;
    fa[x] = y;
}

bool ps[21];
bool g[(1<<20)+3];

inline void Solve(){
    scanf("%d",&n);scanf("%s",A+1);scanf("%s",B+1);
    FOR(i,1,20) fa[i] = i;
    CLR(G,0);CLR(ps,0);
    FOR(i,1,n) G[A[i]-'a'] |= 1<<(B[i]-'a'),merge(A[i]-'a'+1,B[i]-'a'+1);
    FOR(i,1,20) ps[find(i)] = 1;
    int ans = 2*20;FOR(i,1,20) ans -= ps[i];
    int mx = 0;CLR(g,0);
    g[0] = 1;
    FOR(S,0,(1<<20)-1){
        if(!g[S]) continue;
        mx = std::max(mx,__builtin_popcount(S));
        FOR(i,0,19){
            if((S>>i)&1) continue;
            if(G[i]&S) continue;
            g[S|(1<<i)] = 1;
        }
    }
    ans -= mx;
    printf("%d\n",ans);
}

int main(){
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}