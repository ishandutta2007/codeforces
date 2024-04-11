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

const int MAXN = 2e5+5;
int a[MAXN],p,n;
std::map<int,int> S;
std::vector<int> G[MAXN];

int main(){
    scanf("%d%d",&n,&p);
    FOR(i,1,n) scanf("%d",a+i);
    std::sort(a+1,a+n+1);std::reverse(a+1,a+n+1);
    int mx = a[1],lim = mx-n;
    FOR(i,1,n) if(lim <= a[i]) G[a[i]-lim].pb(i);
    FOR(i,1,n) a[i] = n-a[i]-i+1;
    bool flag = 0;
    FOR(i,1,n){
//        DEBUG(a[i]+mx-n);DEBUG(n-i+1);
        if(a[i]+mx-n <= n-i+1) S[(a[i]%p+p)%p]++;
        else if(((n-i+1)%p+p)%p == 0){
            puts("0");return 0;
        }
    }
    std::vector<int> ans;
    FOR(x,mx-n,mx){
        bool flag = 0;
        for(auto xx:G[x-lim]){
            S[(a[xx]%p+p)%p]--;
            flag |= (((n-xx+1) % p) == 0);
        }
        if(flag) break;
        if(S[(p-x%p)%p]) continue;
        ans.pb(x);
    }
    printf("%d\n",(int)ans.size());
    for(auto x:ans) printf("%d ",x);puts("");
    return 0;
}