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
int n,q;
int a[MAXN];
int bel[MAXN],to[MAXN],tag[MAXN],B,c[MAXN];// O(len)

inline void rebuild(int x){
    if(c[x] > B) return;
    int l = (x-1)*B+1,r = std::min(n,x*B);
    FOR(i,l,r) a[i] = std::max(1,a[i]-tag[x]);
    tag[x] = 0;
    FOR(i,l,r){
        if(a[i] < l) to[i] = i;
        else to[i] = to[a[i]];
    }
}

inline int fa(int x){
    return std::max(1,a[x]-tag[bel[x]]);
}

int main(){
    scanf("%d%d",&n,&q);B = std::sqrt(1.0*n);
    a[1] = 1;FOR(i,2,n) scanf("%d",a+i);
    FOR(i,1,n) bel[i] = (i-1)/B+1;
    FOR(i,1,bel[n]) rebuild(i);
    while(q--){
        int o;scanf("%d",&o);
        if(o == 1){
            int l,r,x;scanf("%d%d%d",&l,&r,&x);
            if(bel[l] == bel[r]){
                FOR(i,l,r) a[i] = std::max(1,a[i]-x);
                rebuild(bel[l]);
            }
            else{
                FOR(i,l,bel[l]*B) a[i] = std::max(1,a[i]-x);
                rebuild(bel[l]);
                FOR(i,bel[l]+1,bel[r]-1){
                    tag[i] += x;
                    if(c[i] <= B) rebuild(i),++c[i];
                }
                FOR(i,(bel[r]-1)*B+1,r) a[i] = std::max(1,a[i]-x);
                rebuild(bel[r]);
            }
        }
        else{
            int u,v;scanf("%d%d",&u,&v);
            while(u != v){
                if(u > v) std::swap(u,v);
                if(bel[u] != bel[v]){
                    v = fa(to[v]);
                    continue;
                }
                if(to[u] == to[v]){
                    while(u != v){
                        if(u > v) std::swap(u,v);
                        v = fa(v);
                    }
                    break;
                }
                u = fa(to[u]);v = fa(to[v]);
            }
            printf("%d\n",u);
        }
    }
    return 0;
}