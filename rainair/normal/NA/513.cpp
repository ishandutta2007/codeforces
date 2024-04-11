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

const int MAXN = 1000 + 5;

int a[2][MAXN],now;
char str[MAXN];int n,m;

int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);m = std::min(n,m);
        scanf("%s",str+1);now = 0;
        FOR(i,1,n) a[now][i] = str[i]=='1';
        FOR(i,1,m){
            FOR(j,1,n){
                if(a[now][j]) a[now^1][j] = 1;
                else{
                    int c = 0;
                    if(j > 1) c += a[now][j-1];
                    if(j < n) c += a[now][j+1];
                    if(c == 1) a[now^1][j] = 1;
                    else a[now^1][j] = 0;
                }
            }
            now ^= 1;
        }
        FOR(i,1,n) putchar('0'+a[now][i]);
        puts("");
    }
    return 0;
}