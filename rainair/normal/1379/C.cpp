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

const int MAXN = 2e5 + 5;
LL a[MAXN],b[MAXN];
LL sm[MAXN];

int main(){
    int T;scanf("%d",&T);
    while(T--){
        std::vector<LL> S;
        int n,m;scanf("%d%d",&n,&m);
        FOR(i,1,m) scanf("%lld%lld",a+i,b+i),S.pb(a[i]);
        std::sort(all(S));sm[m+1] = 0;
        ROF(i,m,1) sm[i] = sm[i+1]+S[i-1];
        LL ans = 0;
        FOR(i,1,m){
            int t = std::lower_bound(all(S),b[i])-S.begin()+1;
            int ct = m-t+1;
            if(ct < n){
                LL gx = sm[t],res = n-ct;
                if(a[i] < b[i]) res--,gx += a[i];
                gx += res*b[i];
                ans = std::max(ans,gx);
            }
            else{
                ans = std::max(ans,sm[m-n+1]);
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}