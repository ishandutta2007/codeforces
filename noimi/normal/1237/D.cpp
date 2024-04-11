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
#include <fstream>
#define ll long long
#define rep2(i,a,b) for(ll i=a;i<=b;++i)
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep3(i,a,b) for(ll i=a;i>=b;i--)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pq priority_queue<int>
#define pqg priority_queue<int,vector<int>,greater<int>>
#define pb push_back
#define vec vector<int>
#define vecll vector<ll>
#define vecpii vector<pii>
#define endl "\n"
#define all(c) begin(c),end(c)
using namespace std;
int in() {int x;scanf("%d",&x);return x;}
ll lin() {ll x;scanf("%lld",&x);return x;}

#define INF 1e9+7
#define LLINF 1e18+7
#define N 250000
ll MOD=998244353;

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



main(){
    int n=in();
    SegmentTree<int> seg(n*4+2,[](int a,int b){return min(a,b);},INF);
    vector<pii> mem;
    vec v;
    int MIN=INF,MAX=0;
    rep(i,n){
        int a=in();
        MIN=min(MIN,a);
        MAX=max(MAX,a);
        seg.set(i,a);
        seg.set(i+n,a);
        seg.set(i+n+n,a);
        seg.set(i+n+n+n,a);
        mem.pb({a,i});
    }
    if(MIN>=(MAX+1)/2){
        rep(i,n)cout<<-1<<" ";
        return 0;
    }
    seg.build();
    set<int> S;
    sort(all(mem),greater<pii>());
    vec ans(n+1);
    rep(i,n){
        int a=mem[i].first;
        int x=mem[i].second;
        int next;
        if(i==0) next=3*n;
        else{
            int tmp=*(S.lower_bound(x));
            next=ans[tmp%n]+tmp;
            if(next<x)next+=n;
        }
        int l=x,r=next;
        while(l<r-1){
            int mid=(l+r)/2;
            (seg.query(l,mid+1)<(a+1)/2 ? r : l) = mid;
        }
        ans[x]=r-x;
        S.insert(x);
        S.insert(x+n);
    }
    rep(i,n){
        cout<<ans[i]<<" ";
    }
}