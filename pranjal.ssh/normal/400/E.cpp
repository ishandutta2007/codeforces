#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds;

#define INF 1000000007

typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int> > vvi;
typedef pair<int,int> ii;
typedef vector<pair<int,int> > vii;
typedef vector<vector<pair<int,int> > > vvii;

#define all(x) (x).begin(), (x).end()
#define nall(x) (x).rbegin(), (x).rend()
#define sz(a) int((a).size()) 
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define pb push_back
#define rz resize
#define MP make_pair
#define F first
#define S second
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define NFOR(i,a,b) for(int i=(a);i>=(b);--i)
#define TCASE int __T;cin>>__T;FOR(Tc,1,__T)
inline int add(int a,int b, int m=INF){a+=b;if(a>=m)a-=m;return a;}
inline int mul(int a,int b, int m=INF){return (int)(((ll)a*(ll)b)%m);}


template <typename _node>
struct ST{
  #define mid ((l+r)>>1)
  int n;
  vector<_node> T;
  ST(int n):n(n),T(4*n+10){}
  void upd(int no,int l,int r,int pos,int val){
    if(l==r) { T[no].L=T[no].R=T[no].ans=val; return;}
    if(pos<=mid) upd(no<<1,l,mid,pos,val);
    else upd(no<<1|1,mid+1,r,pos,val);
    T[no]=_node::merge(T[no<<1],T[no<<1|1],mid-l+1,r-mid);
  }
};

const int N = 1e5+10;
struct node{
  ll L,R,ans;
  node():L(0),R(0),ans(0){}
  static node merge(const node&x, const node& y,int nx,int ny){
    node ret;
    ret.L = nx==x.L?x.L+y.L:x.L;
    ret.R = ny==y.R?x.R+y.R:y.R;
    ret.ans = x.ans + y.ans - ((y.L*(y.L-1))>>1) - ((x.R*(x.R-1))>>1) + (((y.L+x.R)*(y.L+x.R-1))>>1);
    return ret;
  }
};
int a[N];
int main()
{
  boost;
  int n,m;cin>>n>>m;
  vector<ST<node>> T(20,n);
  FOR(i,1,n){
    int x;cin>>x;
    FOR(j,0,19){
      if(x&(1<<j))
      T[j].upd(1,1,n,i,1);
    }
  }
  while(m--){
    int p,v;cin>>p>>v;
    ll ans=0;
    FOR(i,0,19){
      T[i].upd(1,1,n,p,(v>>i)&1);
      ans+=T[i].T[1].ans*(1LL<<i);
    }
    cout<<ans<<"\n";
  }
  return 0;
}