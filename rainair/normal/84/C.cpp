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

const int MAXN = 1e4 + 5;
int n,x[MAXN],r[MAXN];

struct Node{
    int l,r,id;
    Node(int l=0,int r=0,int id=0) : l(l),r(r),id(id) {}

    inline bool operator < (const Node &t) const {
        return l < t.l;
    }
}a[MAXN];
int ans[MAXN];

int main(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d%d",x+i,r+i),a[i] = Node(x[i]-r[i],x[i]+r[i],i);
    FOR(i,1,n) ans[i] = -1;
    std::sort(a+1,a+n+1);
    int m;scanf("%d",&m);
    FOR(i,1,m){
        int x,y;scanf("%d%d",&x,&y);
        int p = std::lower_bound(a+1,a+n+1,Node(x,y,-1))-a;
        FOR(j,std::max(1,p-5),std::min(n,p+5)){
            int r = (a[j].r-a[j].l)/2,d = (a[j].l+a[j].r)/2;
            if(1ll*(x-d)*(x-d)+1ll*y*y <= 1ll*r*r){
                if(ans[a[j].id] == -1) ans[a[j].id] = i;
            }
        }
    }
    int sm = 0;FOR(i,1,n) sm += (ans[i]!= -1);
    printf("%d\n",sm);
    FOR(i,1,n) printf("%d%c",ans[i]," \n"[i==n]);
    return 0;
}