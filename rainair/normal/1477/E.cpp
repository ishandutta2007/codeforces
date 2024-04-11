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

const int MAXN = 1e6 + 5;
int n,m,q,a[MAXN],b[MAXN];

struct BIT{
    #define lowbit(x) ((x)&((-(x))))
    LL tree[MAXN];

    inline void add(int pos,int x){
        for(;pos;pos-=lowbit(pos)) tree[pos] += x;
    }

    inline LL query(int pos){
        LL res = 0;pos = std::max(pos,1);
        for(;pos<MAXN;pos+=lowbit(pos)) res += tree[pos];
        return res;
    }
}sa,ca,sb,cb;

std::multiset<int> A,B;

int main(){
    scanf("%d%d%d",&n,&m,&q);
    FOR(i,1,n) scanf("%d",a+i),++a[i],A.insert(a[i]),sa.add(a[i],a[i]),ca.add(a[i],1);
    FOR(i,1,m) scanf("%d",b+i),++b[i],B.insert(b[i]),sb.add(b[i],b[i]),cb.add(b[i],1);
    while(q--){
        int opt,p,x;scanf("%d",&opt);
        if(opt == 1){
            scanf("%d%d",&p,&x);++x;
            A.erase(A.find(a[p]));
            sa.add(a[p],-a[p]);
            ca.add(a[p],-1);
            a[p] = x;
            ca.add(a[p],1);
            sa.add(a[p],a[p]);
            A.insert(a[p]);
        }
        else if(opt == 2){
            scanf("%d%d",&p,&x);++x;
            B.erase(B.find(b[p]));
            sb.add(b[p],-b[p]);
            cb.add(b[p],-1);
            b[p] = x;
            cb.add(b[p],1);
            sb.add(b[p],b[p]);
            B.insert(b[p]);
        }
        else{
            int k;scanf("%d",&k);
            int mn = std::min(*A.begin(),*B.begin());
            auto calc = [&](int t,int o){// 0:A 1:B
/*                LL ans = 0;
                FOR(i,1,m) ans -= std::max(0,b[i]+k-t);
                FOR(i,1,n) ans += std::max(a[i]+k-t,a[i]-mn);
                */
                LL ans = sa.query(1)+1ll*n*std::max(k-t,-mn);
                ans -= sb.query(t-k)-cb.query(t-k)*(t-k);
                if(o == 0) ans -= std::max(k,t-mn);// A 
                else ans += k;
                if(o == 0) ans += k;
                else ans -= k;
                return ans;
            };
            auto query = [&](int t,int o) -> LL{// select A
                auto p = (o?B:A).lower_bound(t);
                LL ans = -1e18;
                if(p != (o?B:A).end()) ans = std::max(ans,calc(*p,o));
                if(p != (o?B:A).begin()){
                    --p;
                    ans = std::max(ans,calc(*p,o));
                    ++p;
                }
                if(p == (o?B:A).end()) return ans;
                ++p;
                if(p != (o?B:A).end()){
                    ans = std::max(ans,calc(*p,o));
                }
                return ans;
            };
            
/*            LL ans = -1e18;
            FOR(i,1,n) ans = std::max(ans,calc(a[i],0));
            FOR(i,1,m) ans = std::max(ans,calc(b[i],1));*/
            
            int mx = std::max(*A.rbegin(),*B.rbegin());
            LL ans = std::max({query(mn,0),query(mn,1),query(*B.rbegin()+k,0),query(*B.rbegin()+k,1)});
            
//            ans = std::max(ans,calc(*A.begin(),0));
//            ans = std::max(ans,calc(*A.rbegin(),0));
//            ans = std::max(ans,query(k+mn,1));
//            ans = std::max(ans,calc(*B.rbegin(),1));
//            ans = std::max(ans,calc(*B.begin(),1));
            printf("%lld\n",ans);
        }
    }
    return 0;
}