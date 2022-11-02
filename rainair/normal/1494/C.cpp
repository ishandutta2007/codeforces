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

int n,m,a[MAXN],b[MAXN];
int suf[MAXN];

inline int work(std::vector<int> A,std::vector<int> B){
    if(A.empty() || B.empty()) return 0;
    int ans = 0,p = -1;
    suf[SZ(B)] = 0;
    ROF(i,SZ(B)-1,0){
        int q = std::lower_bound(all(A),B[i])-A.begin();
        suf[i] = suf[i+1]+(q >= 0 && q < SZ(A) && A[q] == B[i]);
    }
    FOR(i,0,SZ(B)-1){
        while(p+1 < SZ(A) && A[p+1] <= B[i]) ++p;
        if(p == -1) continue;
        int q = std::lower_bound(all(B),B[i]-p)-B.begin();
        ans = std::max(ans,i-q+1+suf[i+1]);
    }
    return ans;
}

inline void Solve(){
    scanf("%d%d",&n,&m);
    FOR(i,1,n) scanf("%d",a+i);
    FOR(i,1,m) scanf("%d",b+i);
    int p1 = 1,p2 = 1;
    while(p1 <= n && a[p1] < 0) ++p1;
    while(p2 <= m && b[p2] < 0) ++p2;
    std::vector<int> A,B;
    FOR(i,p1,n) A.pb(a[i]);
    FOR(i,p2,m) B.pb(b[i]);
    int ans = work(A,B);
    A.clear();B.clear();
    ROF(i,p1-1,1) A.pb(-a[i]);
    ROF(i,p2-1,1) B.pb(-b[i]);
    ans += work(A,B);
    printf("%d\n",ans);
}

int main(){
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}