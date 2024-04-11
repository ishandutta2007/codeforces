#include <bits/stdc++.h>

#define fi first
#define se second
#define db double
#define U unsigned
#define P std::pair<LL,int>
#define LL long long
#define pb push_back
#define MP std::make_pair
#define SZ(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 2e5 + 5;
int n,k,m,s;
int a[MAXN],b[MAXN];
std::vector<P> S1,S2;
int p1 = 0,p2 = 0;

inline bool chk(int lim){
    int mn1 = 1e9,mn2 = 1e9;
    FOR(i,1,lim) mn1 = std::min(mn1,a[i]),mn2 = std::min(mn2,b[i]);
    FOR(i,0,k){
        if(i <= SZ(S1) && k-i <= SZ(S2)){
            LL sm1 = 0,sm2 = 0;
            if(i) sm1 = S1[i-1].fi;
            if(k-i) sm2 = S2[k-i-1].fi;
            if(1ll*sm1*mn1+1ll*sm2*mn2 <= s){
                p1 = i;p2 = k-i;
                return 1;
            }
        }
    }
    return 0;
}

int main(){
    scanf("%d%d%d%d",&n,&m,&k,&s);
    FOR(i,1,n) scanf("%d",a+i);
    FOR(i,1,n) scanf("%d",b+i);
    FOR(i,1,m){
        int t,c;scanf("%d%d",&t,&c);
        if(t == 1) S1.pb(MP(c,i));
        else S2.pb(MP(c,i));
    }
    std::sort(all(S1));std::sort(all(S2));
    FOR(i,1,SZ(S1)-1) S1[i].fi += S1[i-1].fi;
    FOR(i,1,SZ(S2)-1) S2[i].fi += S2[i-1].fi;
    int l = 1,r = n,ans = -1;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(chk(mid)) ans = mid,r = mid-1;
        else l = mid+1;
    }
    printf("%d\n",ans);
    if(ans != -1){
        int mn1 = 1e9,mn2 = 1e9,ps1 = -1,ps2 = -1;
        FOR(i,1,ans){
            if(mn1 > a[i]){
                mn1 = a[i];ps1 = i;
            }
            if(mn2 > b[i]){
                mn2 = b[i];ps2 = i;
            }
        }
        chk(ans);
        FOR(i,1,p1){
            printf("%d %d\n",S1[i-1].se,ps1);
        }
        FOR(i,1,p2){
            printf("%d %d\n",S2[i-1].se,ps2);
        }
    }
    return 0;
}