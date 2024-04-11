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

const int MAXN = 3e5 + 5;
const int ha = 998244353;
std::vector<std::vector<int> > a,b;
int n,m,pw[MAXN];
char str[MAXN];

inline void add(int &x,int y){
    x += y-ha;x += x>>31&ha;
}

int all;
int sm[MAXN];

inline int calc(int len){
    if(len <= 1) return 0;
    int ans = 0;
    FOR(i,0,len-2){// 
        int s = 0,up = i-1;
        if(up >= 0) s = sm[up];
//        FOR(j,0,i-1){
//            if((i-j)%2 == 1) add(s,pw[j]);
//        }
        if(!(i&1)) add(s,1);
        s = 1ll*s*pw[len-i-2]%ha;
        add(ans,s);
    }
    ans = 1ll*ans*pw[all-len]%ha;
    return ans;
}

inline int work(){
    int ans = 0;
    FOR(i,1,n){
        int cnt = 0;
        FOR(j,1,m){
            if(a[i][j]) ++cnt;
            else{
                add(ans,calc(cnt));
                cnt = 0;
            }
        }
        add(ans,calc(cnt));
    }
    return ans;
}

int main(){
    pw[0] = 1;FOR(i,1,MAXN-1) pw[i] = 2ll*pw[i-1]%ha;
    sm[0] = pw[0];sm[1] = pw[1];FOR(i,1,MAXN-1) sm[i] = (sm[i-2]+pw[i])%ha;
    scanf("%d%d",&n,&m);a.resize(n+1);
    FOR(i,1,n){
        scanf("%s",str+1);a[i].resize(m+1);
        FOR(j,1,m) a[i][j] = (str[j] == 'o');
    }
    FOR(i,1,n) FOR(j,1,m) all += a[i][j];
    int ans = 0;
    add(ans,work());
    b = a;
    a.resize(m+1);
    FOR(i,1,m) a[i].resize(n+1);
    FOR(i,1,n) FOR(j,1,m) a[j][i] = b[i][j];
    std::swap(n,m);
    add(ans,work());
    printf("%d\n",ans);
    return 0;
}