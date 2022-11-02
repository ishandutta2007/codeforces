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

const int MAXN = 10 + 5;
int gs[MAXN][5];
int b[MAXN],c[MAXN],n;
int d[5],e[5];
bool vis[10];

inline P<int,int> chk(int a[],int b[]){
    CLR(vis,0);
    FOR(i,1,4) vis[a[i]] = 1;
    int x = 0,y = 0;
    FOR(i,1,4){
        if(vis[b[i]]){
            if(b[i] == a[i]) ++x;
            else ++y;
        }
    }
    return MP(x,y);
}

int main(){
    scanf("%d",&n);
    FOR(i,1,n){
        char s[23];
        scanf("%s%d%d",s+1,b+i,c+i);
        FOR(j,1,4) gs[i][j] = s[j]-'0';
    }
    int ans = 0;
    FOR(d1,0,9){
        d[1] = d1;
        FOR(d2,0,9){
            if(d2 == d1) continue;
            d[2] = d2;
            FOR(d3,0,9){
                if(d3 == d2 || d3 == d1) continue;
                d[3] = d3;
                FOR(d4,0,9){
                    if(d4 == d3 || d4 == d2 || d4 == d1) continue;
                    d[4] = d4;
                    bool flag = 1;
                    FOR(i,1,n){
                        flag &= MP(b[i],c[i]) == chk(gs[i],d);
                    }
                    if(flag) FOR(i,1,4) e[i] = d[i];
                    ans += flag;
                }
            }
        }
    }
    if(!ans) return puts("Incorrect data"),0;
    if(ans > 1) return puts("Need more data"),0;
    FOR(i,1,4) putchar('0'+e[i]);puts("");
    return 0;
}