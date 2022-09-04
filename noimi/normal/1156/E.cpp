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
#define N 310000
ll MOD=1e9+7;
template< typename Monoid >
struct SegmentTree {
  using F = function< Monoid(Monoid, Monoid) >;
 
  int sz;
  vector< Monoid > seg;
 
  const F f;
  const Monoid M1;
 
  SegmentTree(int n, const F f, const Monoid &M1) : f(f), M1(M1) {
    sz = 1;
    while(sz < n) sz <<= 1;
    seg.assign(2 * sz, M1);
  }
 
  void set(int k, const Monoid &x) {
    seg[k + sz] = x;
  }
 
  void build() {
    for(int k = sz - 1; k > 0; k--) {
      seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
    }
  }
 
  void update(int k, const Monoid &x) {
    k += sz;
    seg[k] = x;
    while(k >>= 1) {
      seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
    }
  }
 
  Monoid query(int a, int b) {
    Monoid L = M1, R = M1;
    for(a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
      if(a & 1) L = f(L, seg[a++]);
      if(b & 1) R = f(seg[--b], R);
    }
    return f(L, R);
  }
 
  Monoid operator[](const int &k) const {
    return seg[k + sz];
  }
};
//SegmentTree(n,f,M1) nfM1
//set(k,x) k = x
//build() 
//query [a,b)
//update(k,x) kx
//operator[k] k
// SegmentTree< int > seg(N,[](int a,int b){return min(a,b);},INF);
//

    int n;
    int p[N],pos[N];
    main(){
        n=in();
            SegmentTree<int> seg(n+1,[](int a,int b){return a+b;},0);
        rep(i,n){
        p[i]=in();
        pos[p[i]]=i;
    }
    ll ans=0;
    rep3(i,n,1){
        int s=pos[i];
        bool f;
        rep(j,n){
            if(s-j<0||p[s-j]>i){
                f=true;break;
            }
            if(s+j>=n||p[s+j]>i){
                f=false;break;
            }
        }
        if(f){
            int t=s-1;
            while(t>=0&&p[t]<i){
                if(pos[i-p[t]]>s&&!seg.query(s,pos[i-p[t]]+1))ans++;
                t--;
            }
        }
        else{
            int t=s+1;
            while(t<n&&p[t]<i){
                if(pos[i-p[t]]<s&&!seg.query(pos[i-p[t]],s))ans++;t++;
            }
        }
        seg.update(s,1);
    }
    cout<<ans;
}