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

const int MAXN = 1001+5;
int a[MAXN][MAXN];
bool p[MAXN];
int prime[MAXN],cnt;

inline void prework(){
    FOR(i,2,MAXN-1){
        if(!p[i]) prime[++cnt] = i;
        for(int j = 1;j <= cnt && i*prime[j] < MAXN;++j){
            p[i*prime[j]] = 1;
        }
    }
}

int main(){
    int T;scanf("%d",&T);prework();
    while(T--){
        int n;scanf("%d",&n);
        if(!p[n]){
            FOR(i,1,n) FOR(j,1,n) a[i][j] = 1;
        }
        else{
            int t = n-1,aa = 1;
            while(p[aa+t] || !p[aa]) ++aa;
            FOR(i,1,n) FOR(j,1,n){
                if(i != j) a[i][j] = 1;
                else a[i][j] = aa;
            }
        }
        FOR(i,1,n) FOR(j,1,n) printf("%d%c",a[i][j]," \n"[j==n]);
    }
    return 0;
}