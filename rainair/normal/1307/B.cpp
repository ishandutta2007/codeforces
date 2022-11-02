/*
 * Author: RainAir
 * Time: 2020-03-02 08:34:35
 */
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
        int n,x;scanf("%d%d",&n,&x);
        bool flag = 0;
        int mx = 0;FOR(i,1,n){
            int t;scanf("%d",&t);mx = std::max(mx,t);
            if(x == t) flag = 1;
        }
        if(flag){
            puts("1");
            continue;
        }
        if(x%mx == 0){
            printf("%d\n",x/mx);
        }
        else if(mx > x){
            puts("2");
        }
        else printf("%d\n",x/mx+1);
    }
    return 0;
}