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
int p,ha;

inline int qpow(int a,int n){
    int res = 1;
    while(n){
        if(n & 1) res = 1ll*res*a%p;
        a = 1ll*a*a%p;
        n >>= 1;
    }
    return res;
}
int ans;
int main(){
    scanf("%d",&p);ha = p;
    FOR(g,1,p-1){
        bool flag = true;
        FOR(n,1,p-2){
            if((qpow(g,n)-1+ha)%ha == 0){
                flag = false;break;
            }
        }
        if((qpow(g,p-1)-1+ha)%ha != 0) flag = false;
        if(!flag) continue;
        ans++;
    }
    printf("%d\n",ans);
    return 0;
}