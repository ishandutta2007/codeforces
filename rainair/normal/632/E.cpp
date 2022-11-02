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

const int MAXN = 1000+5;
int n,k,a[MAXN];
int f[MAXN*MAXN];

int main(){
    scanf("%d%d",&n,&k);
    FOR(i,1,n) scanf("%d",a+i);
    int mx = *std::max_element(a+1,a+n+1);
    int mn = *std::min_element(a+1,a+n+1);
    int m = (mx-mn)*k;
    FOR(i,1,n) a[i] -= mn;
    CLR(f,0x3f);f[0] = 0;
    FOR(i,1,n){
        FOR(j,a[i],m){
            f[j] = std::min(f[j],f[j-a[i]]+1);
        }
    }
    FOR(i,0,m) if(f[i] <= k) printf("%d ",i+k*mn);
    puts("");
    return 0;
}