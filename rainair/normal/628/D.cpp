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

const int MAXN = 2000+5;
const int ha = 1e9 + 7;

int m,d;
int f[MAXN][MAXN][2];

inline void add(int &x,int y){
    x += y-ha;x += x>>31&ha;
}

char str[MAXN];
int n;

inline int work(){
    CLR(f,0);
    f[0][0][1] = 1;
    FOR(i,0,n-1){
        FOR(j,0,m-1){
            FOR(k,0,1){
                if(!f[i][j][k]) continue;
                int up = k?str[i+1]-'0':9;
                FOR(x,0,up){
                    if(!(i&1) && x == d) continue;
                    if((i&1) && x != d) continue;
                    add(f[i+1][(j*10+x)%m][k&(x==up)],f[i][j][k]);
                }
            }
        }
    }
    return (f[n][0][0]+f[n][0][1])%ha;
}

int main(){
    scanf("%d%d",&m,&d);
    scanf("%s",str+1);n = strlen(str+1);
//    work();
//    exit(0);
    int ans = (ha-work())%ha;
    bool flag = 1;int x = 0;
    FOR(i,1,n){
        x = (x*10+str[i]-'0')%m;
        if(i&1) flag &= str[i]!=d+'0';
        else flag &= str[i]==d+'0';
    }
    flag &= (x==0);
    (ans += flag) %= ha;
    scanf("%s",str+1);n = strlen(str+1);
    add(ans,work());
    printf("%d\n",ans);
    return 0;
}