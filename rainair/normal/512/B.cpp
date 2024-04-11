/*
 * sto Qingyu orz
 * sqysqy,
 * 
 * sqy
 * Author: RainAir
 * Time: 2019-10-20 15:56:13
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

const int MAXN = 300+5;

inline int gcd(int a,int b){
    return !b ? a : gcd(b,a%b);
}

int n,a[MAXN],b[MAXN],now;
std::map<int,int> f[2];

int main(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",a+i);
    FOR(i,1,n) scanf("%d",b+i);
    f[now][a[1]] = b[1];
    FOR(i,2,n){
        f[now^1].clear();
        f[now^1][a[i]] = b[i];
        for(auto x:f[now]){
            int g = gcd(x.fi,a[i]);
            if(!f[now^1].count(g)) f[now^1][g] = x.se+b[i];
            else f[now^1][g] = std::min(f[now^1][g],x.se+b[i]);
        }
        for(auto x:f[now]){
            if(!f[now^1].count(x.fi)) f[now^1][x.fi] = x.se;
            else f[now^1][x.fi] = std::min(f[now^1][x.fi],x.se);
        }
        now ^= 1;
    }
    if(!f[now].count(1)) puts("-1");
    else printf("%d\n",f[now][1]);
    return 0;
}