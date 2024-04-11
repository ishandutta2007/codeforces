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

const int MAXN = 1e5 + 5;
int n,m,a[MAXN],cnt[MAXN];

int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        FOR(i,0,m-1) cnt[i] = 0;
        FOR(i,1,n) scanf("%d",a+i),++cnt[a[i]%m];
        int ans = cnt[0]>0;
        FOR(i,1,m/2){
            int t1 = cnt[i],t2 = cnt[m-i];
            if(t1 < t2) std::swap(t1,t2);
            if(i == m-i && t1) ++ans;
            else ans += std::max(0,t1-t2-1)+(t1>0||t2>0);
        }
        printf("%d\n",ans);
    }
    return 0;
}