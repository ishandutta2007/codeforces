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

const int MAXN = 2000+5;
char str[MAXN][MAXN];
int n;
int mxx[10],mxy[10],mnx[10],mny[10];
int ans[10];

inline void Solve(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%s",str[i]+1);
    CLR(mxx,-0x3f);CLR(mxy,-0x3f);
    CLR(mnx,0x3f);CLR(mny,0x3f);CLR(ans,0);
    FOR(i,1,n){
        FOR(j,1,n){
            int o = str[i][j]-'0';
            mxx[o] = std::max(mxx[o],i);
            mxy[o] = std::max(mxy[o],j);
            mnx[o] = std::min(mnx[o],i);
            mny[o] = std::min(mny[o],j);
        }
    }
    FOR(i,1,n){
        FOR(j,1,n){
            int o = str[i][j]-'0';
            ans[o] = std::max(ans[o],std::max(j-1,n-j)*abs(i-mnx[o]));
            ans[o] = std::max(ans[o],std::max(j-1,n-j)*abs(i-mxx[o]));
            ans[o] = std::max(ans[o],std::max(i-1,n-i)*abs(j-mny[o]));
            ans[o] = std::max(ans[o],std::max(i-1,n-i)*abs(j-mxy[o]));
        }
    }
    FOR(i,0,9) printf("%d%c",ans[i]," \n"[i==9]);
}

int main(){
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}