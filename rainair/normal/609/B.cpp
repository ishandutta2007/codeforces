#include <bits/stdc++.h>

#define fi first
#define se second
#define db double
#define U unsigned
#define P std::pair<int,int>
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
int n,m;
int cnt[MAXN];

int main(){
    scanf("%d%d",&n,&m);
    FOR(i,1,n){
        int x;scanf("%d",&x);++cnt[x];
    }
    LL ans = 0;
    FOR(i,1,m){
        FOR(j,i+1,m){
            ans += cnt[i]*cnt[j];
        }
    }
    printf("%lld\n",ans);
    return 0;
}