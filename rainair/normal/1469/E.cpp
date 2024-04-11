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

char str[MAXN];
int a[MAXN],ans[MAXN];
int n,k;
int suf[MAXN];

inline void Solve(){
    scanf("%d%d",&n,&k);scanf("%s",str+1);FOR(i,1,n) a[i] = (str[i]=='0');
    suf[n+1] = 0;
    FOR(i,1,k-20) ans[i] = 0;
    int l = std::max(1,k-19),len = l-1;
    std::vector<int> S;
    ROF(i,n,1) suf[i] = a[i]?0:suf[i+1]+1;
    FOR(i,1,n-k+1){
        if(suf[i] < len) continue;
        int t = 0;
        FOR(j,i+len,i+k-1) t = (t<<1)|a[j];
        S.pb(t);
    }
    std::sort(all(S));S.erase(std::unique(all(S)),S.end());
    FOR(i,l,k){
        int bit = k-i;
        int sm = 0;
        for(auto x:S){
            if(x != -1) if(!((x>>bit)&1)) sm++;
        }
        if(sm != (1<<(k-i))) ans[i] = 0;
        else{
            sm = 0;
            for(auto x:S){
                if(x != -1) if((((x>>bit)&1))) sm++;
            }
            if(sm == ((1<<(k-i)))){
                puts("NO");
                return;
            }
            else ans[i] = 1;
        }
        for(auto &x:S) if(((x>>bit)&1) != ans[i]) x = -1;
    }
    puts("YES");
    FOR(i,1,k) printf("%d",ans[i]);puts("");
}

int main(){
    int T;scanf("%d",&T);while(T--) Solve();
    return 0;
}