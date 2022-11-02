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

const int MAXN = 500+5;
int a[MAXN][MAXN],n,m;
int b[MAXN][MAXN];

int main(){
    scanf("%d%d",&n,&m);
    FOR(i,1,n) FOR(j,1,m) scanf("%d",&a[i][j]);
    FOR(i,1,n){
        FOR(j,1,m){
            printf("%d\n",720720+((i+j)&1?0:a[i][j]*a[i][j]*a[i][j]*a[i][j]));
        }
    }
    return 0;
}