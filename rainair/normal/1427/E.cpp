#include <bits/stdc++.h>

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

struct Node{
    int o;LL x,y;
    inline Node(int o=0,LL x=0,LL y=0) : o(o),x(x),y(y) {}
};

std::vector<Node> ans;

inline void work(LL x){
    if(x == 1) return;
    if((x>>1)&1){
        ans.pb(Node(1,x,x));LL y = x<<1;
        ans.pb(Node(2,x,y));LL z = x^y;
        work(z);
        return;
    }
    int lb=1e9,ub=0;
    ROF(i,60,0) if((x>>i)&1) lb = std::min(lb,i),ub = std::max(ub,i);
    LL y = x;
    FOR(i,1,ub-lb) ans.pb(Node(1,y,y)),y <<= 1;
    ans.pb(Node(2,y,x));LL z = y^x;
    ans.pb(Node(1,y,x));LL a = x+y;
    ans.pb(Node(2,a,z));LL b = a^z;
    if(!((x>>1)&1)){
        FOR(i,ub+1,60){
            if((z>>i)&1) ans.pb(Node(2,z,b)),z ^= b;
            ans.pb(Node(1,b,b));b <<= 1;
        }
        work(z);
    }
}

int main(){
    LL x;scanf("%lld",&x);
    work(x);
    printf("%d\n",(int)ans.size());
    for(auto x:ans){
        if(x.o == 1) printf("%lld + %lld\n",x.x,x.y);
        else printf("%lld ^ %lld\n",x.x,x.y);
    }
    return 0;
}