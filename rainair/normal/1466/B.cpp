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

const int MAXN = 3e5 + 5;
int n,a[MAXN];
int cnt[MAXN];
bool can[MAXN];

inline void Solve(){
    scanf("%d",&n);FOR(i,1,n) scanf("%d",a+i);
    FOR(i,1,2*n+1) cnt[i] = 0,can[i] = 0;
    FOR(i,1,n) ++cnt[a[i]];
    int ans = 0;
    FOR(i,1,2*n){
        if(!cnt[i]) continue;
        ++ans;
        if(cnt[i+1] == 0 && (cnt[i]>1||can[i])){
            ans++;i++;
        }
        else if(cnt[i] > 1 || can[i]){
            can[i+1] = 1;
        }
    }
    printf("%d\n",ans);
}

int main(){
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}