/*
 * Author: RainAir
 * Time: 2020-06-12 15:14:03
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

const int MAXN = 5e5 + 5;
const int MAXM = 1e7 + 6;
int d1[MAXN],d2[MAXN];
int d[MAXM];
bool p[MAXM];
int prime[MAXM],cnt;

inline void prework(){
    d[1] = 1;
    FOR(i,2,MAXM-1){
        if(!p[i]) prime[++cnt] = i,d[i] = i;
        for(int j = 1;j <= cnt && i*prime[j] < MAXM;++j){
            p[i*prime[j]] = 1;
            d[i*prime[j]] = prime[j];
            if(!(i%prime[j])){
                break;
            }
        }
    }
}

int main(){
    prework();
    int n;scanf("%d",&n);
    FOR(i,1,n){
        int x;scanf("%d",&x);
        if(x == 1){
            d1[i] = d2[i] = -1;
        }
        int t = x;
        int p = 1;
        while(!(t%d[x])) t /= d[x],p *= d[x];
        if(p == 1 || t == 1){
            d1[i] = d2[i] = -1;
        }
        else d1[i] = p,d2[i] = t;
    }
    FOR(i,1,n) printf("%d ",d1[i]);puts("");
    FOR(i,1,n) printf("%d ",d2[i]);puts("");
    return 0;
}