/*
 * Author: RainAir
 * Time: 2020-07-10 10:18:16
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
#define int LL
const int MAXN = 1000+5;
int n;
int x[MAXN],y[MAXN];
inline int query(int t,int i,int j,int k){
    printf("%lld %lld %lld %lld\n",t,i,j,k);std::fflush(stdout);/*
    int xa = x[j]-x[i],ya = y[j]-y[i],xb = x[k]-x[i],yb = y[k]-y[i];
    int s = xa*yb-xb*ya;
    if(t == 1){
        return std::abs(s);
    }
    else{
        return s > 0 ? 1 : -1;
    }*/
    int res;scanf("%lld",&res);return res;
}
std::vector<int> v1,v2;
int s[MAXN];

inline bool cmp(int x,int y){
    return s[x] < s[y];
}

inline void solve(std::vector<int> &v,int type){
    if(v.size() <= 1) return;
    int mx=0,ps=0;
    for(auto x:v){
        if(mx < s[x]){
            mx = s[x];
            ps = x;
        }
    }
    std::vector<int> v1,v2;
    for(auto x:v){
        if(x == ps) continue;
        int t = type==1?query(2,1,ps,x):query(2,2,ps,x);
        if(t < 0) v1.pb(x);
        else v2.pb(x);
    }
    std::sort(all(v1),cmp);
    std::sort(all(v2),cmp);std::reverse(all(v2));
    v.clear();
    for(auto x:v1) v.pb(x);
    v.pb(ps);
    for(auto x:v2) v.pb(x);
}

signed main(){
    scanf("%lld",&n);
//    FOR(i,1,n) scanf("%d%d",x+i,y+i);
    FOR(i,3,n){
        int t = query(2,1,2,i);
        if(t < 0) v1.pb(i);
        else v2.pb(i);
    }// n-2
    FOR(i,3,n) s[i] = query(1,1,2,i); // n-2
    solve(v1,1);solve(v2,2);//n-4
    printf("0 1 ");
    for(auto x:v1) printf("%lld ",x);
    printf("2 ");
    for(auto x:v2) printf("%lld ",x);
    puts("");std::fflush(stdout);
    return 0;
}