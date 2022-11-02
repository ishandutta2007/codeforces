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

const int MAXN = 5000+5;
const int ha = 998244353;
int a[MAXN],n;
int f[2][MAXN],cf[MAXN];
//  i    j
std::vector<int> S;
int las[MAXN];//  i  
int nxt[MAXN];//  i  
int cnt[MAXN];

inline void add(int &x,int y){
    x += y-ha;x += x>>31&ha;
}

int main(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",a+i);
    std::sort(a+1,a+n+1);
    FOR(i,1,n) S.pb(a[i]);S.erase(std::unique(all(S)),S.end());
    FOR(i,1,n) cnt[std::lower_bound(all(S),a[i])-S.begin()+1]++;
    int m = S.size();
    FOR(i,1,m){
        las[i] = las[i-1];
        while(las[i]+1 <= n && a[las[i]+1]*2 <= S[i-1]) las[i]++;
    }
    nxt[0] = 1;
    FOR(i,1,m){
        nxt[i] = -1;
        FOR(j,i+1,m){
            if(S[i-1]*2 <= S[j-1]) {nxt[i] = j;break;}
        }
    }
    int now = 0;f[now][0] = 1;
    FOR(i,1,n){
        CLR(f[now^1],0);CLR(cf,0);
        FOR(j,0,m){
            if(!f[now][j]) continue;
            int t = las[j]-i+1+1;
            if(j == 0) t = 0;
            if(t > 0) add(f[now^1][j],1ll*f[now][j]*t%ha);
            if(nxt[j] != -1) add(cf[nxt[j]],f[now][j]);
        }
        FOR(j,1,m) add(cf[j],cf[j-1]),add(f[now^1][j],1ll*cf[j]*cnt[j]%ha);
        now ^= 1;
//        FOR(i,0,m) printf("%d ",f[now][i]);puts("");
    }
    printf("%d\n",f[now][m]);
    return 0;
}