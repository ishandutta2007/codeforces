/*
 * Author: RainAir
 * Time: 2020-06-01 15:23:44
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

const int MAXN = 5000+5;
int n,k;
std::vector<int> S[MAXN];
int ans[MAXN],mx;

inline int query(std::vector<int> S){
    printf("? %d",(int)S.size());
    for(auto x:S) printf(" %d",x);puts("");
    std::fflush(stdout);
    int res;scanf("%d",&res);
    return res;
}

bool vis[MAXN];

inline void work(int l,int r){
    if(l == r){
        FOR(i,1,n) vis[i] = 0;
        for(auto x:S[l]) vis[x] = 1;
        std::vector<int> tmp;FOR(i,1,n) if(!vis[i]) tmp.pb(i);
        ans[l] = query(tmp);
        return;
    }
    int mid = (l + r) >> 1;
    FOR(i,1,n) vis[i] = 0;
    std::vector<int> tmp;
    FOR(i,l,mid){
        for(auto x:S[i]) tmp.pb(x);
    }
    int t = query(tmp);
    if(t == mx) work(l,mid);
    else work(mid+1,r);
}
char str[MAXN];
inline void Solve(){
    scanf("%d%d",&n,&k);
    FOR(i,1,k){
        S[i].clear();int c;scanf("%d",&c);
        while(c--){
            int x;scanf("%d",&x);
            S[i].pb(x);
        }
        ans[i] = -1;
    }
    std::vector<int> tmp;FOR(i,1,n) tmp.pb(i);
    mx = query(tmp);
    work(1,k);
    FOR(i,1,k) if(ans[i] == -1) ans[i] = mx;
    printf("! ");
    FOR(i,1,k) printf("%d%c",ans[i]," \n"[i==k]);
    std::fflush(stdout);
    scanf("%s",str);
    if(str[0] != 'C'){
        exit(-1);
    }
}

int main(){
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}