#include <bits/stdc++.h>

#define fi first
#define se second
#define DB double
#define U unsigned
#define P std::pair
#define LL long long
#define LD long double
#define pb push_back
#define MP std::make_pair
#define SZ(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 4e5 + 5;
int n;
std::vector<int> S;
struct Node{
    int l,r,id;
    Node(int l=0,int r=0,int id=0) : l(l),r(r),id(id) {}
}a[MAXN];

struct BIT{
    #define lowbit(x) ((x)&(-(x)))
    int tree[MAXN];

    inline void add(int pos,int x){
        for(;pos<MAXN;pos+=lowbit(pos)) tree[pos] += x;
    }

    inline int query(int pos){
        int res = 0;
        for(;pos;pos-=lowbit(pos)) res += tree[pos];
        return res;
    }
}bit;

int ans[MAXN];

int main(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d%d",&a[i].l,&a[i].r),S.pb(a[i].l),a[i].id = i;
    std::sort(all(S));S.erase(std::unique(all(S)),S.end());
    FOR(i,1,n) a[i].l = std::lower_bound(all(S),a[i].l)-S.begin()+1;
    std::sort(a+1,a+n+1,[&](const Node &a,const Node &b){return a.r < b.r;});
    FOR(i,1,n){
        ans[a[i].id] = i-1-bit.query(a[i].l-1);
        bit.add(a[i].l,1);
    }
    FOR(i,1,n) printf("%d\n",ans[i]);
    return 0;
}