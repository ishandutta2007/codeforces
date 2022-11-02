/*
 * Author: RainAir
 * Time: 2019-07-13 09:59:32
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
#define Re register
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(Re int i = a;i <= b;++i)
#define ROF(i,a,b) for(Re int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

int h,r;
//sqrt(3)
int main(){
    scanf("%d%d",&r,&h);
    int ans = (int)(h/r*2),t = h%r;
    if(t*2 < r) ans++;
    else if(t*2 < std::sqrt(3.0)*r) ans += 2;
    else ans += 3;
    printf("%d\n",ans);
    return 0;
}