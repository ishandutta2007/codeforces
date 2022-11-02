/*
 * Author: RainAir
 * Time: 2019-09-04 17:18:41
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
    int b,g,n;
    scanf("%d%d%d",&b,&g,&n);
    int ans = 0;
    FOR(i,0,b){
        int j = n-i;
        if(j > g) continue;
        if(j < 0) continue;
        ans++;
    }
    printf("%d\n",ans);
    return 0;
}