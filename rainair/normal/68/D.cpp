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

int h,q;
std::map<int,int> S,a;

int main(){
    // freopen("A.in","r",stdin);
    // freopen("A.out","w",stdout);
    scanf("%d%d",&h,&q);
    while(q--){
        char opt[23];
        scanf("%s",opt);
        if(opt[0] == 'a'){
            int x,y;scanf("%d%d",&x,&y);
            a[x] += y;
            while(x) S[x] += y,x >>= 1;
        }
        if(opt[0] == 'd'){
            int x = 1;LL ans = 0;int mx = 0;
            FOR(i,1,h){
                int o = 1<<(h-i);
                if(S[x<<1] < S[x<<1|1]){
                    ans += 1ll*o*std::max(mx,S[x<<1|1]+a[x]);
                    mx = std::max(mx,S[x<<1]+a[x]);
                    x = x<<1|1;
                }
                else{
                    ans += 1ll*o*std::max(mx,S[x<<1]+a[x]);
                    mx = std::max(mx,S[x<<1|1]+a[x]);
                    x = x<<1;
                }
            }
            ans += std::max(mx,a[x]);
            double res = ans;
            FOR(i,1,h)  res /= 2;
            printf("%.10f\n",res);
        }
    }
    return 0;
}