#include <bits/stdc++.h>
#include <ext/hash_map>
#include <ext/hash_set>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
#define XINF INT_MAX
#define INF 0x3F3F3F3F
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X,N) for(int X=0;X<N;X++)
#define REP2(X,L,R) for(int X=L;X<=R;X++)
#define DEP(X,R,L) for(int X=R;X>=L;X--)
#define CLR(A,X) memset(A,X,sizeof(A))
#define IT iterator
#define RIT reverse_iterator
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;
typedef tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update > rb_tree_set;
typedef tree<int, int, greater<int>, rb_tree_tag, tree_order_statistics_node_update > rb_tree;
#define PQ std::priority_queue
#define HEAP __gnu_pbds::priority_queue
#define X first
#define Y second
#define lson(X) ((X)<<1)
#define rson(X) ((X)<<1|1)

int d[200000];
int h[200000];
ll s[200001];
ll ls[200001];
ll rs[200001];
ll a[1<<19];
ll b[1<<19];
ll c[1<<19];

int N;

void pushup(int t) {
    a[t]=max(a[lson(t)],a[rson(t)]);
    b[t]=max(b[lson(t)],b[rson(t)]);
    c[t]=max( max(c[lson(t)], c[rson(t)]), a[lson(t)]+b[rson(t)]);
}

void init(int n) {
    N=1;
    while(N<=n) N*=2;
    REP(i,N) {
        a[N+i]=rs[i];
        b[N+i]=ls[i];
        c[N+i]=0;
    }
    DEP(i,N-1,0) {
        pushup(i);
    }
}

tuple<ll,ll,ll> query(int t, int L, int R, int l, int r) {
    l=max(L,l);
    r=min(r,R);
    if(l>R||r<L) return make_tuple(0,0,0);
    if(l==L && r==R) return make_tuple(a[t],b[t],c[t]);
    int M=(L+R)>>1;
    tuple<ll,ll,ll> t1 = query(lson(t),L,M,l,r),
                    t2 = query(rson(t),M+1,R,l,r);
    ll A1=get<0>(t1);
    ll B1=get<1>(t1);
    ll C1=get<2>(t1);
    
    ll A2=get<0>(t2);
    ll B2=get<1>(t2);
    ll C2=get<2>(t2);
    
    ll A=max(A1,A2);
    ll B=max(B1,B2);
    ll C=max(max(C1,C2), A1+B2);
    return make_tuple(A,B,C);
}

int main()
{
    ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    REP(i,n) cin>>d[i];
    REP(i,n) cin>>h[i];
    REP(i,n) d[i+n]=d[i];
    REP(i,n) h[i+n]=h[i];
    REP(i,2*n) s[i+1]=s[i]+d[i];
    REP(i,2*n) {
        ls[i]=s[i]+h[i]*2;
        rs[i]=s[n*2]-s[i]+h[i]*2;
        //cout<<ls[i]<<' '<<rs[i]<<endl;
    }
    init(2*n);
    REP(i,m) {
        int a,b;
        cin>>a>>b; a--; b--;
        if(a<=b) a+=n;
        a--;b++;
        //cout<<a<<' '<<b<<endl;
        tuple<ll,ll,ll> p = query(1,0,N-1,b,a);
        cout<<get<2>(p)-s[n*2]<<endl;
    }
    return 0;
}