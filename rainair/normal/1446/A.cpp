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

const int MAXN = 2e5 + 5;
int n;LL W;
LL a[MAXN];

inline void Solve(){
    scanf("%d%lld",&n,&W);
    FOR(i,1,n) scanf("%lld",a+i);
    LL l = (W+1)/2,r = W;
    FOR(i,1,n){
        if(l <= a[i] && a[i] <= r){
            printf("1\n%d\n",i);
            return;
        }
    }
    std::vector<int> S;
    LL sm = 0;
    FOR(i,1,n){
        if(a[i] > r) continue;
        if(sm+a[i] <= r){
            sm += a[i];
            S.pb(i);
        }
    }
    if(sm < l){
        puts("-1");
    }
    else{
        printf("%d\n",(int)S.size());
        for(auto x:S) printf("%d ",x);puts("");
    }
}

int main(){
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}