#include<bits/stdc++.h>

#define fi first
#define se second
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

int n,k;
char str[233];

inline int query(std::vector<int> x,std::vector<int> y){//a[x]-a[y]
    printf("? %d %d\n",(int)x.size(),(int)y.size());
    for(auto t:x) printf("%d ",t);puts("");
    for(auto t:y) printf("%d ",t);puts("");
    std::fflush(stdout);
    scanf("%s",str);
    if(str[0] == 'F') return 1;
    if(str[0] == 'S') return -1;
    if(str[0] == 'W') exit(-1);
    return 0;
}

std::vector<int> id;
std::mt19937 g(23332333);

inline void Solve(){
    scanf("%d%d",&n,&k);id.clear();
    FOR(i,2,n) id.pb(i);std::shuffle(all(id),g);
    FOR(i,0,std::min(29,(int)id.size()-1)){
        if(query({1},{id[i]}) < 0){
            puts("! 1");std::fflush(stdout);
            return;
        }
    }
    int ps = 2;
    while(ps <= n){
        std::vector<int> t1,t2;
        FOR(i,1,ps/2) t1.pb(i);FOR(i,ps/2+1,ps) t2.pb(i);
        if(query(t1,t2) != 0){
            break;
        }
        ps <<= 1;
    }
    int l = ps/2+1,r = std::min(ps,n),ans = ps/2;
    while(l <= r){// [l,mid]
        int mid = (l + r) >> 1;
        std::vector<int> v1,v2;
        FOR(i,l,mid) v1.pb(i-l+1),v2.pb(i);
        if(query(v1,v2) == 0) ans = mid,l = mid+1;
        else r = mid-1;
    }
    printf("! %d\n",ans+1);
    std::fflush(stdout);
}

int main(){
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}