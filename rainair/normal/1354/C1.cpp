/*
 * Author: RainAir
 * Time: 2020-05-17 17:35:52
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
const double pi = acos(-1);
inline void Solve(){
    int n;scanf("%d",&n);
    if(n&1){

    }
    else{
        n *= 2;
        double tt = 1/tan(pi/n);
        printf("%.10f\n",tt);
    }
}

int main(){
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}