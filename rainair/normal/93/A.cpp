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

int main(){
    int n,m,a,b;
    scanf("%d%d%d%d",&n,&m,&a,&b);
    --a;--b;
    if(a/m == b/m || (a%m == 0 && (b%m == m-1 || b == n-1))){
        puts("1");
        return 0;
    }
    if(a%m == 0 || b%m == m-1 || b == n-1 || (b%m+1 == a%m)){
        puts("2");
        return 0;
    }
    if(b/m - a/m == 1){
        puts("2");
        return 0;
    }
    puts("3");
    return 0;
}