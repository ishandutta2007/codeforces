#include <bits/stdc++.h>

#define fi first
#define se second
#define DB double
#define U unsigned
#define P std::pair
#define LL long long
#define LD long double
#define pb push_back
#define MP std::make_pair
#define SZ(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 1e6 + 5;
const int MAXM = 29;
int ch[MAXN*(MAXM+1)][2],sz[MAXN*(MAXM+1)],tot = 1;
int n,k,a[MAXN];

inline void insert(int x){
    int v = 1;++sz[v];
    ROF(i,MAXM,0){
        int o = (x>>i)&1;
        if(!ch[v][o]) ch[v][o] = ++tot;
        v = ch[v][o];++sz[v];
    }
}

inline int query(int x){
    int v = 1,res = 0;
    ROF(i,MAXM,0){
        if(!v) break;
        int o = (x>>i)&1;
        if((k>>i)&1){
            v = ch[v][o^1];
        }
        else{
            res += sz[ch[v][o^1]];
            v = ch[v][o];
        }
    }
    res += sz[v];
    return res;
}

int main(){
    scanf("%d%d",&n,&k);
    FOR(i,1,n) scanf("%d",a+i),a[i] ^= a[i-1];
    insert(0);LL ans = 0;
    FOR(i,1,n){
        ans += query(a[i]);
        insert(a[i]);
    }
    printf("%lld\n",ans);
    return 0;
}