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

const int MAXN = 1000+5;
int a[MAXN],n;

int main(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",a+i);
    if(n == 1){
        puts(a[1]?"YES":"NO");
        return 0;
    }
    int c = std::accumulate(a+1,a+n+1,0);
    puts(c==n-1?"YES":"NO");
    return 0;
}