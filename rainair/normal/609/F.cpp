#include <bits/stdc++.h>

#define fi first
#define se second
#define db double
#define U unsigned
#define P std::pair
#define LL long long
#define pb push_back
#define MP std::make_pair
#define SZ(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 2e5 + 5;
int n,m;
LL ans[MAXN];int cnt[MAXN];
int x[MAXN];

struct Node{
    LL l,r;int id;
    Node(LL l=0,LL r=0,int id=0) : l(l),r(r),id(id) {}

    inline bool operator < (const Node &t) const {
        return l < t.l;
    }
};

std::set<Node> S;
std::multiset<P<LL,LL> > frog;

P<int,int> a[MAXN];
int id[MAXN];

int main(){
    scanf("%d%d",&n,&m);
    FOR(i,1,n) scanf("%d%d",&a[i].fi,&a[i].se),id[i] = i;
    std::sort(id+1,id+n+1,[&](int x,int y){
              return a[x].fi < a[y].fi;
              });
    S.insert(Node(-1e18,-1e18));S.insert(Node(1e18,1e18));
    LL las = -1e9;
    FOR(cc,1,n){
        int i = id[cc];
        int t = a[i].se;x[i] = a[i].fi;ans[i] = t;
        // [x,x+t]
        LL l = x[i],r = x[i]+t;l = std::max(l,las+1);
        if(l <= r) S.insert(Node(l,r,i));
        las = std::max(las,r);
    }
    FOR(i,1,m){
        int p,b;scanf("%d%d",&p,&b);
        auto it = S.upper_bound(Node(p,0));--it;
        if(it->l > p || p > it->r){
            frog.insert(MP(p,b));
        }
        else{
            ans[it->id] += b;cnt[it->id]++;
            while(!frog.empty()){
                auto p = frog.lower_bound(MP(x[it->id],-1e9));
                if(p == frog.end() || p->fi > x[it->id]+ans[it->id]) break;
                ans[it->id] += p->se;cnt[it->id]++;frog.erase(p);
            }
            LL now = x[it->id]+ans[it->id];
            auto q = it;++q;
            while(q->l != 1e18){
                if(q->r <= now) q = S.erase(q);
                else{
                    Node t = *q;S.erase(q);
                    t.l = std::max(t.l,now+1);S.insert(t);
                    break;
                }
            }
            Node t = *it;S.erase(it);t.r = now;S.insert(t);
        }
    }
    FOR(i,1,n) printf("%d %lld\n",cnt[i],ans[i]);
    return 0;
}