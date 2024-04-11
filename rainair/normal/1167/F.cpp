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
#define U unsigned
#define P std::pair
#define Re register
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(Re int i = a;i <= b;++i)
#define ROF(i,a,b) for(Re int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 5e5 + 10;
const int ha = 1e9 + 7;

int n;

struct BIT{
    #define lowbit(x) ((x)&(-x))
    LL tree[MAXN];

    inline void clear(){CLR(tree,0);}

    inline void add(int pos,int x){
        while(pos <= n){
            (tree[pos] += x) %= ha;
            pos += lowbit(pos);
        }
    }

    inline LL calc(int pos){
        LL res = 0ll;
        while(pos){
            (res += tree[pos]) %= ha;
            pos -= lowbit(pos);
        }
        return res;
    }
}bit;

int a[MAXN],origin[MAXN],cn;
std::map<int,int> S;
LL ans = 0ll;

inline void calc(int k){
    if(!k) std::reverse(a+1,a+n+1);bit.clear();
    FOR(i,1,n){
        //bit.add(a[i],i); 
        int t = bit.calc(a[i])%ha;
        //printf("t:%d a[%d]:%d origin[a[%d]]:%d (n-i+1):%d\n",t,i,a[i],i,origin[a[i]],n-i+1);
        (ans += 1ll*(n-i+1)*origin[a[i]]%ha*t%ha) %= ha;
        if(k) (ans += 1ll*(n-i+1)*origin[a[i]]%ha*i%ha) %= ha;
        bit.add(a[i],i);
    }
}

int main(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",a+i),S.insert(MP(a[i],0));
    for(auto &x:S){
        x.second = ++cn;
        origin[cn] = x.first;
    }
    FOR(i,1,n) a[i] = S[a[i]];
    calc(1);calc(0);
    printf("%lld\n",ans);
    return 0;
}