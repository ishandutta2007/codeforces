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
#include <deque>
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
void print(vec v){for(auto e:v)cout<<e<<" ";cout<<endl;}
void print(vecll v){for(auto e:v)cout<<e<<" ";cout<<endl;}
void print(map<int,int> mp){for(auto e:mp)cout<<e.first<<" "<<e.second<<endl;cout<<endl;}


#define INF 1e9+7
#define LLINF 1e18+7

ll MOD=998244353;
const int N=160000;

template <ll Modulus> class modint {
  using u64 = ll;

public:
  u64 a;

  constexpr modint(const u64 x = 0) noexcept : a((x%Modulus+Modulus) % Modulus) {}
  constexpr u64 &value() noexcept { return a; }
  constexpr const u64 &value() const noexcept { return a; }
  constexpr modint operator+(const modint rhs) const noexcept {
    return modint(*this) += rhs;
  }
  constexpr modint operator-(const modint rhs) const noexcept {
    return modint(*this) -= rhs;
  }
  constexpr modint operator*(const modint rhs) const noexcept {
    return modint(*this) *= rhs;
  }
  constexpr modint operator/(const modint rhs) const noexcept {
    return modint(*this) /= rhs;
  }
  constexpr modint &operator+=(const modint rhs) noexcept {
    a += rhs.a;
    if (a >= Modulus) {
      a -= Modulus;
    }
    return *this;
  }
  constexpr modint &operator-=(const modint rhs) noexcept {
    if (a < rhs.a) {
      a += Modulus;
    }
    a -= rhs.a;
    return *this;
  }
  constexpr modint &operator*=(const modint rhs) noexcept {
    a = a * rhs.a % Modulus;
    return *this;
  }
  constexpr modint &operator/=(modint rhs) noexcept {
    u64 exp = Modulus - 2;
    while (exp) {
      if (exp % 2) {
        *this *= rhs;
      }
      rhs *= rhs;
      exp /= 2;
    }
    return *this;
  }
};

#define mint modint<998244353>
mint inv[N],comb[N],prd[N],invprd[N];
void calc_inv(){
    inv[1]=1;
    rep2(i,2,N-1){
        inv[i]=inv[MOD%i]*(-MOD/i);
    }
    return;
}
void calc_product(){
    prd[0]=prd[1]=1;
    invprd[0]=invprd[1]=1;
    rep2(i,2,N-1){
        prd[i]=prd[i-1]*i;
        invprd[i]=inv[i]*invprd[i-1];
    }
    return ;
}
void calc_mod(){calc_inv(),calc_product();}
mint cmb(int a,int b){
    if(a<b)return 0;
    if(a<0||b<0)return 0;
    return {prd[a]*invprd[b]*invprd[a-b]};
}
mint modpow(mint x,ll n){
    if(n==0) return 1;
    mint res=modpow(x*x,n/2);
    if(n&1) res=res*x;
    return res;
}

vector<vec> G;
vector<mint> subtree;
mint calc_sub(int x,int p){
    mint res=1;
    for(auto e:G[x]){
        if(e!=p)
        res+=calc_sub(e,x);
    }
    return subtree[x]=res; 
}
struct querry{
    int l,r;
    mint p;
};
int n;
vector<vector<querry>> mem;
vec ls,rs;
void dfs(int x,int p,int &idx){
    ls[x]=idx++;
    vecpii visit;
    for(auto e:G[x]){
        if(e!=p) visit.pb({subtree[e].a,e});
    }
    sort(all(visit));
    for(auto e:visit){
        dfs(e.second,x,idx);
    }
    int now=0,start=0;
    now=subtree[x].a;
    mem[x].pb(querry{0,ls[x],inv[n]*(now)});
    mem[x].pb(querry{ls[x],ls[x]+1,(mint)1});
    rep(i,visit.size()){
        now=visit[i].first,start=ls[visit[i].second];
        while(i<visit.size()-1&&visit[i+1].first==now)i++;
        mem[x].pb(querry{start,rs[visit[i].second],inv[n]*(n-now)});
    }
    rs[x]=idx;
    now=subtree[x].a;
    mem[x].pb(querry{rs[x],n,inv[n]*(now)});
    reverse(all(mem[x]));
    return;
}
template<typename T>
struct BIT{
    vector<T> data;

    BIT(int size){
        data.assign(++size,0);
    }
    T sum(int k){
        T ret=0;
        for(++k;k>0;k-=k&-k) ret+=data[k];
        return (ret);
    }
    void add(int k,T x){
        for(++k;k<data.size();k+=k&-k)data[k]+=x;
    }
};
BIT<mint> bit0(N),bit1(N);
main(){
    clock_t start=clock();
    calc_mod();
    mem.resize(n+1);
    int q;cin>>n>>q;
    G.resize(n+1);
    mem.resize(n+1);
    ls.resize(n+1),rs.resize(n+1);
    subtree.resize(n+1);
    rep(i,n-1){
        int a=in(),b=in();
        G[a].pb(b);G[b].pb(a);
    }
    calc_sub(1,0);
    int idx=0;
    dfs(1,0,idx);
    map<int,mint> todo;
    rep(iii,q){
        int t=in();
        if(t==1){
            int v=in();
            mint d=in();
            todo[v]+=d;
        }
        else{
            for(auto c:todo){
                for(auto q:mem[c.first]){
                    mint x=q.p*c.second;
                    bit0.add(q.l,x*(1-q.l));
                    bit1.add(q.l,x);
                    bit0.add(q.r,x*(q.r-1));
                    bit1.add(q.r,x*-1);
                }
            }
            todo=map<int,mint>();
            int x=ls[in()];
            mint res=bit1.sum(x)*x-bit1.sum(x-1)*(x-1)+bit0.sum(x)-bit0.sum(x-1);
            printf("%d\n",res.a);
        }
    }
}