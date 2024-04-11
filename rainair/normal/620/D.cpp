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

const int MAXN = 2000+5;
LL mn = 1e18;int ans[3][2],k=-1;
int n,m;LL a[MAXN],b[MAXN];

inline LL mabs(LL x){
    return x < 0 ? -x : x;
}

int main(){
    scanf("%d",&n);LL s1=0,s2=0;
    FOR(i,1,n) scanf("%lld",a+i),s1 += a[i];
    scanf("%d",&m);
    FOR(i,1,m) scanf("%lld",b+i),s2 += b[i];
    // k = 0
    mn = mabs(s1-s2);k = 0;
    // k=1
    FOR(i,1,n){
        FOR(j,1,m){
            if(mn > mabs(s1-s2-2*a[i]+2*b[j])){
                mn = mabs(s1-s2-2*a[i]+2*b[j]);
                k = 1;
                ans[1][0] = i;
                ans[1][1] = j;
            }
        }
    }
    // k = 2
    std::vector<LL> S1,S2;
    LL t1 = -1,t2 = -1;
    FOR(i,1,n) FOR(j,i+1,n) S1.pb(2ll*(a[i]+a[j]));
    FOR(i,1,m) FOR(j,i+1,m) S2.pb(2ll*(b[i]+b[j]));
    std::sort(all(S1));std::sort(all(S2));
    for(auto x:S1){
        LL now = s1-s2-x;
        auto p = std::upper_bound(all(S2),-now);
        if(p != S2.end()){
            if(mn > mabs(now+*p)){
                mn = mabs(now+*p);
                t1 = x;t2 = *p;
                k = 2;
            }
        }
        if(p != S2.begin()){
            --p;
            if(mn > mabs(now+*p)){
                mn = mabs(now+*p);
                t1 = x;t2 = *p;
                k = 2;
            }
        }
    }
    if(k == 2){
        FOR(i,1,n) FOR(j,i+1,n) if(2ll*(a[i]+a[j]) == t1){
            ans[1][0] = i;ans[2][0] = j;break;
        }
        FOR(i,1,m) FOR(j,i+1,m) if(2ll*(b[i]+b[j]) == t2){
            ans[1][1] = i;ans[2][1] = j;break;
        }
    }
    printf("%lld\n%d\n",mn,k);
    FOR(i,1,k){
        printf("%d %d\n",ans[i][0],ans[i][1]);
    }
    auto chk = [&](){
        FOR(i,1,k) std::swap(a[ans[i][0]],b[ans[i][1]]);
        LL sm0 = 0,sm1 = 0;
        FOR(i,1,n) sm0 += a[i];
        FOR(i,1,m) sm1 += b[i];
        assert(mabs(sm0-sm1)==mn);
    };
    chk();
    return 0;
}