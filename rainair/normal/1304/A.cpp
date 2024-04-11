/*
 * Author: RainAir
 * Time: 2020-03-03 09:56:14
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
        int x,y,a,b;scanf("%d%d%d%d",&x,&y,&a,&b);// x+at=y-bt
        // at+bt=y-x
        // t=(y-x)/(a+b)
        if(x > y){
            puts("-1");continue;
        }
        if((y-x)%(a+b) != 0){
            puts("-1");continue;
        }
        printf("%d\n",(y-x)/(a+b));
    }
    return 0;
}