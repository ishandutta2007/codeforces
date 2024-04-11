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

const int MAXN = 5e5 + 5;
char str[MAXN];int a[MAXN];
LL sm[MAXN][2];int n;

int main(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",a+i);scanf("%s",str+1);
    FOR(i,1,n){
        sm[i][str[i]=='B'] += a[i];
        FOR(j,0,1) sm[i][j] += sm[i-1][j];
    }
    LL s = sm[n][1],ans = s;
    FOR(i,1,n){
        ans = std::max(ans,s-sm[i][1]+sm[i][0]);
        ans = std::max(ans,sm[i][1]+sm[n][0]-sm[i][0]);
    }
    printf("%lld\n",ans);
    return 0;
}