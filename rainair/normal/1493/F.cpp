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

bool flag;int n,m;
//std::mt19937 g(123123);
inline int query(int l1,int r1,int l2,int r2){
    assert(r1 < l2 || r2 < l1);
    assert(r1-l1 == r2-l2);
//    return g()%2;
    if(flag == 0) printf("? %d %d %d %d %d %d\n",r1-l1+1,m,l1,1,l2,1);
    else printf("? %d %d %d %d %d %d\n",n,r1-l1+1,1,l1,1,l2);
    std::fflush(stdout);
    int res;scanf("%d",&res);return res;
}

inline int solve(int n){
    int x = n,t = n;
    int ans = 1;
    FOR(i,2,n){
        if(t%i) continue;
        int e = 1;
        while(!(x%i)){
            auto chk = [&](int d,int n){
                // [1..n]  d 
                assert(n%d == 0);
                auto idl = [&](int x){
                    return (x-1)*d+1;
                };
                auto idr = [&](int x){
                    return idl(x+1)-1;
                };
                if(n/d == 2) return query(idl(1),idr(1),idl(2),idr(2));
                else{
                    int t = (n/d)/2;
                    return query(idl(1),idr(t),idl(t+1),idr(n/d-1))&query(idl(1),idr(t),idl(t+2),idr(n/d));
                }
            };
            if(!chk(x/i,x)) break;
            ++e;x /= i;
        }
        while(!(t%i)) t /= i;
        ans *= e;
    }
    return ans;
}

int main(){
    scanf("%d%d",&n,&m);
    //n = m = 512;
    int ans = solve(n);flag = 1;ans *= solve(m);
    printf("! %d\n",ans);std::fflush(stdout);
    return 0;
}