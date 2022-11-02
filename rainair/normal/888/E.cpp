#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdlib>
#include <cstdio>
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

const int MAXN = 40;
int a[MAXN],n,m,mid;
std::vector<int> S;
std::unordered_map<int,bool> vis;

inline void dfs1(int step,int sum){
    if(step == mid + 1){
        if(!vis[sum]){
            S.pb(sum);vis[step] = true;
        }
        return;
    }
    dfs1(step+1,(sum+a[step])%m);
    dfs1(step+1,sum);
}
int ans = 0;
inline void dfs2(int step,int sum){
    if(step == n + 1){
        int k = m-sum;//DEBUG(k);
        int x = lower_bound(all(S),k)-S.begin();//DEBUG(x);
        if(!x) x = S.size()-1,ans = std::max(ans,(S[x]+sum)%m);
        else ans = std::max(ans,(S[x-1]+sum)%m);
        return;
    }
    dfs2(step+1,(sum+a[step])%m);
    dfs2(step+1,sum);
}

int main(){
    scanf("%d%d",&n,&m);mid = n>>1;
    FOR(i,1,n) scanf("%d",a+i);
    dfs1(1,0);
    std::sort(all(S));
    ans = S[(int)S.size()-1];
    dfs2(mid+1,0);
    printf("%d\n",ans);
    return 0;
}