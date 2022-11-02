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

const int MAXN = 4e5 + 5;
char str[MAXN];
int a[4][MAXN],ans[MAXN];
int c[4][2];
int n;

inline void Solve(){
    scanf("%d",&n);CLR(c,0);
    FOR(i,1,3){
        scanf("%s",str+1);
        FOR(j,1,2*n) a[i][j] = str[j]-'0';
    }
    FOR(i,1,3) FOR(j,1,2*n) ++c[i][a[i][j]];
    int c0 = 0,c1 = 0;
    FOR(i,1,3) c0 += (c[i][0] >= c[i][1]),c1 += (c[i][0] < c[i][1]);
    int tag = (c1 >= 2);
    FOR(i,1,3) FOR(j,1,2*n) a[i][j] ^= tag;
    CLR(c,0);
    FOR(i,1,3) FOR(j,1,2*n) ++c[i][a[i][j]];
    int p1 = -1,p2 = -1;
    FOR(i,1,3) if(c[i][0] >= c[i][1]){
        if(p1 == -1) p1 = i;
        else p2 = i;
    }
    int l1 = 1e9,l2 = 1e9,r1 = -1e9,r2 = -1e9;
    FOR(i,1,2*n){
        if(!a[p1][i]) l1 = std::min(l1,i),r1 = std::max(r1,i);
        if(!a[p2][i]) l2 = std::min(l2,i),r2 = std::max(r2,i);
    }
    int sz = 0;
    FOR(i,1,l1-1) ans[++sz] = a[p1][i];
    FOR(i,1,l2-1) ans[++sz] = a[p2][i];

    FOR(i,1,std::max(c[p1][0],c[p2][0])){
        ans[++sz] = 0;
        ++l1;++l2;
        while(l1 <= r1 && a[p1][l1]) ans[++sz] = 1,++l1;
        while(l2 <= r2 && a[p2][l2]) ans[++sz] = 1,++l2;
    }

    FOR(i,r1+1,2*n) ans[++sz] = a[p1][i];
    FOR(i,r2+1,2*n) ans[++sz] = a[p2][i];
    FOR(i,1,sz) ans[i] ^= tag;
    FOR(i,1,sz) putchar(ans[i]+'0');puts("");
}

int main(){
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}