#include <bits/stdc++.h>

#define fi first
#define se second
#define DB double
#define U unsigned
#define P std::pair
#define LL long long
#define LD long double
#define pb emplace_back
#define MP std::make_pair
#define SZ(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 2e5 + 5;
int n,p,k;

struct Node{
    int a,b,id;
}a[MAXN];

LL pre[MAXN],suf[MAXN];

int main(){
    scanf("%d%d%d",&n,&p,&k);
    FOR(i,1,n) scanf("%d%d",&a[i].a,&a[i].b),a[i].id = i;
    std::sort(a+1,a+n+1,[&](const Node &x,const Node &y){return x.b > y.b || (x.b == y.b && x.a < y.a);});
    std::priority_queue<int,std::vector<int>,std::greater<int> > q;LL sm = 0;
    FOR(i,1,k-1) q.push(a[i].a),sm += a[i].a;
    FOR(i,k,n-(p-k)){
        q.push(a[i].a);sm += a[i].a;
        while(SZ(q) > k) sm -= q.top(),q.pop();
        pre[i] = sm;
    }
    while(!q.empty()) q.pop();sm = 0;
    if(p-k > 0){
        ROF(i,n,n-(p-k)+2) q.push(a[i].b),sm += a[i].b;
        ROF(i,n-(p-k)+1,k){
            q.push(a[i].b);sm += a[i].b;
            while(SZ(q) > p-k) sm -= q.top(),q.pop();
            suf[i] = sm;
        }
    }
    int ps = -1;P<LL,LL> mx(-1e18,-1e18);
    FOR(i,k,n-(p-k)){
        P<LL,LL> c = MP(pre[i],suf[i+1]);
        if(mx < c){
            mx = c;
            ps = i;
        }
    }
    std::sort(a+1,a+ps+1,[&](const Node &x,const Node &y){return x.a > y.a;});
    FOR(i,1,k) printf("%d ",a[i].id);
    if(ps != n){
        std::sort(a+ps+1,a+n+1,[&](const Node &x,const Node &y){return x.b > y.b;});
        FOR(i,ps+1,ps+(p-k)) printf("%d ",a[i].id);
    }
    puts("");
    return 0;
}