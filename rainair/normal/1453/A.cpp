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

int cnt[101];

int main(){
    int T;scanf("%d",&T);
    while(T--){
        int n,m;scanf("%d%d",&n,&m);
        CLR(cnt,0);
        FOR(i,1,n){
            int x;scanf("%d",&x);
            ++cnt[x];
        }
        FOR(i,1,m){
            int x;scanf("%d",&x);
            ++cnt[x];
        }
        int ans = 0;
        FOR(i,1,100) ans += (cnt[i] == 2);
        printf("%d\n",ans);
    }
    return 0;
}