/*
 * Author: RainAir
 * Time: 2020-03-06 10:06:20
 */
#include<bits/stdc++.h>

#define fi first
#define se second
#define U unsigned
#define P std::pair<int,int>
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

int main(){
    int T;scanf("%d",&T);
    while(T--){
        int n,d;scanf("%d%d",&n,&d);
        int q = std::sqrt(1.0*d);
        int mn = 1e9+233;
        FOR(x,std::max(0,q-233),std::min(n,q+233)){
            mn = std::min(mn,x+(int)std::ceil(1.0*d/(x+1)));
        }
        puts(mn > n ? "NO" : "YES");
    }
    return 0;
}