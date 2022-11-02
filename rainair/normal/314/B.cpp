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

const int MAXN = 100+5;
int b,d;
char a[MAXN],c[MAXN];
P<int,int> f[MAXN];//  c[j] 

int main(){
    scanf("%d%d",&b,&d);
    scanf("%s%s",a+1,c+1);
    int n = strlen(a+1),m = strlen(c+1);
    FOR(i,1,m){
        f[i] = MP(0,i);
        FOR(j,1,n){
            if(a[j] == c[f[i].se]){
                ++f[i].se;
                if(f[i].se > m) f[i].se = 1,f[i].fi++;
            }
        }
    }
    P<int,int> now = MP(0,1);
    FOR(i,1,b){
        now.fi += f[now.se].fi;
        now.se = f[now.se].se;
    }
    printf("%d\n",now.fi/d);
    return 0;
}