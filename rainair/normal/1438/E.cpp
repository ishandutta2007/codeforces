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

const int MAXN = 2e5 + 5;
int n,a[MAXN];LL sm[MAXN];
int ans = 0;
int pc[MAXN];

inline bool check(int l,int r){
    return (a[l]^a[r]) == sm[r-1]-sm[l];
}

int main(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",a+i),sm[i] = sm[i-1]+a[i];
    FOR(i,1,n){
        int x = a[i];
        while(x) x >>= 1,++pc[i];
    }
    FOR(l,1,n-2){
        int r = l+2;
        while(r <= n && sm[r-1]-sm[l] < (1ll<<pc[l])){
            if(pc[l] >= pc[r]) ans += check(l,r);
            ++r;
        }
    }
    std::reverse(a+1,a+n+1);std::reverse(pc+1,pc+n+1);
    FOR(i,1,n) sm[i] = sm[i-1]+a[i];
    FOR(l,1,n-2){
        int r = l+2;
        while(r <= n && sm[r-1]-sm[l] < (1ll<<pc[l])){
            if(pc[l] > pc[r]) ans += check(l,r);
            ++r;
        }
    }
    printf("%d\n",ans);
    return 0;
}