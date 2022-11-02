#include <bits/stdc++.h>

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
int n,a[MAXN];

int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d",&n);FOR(i,1,n) scanf("%d",a+i);
        std::priority_queue<P,std::vector<P>,std::greater<P> > q;
        q.push(MP(0,1));int p = 2;
        int ans = 0;
        while(!q.empty()){
            int dep = q.top().fi;q.pop();ans = std::max(ans,dep);
            int las = -1;std::vector<int> v;
            while(p <= n && las <= a[p]) las = a[p++],v.pb(las);
            for(auto x:v) q.push(MP(dep+1,x));
        }
        printf("%d\n",ans);
    }
    return 0;
}