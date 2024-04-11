#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdlib>
#include <cstdio>
#include <bitset>
#include <vector>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <map>
#include <set>

#define fi first
#define se second
#define db double
#define U unsigned
#define P std::pair<int,int>
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(LL i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

LL l,r,m;

inline bool chk(LL x){
    return x <= r && x >= l;
}

int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%lld%lld%lld",&l,&r,&m);
        LL q = std::sqrt(1.0*m);
        FOR(a,l,r){
            if(m%a <= r-l && m-m%a != 0){
                printf("%lld %lld %lld\n",a,l+m%a,l);
                break;
            }
            if(a-m%a <= r-l){
                printf("%lld %lld %lld\n",a,l,l+(a-m%a));
                break;
            }
        }
    }
    return 0;
}