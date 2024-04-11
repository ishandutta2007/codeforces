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
    int T;scanf("%d",&T);
    while(T--){
        int n;scanf("%d",&n);
        std::vector<int> a(n,0);
        FOR(i,0,n-1) scanf("%d",&a[i]);
        std::sort(all(a));
        int p = 0,v = a[0];
        while(p < n && a[p] == v) ++p;
        printf("%d\n",n-p);
    }
    return 0;
}