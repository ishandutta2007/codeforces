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

const int MAXN = 9 + 5;
int n,m;
int a[MAXN][MAXN];
int b[MAXN][MAXN],mx;
std::vector<P<int,int> > vec;
std::mt19937 g(time(0));

inline void dfs(int x,int las){
    if(x+(n*m-las)/5 < mx) return;
    if(las > SZ(vec)) return;
    bool flag = 0;
    FOR(c,las,las){
        int i,j;std::tie(i,j) = vec[c];
        if(i+2 <= n && j >= 2 && j+1 <= m){
            if(!a[i][j] && !a[i][j-1] && !a[i][j+1] && !a[i+1][j] && !a[i+2][j]){
                a[i][j] = a[i][j-1] = a[i][j+1] = a[i+1][j] = a[i+2][j] = x+1;
                dfs(x+1,las+1);flag = 1;
                a[i][j] = a[i][j-1] = a[i][j+1] = a[i+1][j] = a[i+2][j] = 0;
            }
        }
        if(i-2 >= 1 && j >= 2 && j+1 <= m){
            if(!a[i][j] && !a[i][j-1] && !a[i][j+1] && !a[i-1][j] && !a[i-2][j]){
                a[i][j] = a[i][j-1] = a[i][j+1] = a[i-1][j] = a[i-2][j] = x+1;
                dfs(x+1,las+1);flag = 1;
                a[i][j] = a[i][j-1] = a[i][j+1] = a[i-1][j] = a[i-2][j] = 0;
            }
        }
        if(j-2 >= 1 && i >= 2 && i < n){
            if(!a[i][j] && !a[i][j-1] && !a[i][j-2] && !a[i-1][j] && !a[i+1][j]){
                a[i][j] = a[i][j-1] = a[i][j-2] = a[i-1][j] = a[i+1][j] = x+1;
                dfs(x+1,las+1);flag = 1;
                a[i][j] = a[i][j-1] = a[i][j-2] = a[i-1][j] = a[i+1][j] = 0;
            }
        }
        if(j+2 <= m && i >= 2 && i < n){
            if(!a[i][j] && !a[i][j+1] && !a[i][j+2] && !a[i-1][j] && !a[i+1][j]){
                a[i][j] = a[i][j+1] = a[i][j+2] = a[i-1][j] = a[i+1][j] = x+1;
                dfs(x+1,las+1);flag = 1;
                a[i][j] = a[i][j+1] = a[i][j+2] = a[i-1][j] = a[i+1][j] = 0;
            }
        }
    }
    dfs(x,las+1);
    if(!flag){
        if(mx < x){
            mx = x;
            FOR(i,1,n) FOR(j,1,m) b[i][j] = a[i][j];
        }
    }
}

int main(){
    scanf("%d%d",&n,&m);
    FOR(i,1,n) FOR(j,1,m) vec.pb(i,j);
//    std::shuffle(all(vec),g);
    mx = 0;dfs(0,0);
    printf("%d\n",mx);
    FOR(i,1,n){
        FOR(j,1,m) putchar(b[i][j]?'A'+b[i][j]-1 : '.');
        puts("");
    }
    return 0;
}