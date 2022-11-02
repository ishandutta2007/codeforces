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

const int MAXN = 2e5 + 5;
char str[MAXN];int n;
int c[2][2];

int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%s",str+1);n = strlen(str+1);
        CLR(c,0);int l = 1;LL ans = 0;
        FOR(r,1,n){
            if(str[r] != '?') ++c[r&1][str[r]-'0'];
            while((c[0][0]&&c[1][0]) || (c[0][1]&&c[1][1]) || (c[0][0] && c[0][1]) || (c[1][0] && c[1][1])){
                if(str[l] != '?') --c[l&1][str[l]-'0'];
                ++l;
            }
            ans += r-l+1;
        }
        printf("%lld\n",ans);
    }
    return 0;
}