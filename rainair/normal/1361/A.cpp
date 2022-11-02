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

const int MAXN = 1e6 + 5;

std::vector<int> G[MAXN];
int n,m;
int ans[MAXN];
int p[MAXN];
int a[MAXN];

inline bool cmp(int x,int y){
    return a[x] < a[y];
}
int aa[MAXN];
int main(){
    scanf("%d%d",&n,&m);
    FOR(i,1,m){
        int u,v;scanf("%d%d",&u,&v);
        G[u].pb(v);G[v].pb(u);
    }
    FOR(i,1,n) scanf("%d",a+i);
    FOR(i,1,n) p[i] = i;
    std::sort(p+1,p+n+1,cmp);
    FOR(i,1,n){
        std::vector<int> S;
        for(auto x:G[p[i]]){
            if(!ans[x]) continue;
            S.pb(a[x]);
        }
        std::sort(all(S));
        int mn = 1;
        for(auto x:S) if(x == mn) mn++;
        if(mn == a[p[i]]){
            ans[p[i]] =  i;
        }
        else{
            puts("-1");return 0;
        }
    }
    FOR(i,1,n) aa[ans[i]] = i;
    FOR(i,1,n) printf("%d ",aa[i]);puts("");
    return 0;
}