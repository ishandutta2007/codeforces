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
/*
ll exgcd(ll a, ll b, ll &x, ll &y) {
    if(b==0) {
        x=1;y=0;
        return a;
    }
    ll r = exgcd(b,a%b,y,x);
    y-=(a/b)*x;
    return r;
}
*/
int a[10000];
/*
ll solve(ll a, ll b, ll c) {
    if(a>b) swap(a,b);
    ll x, y;
    ll g = exgcd(a,b,x,y);
    
    if(c%g==0) {
        c/=g;
        x*=c; y*=c;
        a/=g; b/=g;
        ll t = (x%b+b)%b;
        y -= ((t-x)/b)*a;
        return y<0?INF:(t+y);
    }else return INF;
}
*/
int main()
{
    ios::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    REP(i,n){
        cin>>a[i];
    }
    sort(a,a+n);
    int q;
    cin>>q;
    while(q--) {
        ll x;
        cin>>x;
        int ans = INF;
        REP(t,n)
        REP(i,k+1) {
            REP2(j,1,k-i) {
                ll y=x-a[t]*i;
                if(y%j==0) {
                    auto it = lower_bound(a,a+n,y/j);
                    if(it!=a+n && *it==y/j) {
                        ans = min(ans, i+j);
                    }
                }
            }
        }
        /*
        REP(i,n) {
            REP(j,i+1) {
                ans = min(ans, solve(a[i], a[j], x));
            }
        }
        */
        cout<<(ans>k?-1:ans)<<endl;
    }
    return 0;
}