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
int n,a[MAXN],k;
int cnt[1000000+5],now;

inline void add(int x){
    if(!cnt[x]) ++now;
    ++cnt[x];
}

inline void del(int x){
    --cnt[x];if(!cnt[x]) --now;
}

int main(){
    scanf("%d%d",&n,&k);
    FOR(i,1,n) scanf("%d",a+i);
    int l = 1,mx = 0,L = 1,R = 0;
    FOR(r,1,n){
        add(a[r]);
        while(now > k) del(a[l++]);
        if(R-L+1 < r-l+1){
            L = l;R = r;
        }
    }
    printf("%d %d\n",L,R);
    return 0;
}