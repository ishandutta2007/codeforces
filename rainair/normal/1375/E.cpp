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

const int MAXN = 1000+5;
int p[MAXN],q[MAXN],n,a[MAXN];

int main(){
    scanf("%d",&n);
    std::vector<P<int,int> > S;
    FOR(i,1,n) scanf("%d",a+i),S.pb(a[i],i);
    std::sort(all(S));
    FOR(i,1,n) q[i] = S[i-1].se,p[q[i]] = i;
    std::vector<P<int,int> > res;
    auto swap = [&](int x,int y){
        std::swap(q[p[x]],q[p[y]]);
        std::swap(p[x],p[y]);
        if(a[x] < a[y]) std::swap(x,y);
        res.pb(x,y);
    };
    ROF(i,n,1){
        int t = p[i];
        FOR(j,t+1,i){
            swap(i,q[j]);
        }
    }
    printf("%d\n",SZ(res));
    for(auto x:res) printf("%d %d\n",x.fi,x.se);
    return 0;
}