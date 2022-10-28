#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds;

#define INF 1000000009

typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<ll> > vvi;
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
inline void add(ll &a, ll b){a+=b;if(a>=INF)a-=INF;}
#define mid ((l+r)>>1)

vvi operator*(const vvi&x, const vvi&y){
  vvi ans={{0,0},{0,0}};
  ans[0][0]=(x[0][0]*y[0][0]+x[0][1]*y[1][0])%INF;
  ans[0][1]=(x[0][0]*y[0][1]+x[0][1]*y[1][1])%INF;
  ans[1][1]=(x[1][0]*y[0][1]+x[1][1]*y[1][1])%INF;
  ans[1][0]=(x[1][0]*y[0][0]+x[1][1]*y[1][0])%INF;
  return ans;
}
vvi operator+(const vvi&x, const vvi&y){
  vvi ans=x;
  add(ans[0][0],y[0][0]);
  add(ans[0][1],y[0][1]);
  add(ans[1][1],y[1][1]);
  add(ans[1][0],y[1][0]);
  return ans;
}


const int N = 3e5+10;
vvi M[N],CM[N];
vvi FIB = {{1,1},{1,0}};
struct node{
  ll F,S;
  ll sum;
  node():F(0),S(0),sum(0){}
};
int a[N];
node T[N<<2];
void build(int no,int l,int r){
  if(l==r) return void(T[no].sum=a[l]);
  build(no<<1,l,mid);
  build(no<<1|1,mid+1,r);
  T[no].sum=T[no<<1].sum;
  add(T[no].sum,T[no<<1|1].sum);
}
inline void LAZY(int no,int l,int r){
  if(T[no].F==0 and T[no].S==0)return;
  if(l==r){
    add(T[no].sum,T[no].F);
    T[no].F=T[no].S=0;
    return;
  }
  const vvi &now = CM[r-l+1-2];
  add(T[no].sum,T[no].F);
  add(T[no].sum,(T[no].S*now[0][0]+T[no].F*now[1][0])%INF);

    add(T[no<<1].F,T[no].F), add(T[no<<1].S,T[no].S),
    add(T[no<<1|1].F,(T[no].S*M[mid-l][0][0]+T[no].F*M[mid-l][1][0])%INF), 
    add(T[no<<1|1].S,(T[no].S*M[mid-l+1][0][0]+T[no].F*M[mid-l+1][1][0])%INF), 

  T[no].F=T[no].S=0;
}
void upd(int no,int l,int r,int u,int v){
  LAZY(no,l,r);
  if(r<u or l>v)return;
  if(l>=u and r<=v){
    if(l==u)add(T[no].F,1);else add(T[no].F,M[l-u+1-2][0][0]),add(T[no].F,M[l-u+1-2][1][0]);
    if(l<r)if(l<v)add(T[no].S,M[l-u+1-1][0][0]),add(T[no].S,M[l-u+1-1][1][0]);
    LAZY(no,l,r);
    return;
  }
  upd(no<<1,l,mid,u,v);upd(no<<1|1,mid+1,r,u,v);
  T[no].sum=T[no<<1].sum;
  add(T[no].sum,T[no<<1|1].sum);
}
ll qry(int no,int l,int r,int u,int v){
  LAZY(no,l,r);
  if(r<u or l>v)return 0;
  if(l>=u and r<=v)return T[no].sum;
  ll ans=qry(no<<1,l,mid,u,v);
  add(ans,qry(no<<1|1,mid+1,r,u,v));
  return ans;
}
int main()
{
  boost;
  M[0]={{1,0},{0,1}};
  CM[0]=M[0];
  FOR(i,1,N-1){
    M[i]=M[i-1]*FIB;
    CM[i]=CM[i-1]+M[i];
  }
  int n,m;cin>>n>>m;
  FOR(i,1,n)cin>>a[i];
  build(1,1,n);
  while(m--){
    int x,y,z;cin>>x>>y>>z;
    if(x==1)upd(1,1,n,y,z);
    else cout<<qry(1,1,n,y,z)<<"\n";
  }
  return 0;
}