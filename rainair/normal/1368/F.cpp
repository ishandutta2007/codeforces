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

const int MAXN = 1000+5;

inline int query(std::vector<int> v){
    printf("%d ",(int)v.size());for(auto x:v) printf("%d ",x);puts("");std::fflush(stdout);
    int res;scanf("%d",&res);
    if(res == -1) exit(0);
    return res;
}

int n,k=1;
int vis[MAXN];
// -1: ban

inline void chk(){
    int t = 0;FOR(i,1,n) t += (vis[i] == 1);
    if(t == n-(k-1)-(int)std::ceil(1.0*n/k)){
        puts("0");std::fflush(stdout);exit(0);
    }
}

int main(){
    scanf("%d",&n);
    FOR(i,2,n){
        int gx1 = n-(k-1)-(int)std::ceil(1.0*n/k);
        int gx2 = n-(i-1)-(int)std::ceil(1.0*n/i);
        if(gx1 < gx2) k = i;
    }
    for(int i = 1;i <= n;i += k) vis[i] = -1;
    while(true){
        chk();std::vector<int> v1;
        int t = k;
        FOR(i,1,n){
            if(!t) break;
            if(vis[i] == 0) v1.pb(i),vis[i] = 1,--t;
        }
        int s = query(v1);
        FOR(i,1,k){
            if(vis[s] == 1) vis[s] = 0;
            s = s%n+1;
        }
    }
    return 0;
}