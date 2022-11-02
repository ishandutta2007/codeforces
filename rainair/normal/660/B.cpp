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

const int MAXN = 100+5;
int a[4][MAXN],n,m;

int main(){
    scanf("%d%d",&n,&m);int id = 0;
    FOR(i,1,n){
        if(!m) break;
        --m;a[0][i] = ++id;
        if(!m) break;
        --m;a[3][i] = ++id;
    }
    FOR(i,1,n){
        if(!m) break;
        --m;a[1][i] = ++id;
        if(!m) break;
        --m;a[2][i] = ++id;
    }
    FOR(i,1,n){
        auto gao = [&](int x){
            if(x) printf("%d ",x);
        };
        gao(a[1][i]);
        gao(a[0][i]);
        gao(a[2][i]);
        gao(a[3][i]);
    }
    puts("");
    return 0;
}