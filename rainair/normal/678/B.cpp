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

inline bool pd(int n){
    return n%400 == 0 || (n%4 == 0 && n%100 != 0);
}

int main(){
    int n;scanf("%d",&n);
    int t = n;
    int now = 0;
    while(true){
        now += 365+pd(t);now %= 7;++t;
        if(pd(t) != pd(n) || now) continue;
        printf("%d\n",t);
        return 0;
    }
    return 0;
}