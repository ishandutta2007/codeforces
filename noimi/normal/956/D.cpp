 #pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
#define rep2(i,a,b) for(ll i=a;i<=b;++i)
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep3(i,a,b) for(ll i=a;i>=b;i--)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pq priority_queue
#define pb push_back
#define eb emplace_back
#define vec vector<int>
#define vecll vector<ll>
#define vecpii vector<pii>
#define vec2(a,b) vector<vec>(a,vec(b))
#define vec2ll(a,b) vector<vecll>(a,vecll(b))
#define vec3(a,b,c) vector<vector<vec>>(a,vec2(b,c))
#define vec3ll(a,b,c) vector<vector<vecll>>(a,vec2ll(b,c))
#define fi first
#define se second
#define endl "\n"
#define all(c) begin(c),end(c)
#define ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(c,x) distance(c.begin(),lower_bound(all(c),x))
#define ub(c,x) distance(c.begin(),upper_bound(all(c),x))
#define MM " "
using namespace std;
int in() {int x;cin>>x;return x;}
ll lin() {ll x;cin>>x;return x;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
template<class T> inline void print(pair<T,T> p){cout<<"("<<p.first<<","<<p.second<<") ";}
template<class T> inline void print(vector<pair<T,T>> v){for(auto e:v)print(e); cout<<endl;}
template<class T> inline void print(T v){for(auto e:v)cout<<e<<" ";cout<<endl;}


    
void go();

main(){
    ios
    int tc=1;
    // tc=in();
    while(tc--){
        go();
    }
    return 0;
}
template< typename T >
struct BinaryIndexedTree {
  vector< T > data;

  BinaryIndexedTree(int sz) {
    data.assign(++sz, 0);
  }

  T sum(int k) {
    T ret = 0;
    for(++k; k > 0; k -= k & -k) ret += data[k];
    return (ret);
  }

  void add(int k, T x) {
    for(++k; k < data.size(); k += k & -k) data[k] += x;
  }
};
#define BIT BinaryIndexedTree

int w;
vecpii v;
bool comp1(int xx,int yy){
    pii x=v[xx],y=v[yy];
    int px=x.second-w,py=y.second-w;
    return (ll)py*x.fi < (ll)px*y.fi;
}
bool comp2(int xx,int yy){
    pii x=v[xx],y=v[yy];
    int px=x.second+w,py=y.second+w;
    return (ll)py*x.fi < (ll)px*y.fi;
}
long double eps=1e-6;
ll tentou(vector<long double> x,vector<long  double> y){
    vec idy;
    int n=x.size();
    rep(i,n){
        idy.pb(i);
    }
    sort(all(idy),[&](int aa,int bb){
        return y[aa]<y[bb];});
    vector<pair<long double,int>> v;
    rep(i,n){
        v.pb({x[i],0});
    }
    rep(i,n)v[idy[i]].se=i;
    sort(all(v));
    BIT<ll> bit(n);
    ll res=0;
    
    rep(i,n){
        res+=i-bit.sum(v[i].se);
        bit.add(v[i].se,1);
    }
    return res;
}
void go(){
    int n=in();w=in();
    vec idx,idy,id;
    vec revx(n),revy(n);
    rep(i,n)idx.pb(i),idy.pb(i),id.pb(i);
    rep(i,n){
        int a=in(),b=in();
        v.eb(a,b);
    }
    sort(all(idx),comp1);
    sort(all(idy),comp2);
    rep(i,n)revx[idx[i]]=i,revy[idy[i]]=i;
    ll ans=0;
    sort(all(id),[&](int x,int y){return v[x].fi<v[y].fi;});
    vector<long double> t,s;
    rep(ii,n){
        int i=id[ii];
        t.pb((long double)-v[i].fi/(long double)(v[i].se-w-eps));
        s.pb((long double)-v[i].fi/(long double)(v[i].se+w+eps));
    }
    ans+=tentou(t,s);
    cout<<ans<<endl;

}