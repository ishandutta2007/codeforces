/*
 * Author: RainAir
 * Time: 2020-06-12 15:05:30
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
#define db double
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
const int MAXN = 100+5;
int n,x,m;

inline void Solve(){
    scanf("%d%d%d",&n,&x,&m);
    int ansl = x,ansr = x;
    FOR(i,1,m){
        int l,r;scanf("%d%d",&l,&r);
        if(r < ansl || l > ansr) continue;
        ansl = std::min(l,ansl);ansr = std::max(r,ansr);
    }
    printf("%d\n",ansr-ansl+1);
}

int main(){
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}