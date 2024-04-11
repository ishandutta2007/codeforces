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
#define vec2ll(a,b) vector<vec>(a,vecll(b))
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

const ll MOD=998244353;
const int N=1100000;
 
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

vector<vec> mp=vector<vec>(510000);
main(){
    // ios
    int m=in(),k=in(),n=in(),s=in();
    int rem=m-n*k;
    vec a;
    rep(i,m)a.pb(in());
    map<int,int> b;
    rep(i,s){int x=in();b[x]+=1;}
    rep(i,m){
        if(b[a[i]]){
            mp[a[i]].pb(i);
        }
    }
    set<pii> se;
    vec next(m+1,INT_MAX);
    vec pre(m+1,INT_MAX);
    for(auto e:b){
        int c=e.second;
        int now=e.first;
        if(!e.second)continue;
        if(mp[now].size()<c){
            cout<<-1<<endl;return 0;
        }
        int pre_ = mp[now][c-1];
        rep(i,mp[now].size()){
            pre[mp[now][i]]=pre_;
            if(i+c==mp[now].size()){
                next[mp[now][i]]=INT_MAX;break;
            }
            next[mp[now][i]]=mp[now][i+c];
            pre_=mp[now][i+c];
        }
        se.emplace(mp[now][c-1],now);
    }
    rep(i,m){
        auto it=se.end();
        it--;
        int ne=(*it).first;
        int res=i%k + max(0,ne-(int)i+1-k);
        if(res<=rem){
            cout<<rem<<endl;
            rep(j,i%k) {rem--;cout<<j+1<<" ";}
            rep2(j,i,ne){
                if(!b[a[j]]&&rem){rem--;cout<<j+1<<" ";}
                else b[a[j]]--;
            }
            rep3(j,m-1,0){if(rem){cout<<j+1<<" ";rem--;}}
            cout<<endl;
            return 0;
        }
        if(pre[i]!=INT_MAX){
            // cout<<i<<endl<<" "<<a[i]<<" "<<pre[i]<<endl;
            it=se.find({pre[i],a[i]});
            se.erase(it);
            se.insert({next[i],a[i]});
        }
    }
    cout<<-1<<endl;

}