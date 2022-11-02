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

const int MAXN = 2e5 + 5;
int b[MAXN],n;

inline int work(){
    int c = 1,d = 0,ans = 0;
    ans += b[1]-1,d += b[1]-1;
    FOR(i,2,n){
        int t = b[i]-b[i-1]-1;
        if(t <= c){
            c -= t;
        }
        else{
            t -= c;c = 0;
            ans += t;d += t;
        }
        if(n-i+1 > d) ++c;
    }
    return ans;
}

inline void Solve(){
    scanf("%d",&n);FOR(i,1,n) scanf("%d",b+i);
    int l = 0,r = n;
    r -= work();
    std::reverse(b+1,b+n+1);
    FOR(i,1,n) b[i] = 2*n-b[i]+1;
    l += work();
    printf("%d\n",std::max(0,r-l+1));
}

int main(){
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}