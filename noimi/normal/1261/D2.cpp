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


const ll MOD=998244353;
const int N=500000;

template <ll Modulus> class modint {
  using u64 = ll;

public:
  u64 a;

  constexpr modint(const u64 x = 0) noexcept : a(((x % Modulus) + Modulus)%Modulus) {}
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

#define mint modint<MOD>
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
void calc(){calc_inv();calc_product();}

main(){
    calc();
    int n=in(),k=in();
    vec h;
    rep(i,n){
        h.pb(in());
    }
    h.pb(h[0]);
    mint ans=1;
    int N=n;
    rep(i,n){
        if(h[i]==h[i+1]){
            ans*=k;
            N--;
        }
    }
    mint Ans;
    n=N;
    rep(i,n){
        mint tmp=modpow(k-2,i)*cmb(n,i);
        if((n-i)%2){
            tmp*=modpow(2,n-i-1);
        }
        else{
            tmp*=(modpow(2,n-i)-cmb(n-i,(n-i)/2)+MOD)*inv[2];
        }
        // cout<<tmp.a<<endl;
        Ans+=tmp;
    }
    cout<<(ans*Ans).a<<endl;
}