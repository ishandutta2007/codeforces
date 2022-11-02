/*
 * Author: RainAir
 * Time: 2019-09-04 17:03:33
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

int n,d,e;
int dol[123] = {0,1,2,5,10,20,100};
int eur[123] = {0,5,10,20,50,100,200};
std::vector<int> v;

int main(){
    scanf("%d%d%d",&n,&d,&e);
    int ans = 1e9;
    FOR(i,0,n){
        if(i*d > n) break;
        ans = std::min(ans,(n-i*d)%(5*e));
    }
    FOR(i,1,6) dol[i] *= d,v.pb(dol[i]);
    FOR(i,1,6) eur[i] *= e,v.pb(eur[i]);
    std::sort(all(v));
    std::reverse(all(v));
    for(auto x:v){
        n %= x;
    }
    printf("%d\n",std::min(ans,n));
    return 0;
}