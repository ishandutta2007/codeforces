#include <bits/stdc++.h>

#define fi first
#define se second
#define db double
#define U unsigned
#define P std::pair<LL,int>
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 1e5 + 5;
LL h[MAXN],a[MAXN],t[MAXN];
int n,m,k,p;

int main(){
    scanf("%d%d%d%d",&n,&m,&k,&p);
    FOR(i,1,n) scanf("%lld%lld",h+i,a+i);
    LL l = 0,r = 1e13,ans = -1;
    while(l <= r){
        LL mid = (l + r) >> 1;
        auto chk = [&](){
            std::priority_queue<P,std::vector<P>,std::greater<P> > q;
            FOR(i,1,n) t[i] = mid;
            FOR(i,1,n) if(t[i]/a[i] < m) q.push(MP(t[i]/a[i],i));
            int cnt = m*k;
            FOR(i,1,m){
                if(!q.empty() && q.top().fi < i) return false;
                int tmp = k;
                while(tmp && !q.empty()){
                    P v = q.top();q.pop();
                    t[v.se] += p;
                    if(t[v.se]/a[v.se] < m) q.push(MP(t[v.se]/a[v.se],v.se));
                    --tmp;
                }
                cnt -= k-tmp;
                //if(!q.empty() && q.top().fi <= i) return false;
                if(q.empty()) break;
            }
            LL r = 0;
            FOR(i,1,n) t[i] -= m*a[i];
            FOR(i,1,n) if(t[i] < h[i]) r += (h[i]-t[i]+p-1)/p;
            return r <= cnt;
        };
        if(chk()) ans = mid,r = mid-1;
        else l = mid+1;
    }
    printf("%lld\n",ans);
    return 0;
}