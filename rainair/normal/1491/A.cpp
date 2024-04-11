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

const int MAXN = 1e5 + 5;
int n,a[MAXN],c[2],q;

int main(){
    scanf("%d%d",&n,&q);
    FOR(i,1,n) scanf("%d",a+i),++c[a[i]];
    while(q--){
        int t;scanf("%d",&t);
        if(t == 1){
            int x;scanf("%d",&x);
            --c[a[x]];a[x] ^= 1;++c[a[x]];
        }
        else{
            int k;scanf("%d",&k);
            printf("%d\n",k <= c[1] ? 1 : 0);
        }
    }
    return 0;
}