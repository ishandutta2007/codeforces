#include <stdio.h>  
#include <algorithm>  
#include <assert.h>
#include <bitset>
#include <cmath>  
#include <complex>  
#include <deque>  
#include <functional>  
#include <iostream>  
#include <limits.h>  
#include <map>  
#include <math.h>  
#include <queue>  
#include <set>  
#include <stdlib.h>  
#include <string.h>  
#include <string>  
#include <time.h>  
#include <unordered_map>  
#include <unordered_set>  
#include <vector>  
#include <chrono>
#include <random>
#include <time.h>
#define ll long long
#define rep2(i,a,b) for(ll i=a;i<=b;++i)
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep3(i,a,b) for(ll i=a;i>=b;i--)
#define REP(e,v) for(auto e:v)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define tii tuple<int,int,int>
#define pq priority_queue<int>
#define pqg priority_queue<int,vector<int>,greater<int>>
#define pb push_back
#define edge(v,a,b) v[a].pb(b);v[b].pb(a);
#define MAX_V 400010
#define vec vector<int>
#define vecll vector<ll>
#define vecpii vector<pii>
#define endl "\n"
#define ALL(c) (c).begin(),(c).end()
using namespace std;
int in() {int x;scanf("%d",&x);return x;}
ll lin() {ll x;scanf("%lld",&x);return x;}

#define INF 1e9+7
#define LLINF 1e18+7
ll MOD=998244353;
#define N 110000

//
template< typename Monoid, typename OperatorMonoid = Monoid >
struct LazySegmentTree
{
  using F = function< Monoid(Monoid, Monoid) >;
  using G = function< Monoid(Monoid, OperatorMonoid) >;
  using H = function< OperatorMonoid(OperatorMonoid, OperatorMonoid) >;
  using P = function< OperatorMonoid(OperatorMonoid, int) >;

  int sz;
  vector< Monoid > data;
  vector< OperatorMonoid > lazy;
  const F f;
  const G g;
  const H h;
  const P p;
  const Monoid M1;
  const OperatorMonoid OM0;


  LazySegmentTree(int n, const F f, const G g, const H h, const P p,
                  const Monoid &M1, const OperatorMonoid OM0)
      : f(f), g(g), h(h), p(p), M1(M1), OM0(OM0)
  {
    sz = 1;
    while(sz < n) sz <<= 1;
    data.assign(2 * sz, M1);
    lazy.assign(2 * sz, OM0);
  }

  void set(int k, const Monoid &x)
  {
    data[k + sz] = x;
  }

  void build()
  {
    for(int k = sz - 1; k > 0; k--) {
      data[k] = f(data[2 * k + 0], data[2 * k + 1]);
    }
  }

  void propagate(int k, int len)
  {
    if(lazy[k] != OM0) {
      if(k < sz) {
        lazy[2 * k + 0] = h(lazy[2 * k + 0], lazy[k]);
        lazy[2 * k + 1] = h(lazy[2 * k + 1], lazy[k]);
      }
      data[k] = g(data[k], p(lazy[k], len));
      lazy[k] = OM0;
    }
  }

  Monoid update(int a, int b, const OperatorMonoid &x, int k, int l, int r)
  {
    propagate(k, r - l);
    if(r <= a || b <= l) {
      return data[k];
    } else if(a <= l && r <= b) {
      lazy[k] = h(lazy[k], x);
      propagate(k, r - l);
      return data[k];
    } else {
      return data[k] = f(update(a, b, x, 2 * k + 0, l, (l + r) >> 1),
                         update(a, b, x, 2 * k + 1, (l + r) >> 1, r));
    }
  }

  Monoid update(int a, int b, const OperatorMonoid &x)
  {
    return update(a, b, x, 1, 0, sz);
  }


  Monoid query(int a, int b, int k, int l, int r)
  {
    propagate(k, r - l);
    if(r <= a || b <= l) {
      return M1;
    } else if(a <= l && r <= b) {
      return data[k];
    } else {
      return f(query(a, b, 2 * k + 0, l, (l + r) >> 1),
               query(a, b, 2 * k + 1, (l + r) >> 1, r));
    }
  }

  Monoid query(int a, int b)
  {
    return query(a, b, 1, 0, sz);
  }

  Monoid operator[](const int &k)
  {
    return query(k, k + 1);
  }
};
auto f=[](ll a,ll b){return a+b;};
auto g=[](ll a,ll b){return a*b;};
auto h=[](ll a,ll b){return min(a,b);};
auto p=[](ll a,ll b){return a;};
//
//addmin
//LazySegmentTree<ll> seg(N*2+10,h,f,f,p,INF,0);
//add sum
LazySegmentTree<ll> seg(N*2+10,f,f,f,g,0,0);


//LazySegmentTree(n,f,g,h,p,M1,OM0) 
//n
//f
//g()
//h
//p(value,length)
//M1
//OM0
//update(a,b,x) [a,b) x 
//query(a,b) [a,b) 
main(){
    //LazySegmentTree<int> seg(N*2,[](int a,int b){return a+b;},0);
    int n=in(),q=in();
    int a[N];rep(i,n)a[i]=in();
    vector<pii> qr;
    rep(i,q){
        char c;cin>>c;
        int x=in();
        qr.pb({c=='<',x});
    }
    int suf[N];
    suf[q]=N+1;
    rep3(i,q-1,0){
        int s=qr[i].second;
        s=abs(s);
        if(!(qr[i].first^(qr[i].second<0)))s++;
        suf[i]=min(suf[i+1],s);
    }
    rep(i,q){
        if(suf[i+1]>abs(qr[i].second)){
            if(!(qr[i].first^(qr[i].second<0))){
                if(qr[i].first){
                seg.update(N-suf[i+1]+1,N-abs(qr[i].second),1);
                //cout<<N-suf[i+1]+1<<" "<<N-abs(qr[i].second)<<" 1"<<endl;
                }
                else{
                seg.update(N+abs(qr[i].second)+1,N+suf[i+1],1);
                //cout<<N+abs(qr[i].second)+1<<" "<<N+suf[i+1]<<" 1\n";
                }
            }
            else{
                if(!qr[i].first)
                {
                seg.update(N+abs(qr[i].second),N+suf[i+1],1);
                //cout<<N+abs(qr[i].second)<<" "<<N+suf[i+1]<<" 1\n";
                }
                else{
                seg.update(N-suf[i+1]+1,N-abs(qr[i].second)+1,1);
                //cout<<N-suf[i+1]+1<<" "<<N-abs(qr[i].second)<<endl;
                }
            }
        }
        if(qr[i].first^(qr[i].second<0)){
            if(i+1==q){
              seg.update(N-abs(qr[i].second)+1,N+abs(qr[i].second),1);
            }
            else
            seg.update(N-suf[i]+1,N+suf[i],1);
            //cout<<N-abs(qr[i].second)+1<<" "<<N+abs(qr[i].second)<<endl;
        }
        /*rep2(i,-5,5){
          cout<<seg[N+i]<<" ";
        }
        cout<<endl;
        */
    }
    rep(i,n){
        cout<<(seg[N+a[i]]%2?-a[i]:a[i])<<" ";
    }
    return 0;
}