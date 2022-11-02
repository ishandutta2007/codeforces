/*
 * Author: RainAir
 * Time: 2019-07-13 08:59:55
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

const int MAXN = 10+5;
int p[MAXN],n;

int main(){
    scanf("%d",&n);
    FOR(i,1,n){
        int x;scanf("%d",&x);
        p[x]++;
    }
    if(p[5] || p[7] || p[1] != n/3 || p[2]+p[3] != p[4]+p[6] || p[3] > p[6] || p[4] > p[2]){
        puts("-1");return 0;
    }
    FOR(i,1,p[3]){
        puts("1 3 6");
    }
    FOR(i,1,p[4]){
        puts("1 2 4");
    }
    FOR(i,1,p[6]-p[3]){
        puts("1 2 6");
    }
    return 0;
}