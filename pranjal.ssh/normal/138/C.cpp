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


#define TRACE

#ifdef TRACE
template<class T, class U>
ostream& operator<<(ostream& out, const pair<T,U>& a){out<<"["<<a.first<<" "<<a.second<<"]";return out;}
template<class T>
ostream& operator<<(ostream& out, const vector<T>& a){for(auto &it:a)out<<it<<" ";return out;}
template<class T>
ostream& operator<<(ostream& out, const set<T>& a){for(auto &it:a)out<<it<<" ";return out;}
template<class T>
ostream& operator<<(ostream& out, const multiset<T>& a){for(auto &it:a)out<<it<<" ";return out;}
template<class T,class U>
ostream& operator<<(ostream& out, const map<T,U>& a){for(auto &it:a)out<<it.first<<" -> "<<it.second<<" | ";return out;}
template<class T,class U>
ostream& operator<<(ostream& out, const multimap<T,U>& a){for(auto &it:a)out<<it.first<<" -> "<<it.second<<" | ";return out;}
#define pra(a,n) cerr<<#a<<" : ";for(int i=0;i<n;++i)cerr<<a[i]<<" ";cerr<<endl;
#define praa(a,n,m) cerr<<#a<<" : "<<endl;for(int i=0;i<n;++i){for(int j=0;j<m;++j)cerr<<a[i][j]<<" ";cerr<<endl;}
#define pr(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
  cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
  const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
} 
#else
#define trace(...)
#define pra(a,n)
#define praa(a,n,m)
#endif


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
#define ass(n,l,r) assert(n>=l and n<=r)
inline int add(int a,int b, int m=INF){a+=b;if(a>=m)a-=m;return a;}
inline int mul(int a,int b, int m=INF){return (int)(((ll)a*(ll)b)%m);}


template <typename _node>
struct ST{
  #define mid ((l+r)>>1)
  int n;
  vector<_node> T;
  ST(int n):n(n),T(4*n+10){}

  inline void LAZY(int no,int l,int r){
    if(T[no].lazy == 1)return;
    T[no].P *= T[no].lazy;
    if(l!=r){
     T[no<<1].lazy *=  T[no].lazy ; 
     T[no<<1|1].lazy *= T[no].lazy ; 
    }
    T[no].lazy = 1;
  }
  _node qry(int no,int l,int r,int u,int v){
    LAZY(no,l,r);
    if(l>=u and r<=v)return T[no];
    if(v<=mid) {if(l!=r)LAZY(no<<1|1,mid+1,r);return qry(no<<1,l,mid,u,v);}
    else if(u>=mid+1) {if(l!=r)LAZY(no<<1,l,mid);return qry(no<<1|1,mid+1,r,u,v);}
    return _node::merge(qry(no<<1,l,mid,u,v),qry(no<<1|1,mid+1,r,u,v));
  }

  void updr(int no,int l,int r,int u,int v,double val){
    LAZY(no,l,r);
    if(l>=u and r<=v) {T[no].lazy = val ;LAZY(no,l,r);return;}
    if(r<u or l>v) return;
    updr(no<<1,l,mid,u,v,val),updr(no<<1|1,mid+1,r,u,v,val);
    T[no] = _node::merge(T[no<<1],T[no<<1|1]);
  }
};

struct node{
  double P,lazy;
  node():P(1),lazy(1){}
  static node merge(const node&x, const node&y){
    node ans;
    ans.P = x.P * y.P;
    return ans;
  }
};



int main()
{
  boost;
  int n,m;cin>>n>>m;
  vector<pair<ii,ii>> tree(n);
  vi aph;
  FOR(i,0,n-1)
    cin>>tree[i].F.F>>tree[i].F.S>>tree[i].S.F>>tree[i].S.S,
    aph.pb(tree[i].F.F - 1),
    aph.pb(tree[i].F.F + 1),
    aph.pb(tree[i].F.F),
    aph.pb(tree[i].F.F + tree[i].F.S),
    aph.pb(tree[i].F.F - tree[i].F.S);

  vii mush(m);
  FOR(i,0,m-1)cin>>mush[i].F>>mush[i].S,aph.pb(mush[i].F);

  sort(all(tree));sort(all(aph));aph.erase(unique(all(aph)),aph.end());

  int j = 0,k = 0;
  int mx = -INF;
  ST<node> TL(sz(aph));
  ST<node> TR(sz(aph));
  double hundred = 100;

  FOR(i,0,n-1){
    int pp, pa, pl, pr;
    pp = lower_bound(all(aph),tree[i].F.F - 1) - aph.begin() + 1;
    pa = lower_bound(all(aph),tree[i].F.F + 1) - aph.begin() + 1;
    pl = lower_bound(all(aph),tree[i].F.F - tree[i].F.S) - aph.begin() + 1;
    pr = lower_bound(all(aph),tree[i].F.F + tree[i].F.S) - aph.begin() + 1;

    TR.updr(1,1,sz(aph),pa,pr,1-tree[i].S.S/hundred);
    TL.updr(1,1,sz(aph),pl,pp,1-tree[i].S.F/hundred);
  }
  double ans = 0;
  FOR(i,0,m-1){
    int pos = lower_bound(all(aph),mush[i].F) - aph.begin() + 1;
    ans += mush[i].S * TR.qry(1,1,sz(aph),pos,pos).P * TL.qry(1,1,sz(aph),pos,pos).P;
  }
  cout<<fixed<<setprecision(10)<<ans<<"\n";

  return 0;
}