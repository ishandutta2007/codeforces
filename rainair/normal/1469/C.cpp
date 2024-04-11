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
int n,k,a[MAXN];

inline void Solve(){
    scanf("%d%d",&n,&k);
    FOR(i,1,n) scanf("%d",a+i);
    int l = a[1],r = a[1];
    FOR(i,2,n){
        int ll = a[i],rr = a[i]+k-1;
        ll = std::max(ll,l-k+1);
        rr = std::min(rr,r+k-1);
        if(ll > rr){
            puts("NO");
            return;
        }
        l = ll;r = rr;
    }
    if(l != a[n]) puts("NO");
    else puts("YES");
}

int main(){
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}