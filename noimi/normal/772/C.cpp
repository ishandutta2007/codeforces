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
// #define INF 100000000
using namespace std;
int in() {int x;cin>>x;return x;}
ll lin() {ll x;cin>>x;return x;}
string stin() {string s;cin>>s;return s;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
template<class T> inline void print(pair<T,T> p){cout<<"("<<p.first<<","<<p.second<<") ";}
template<class T> inline void print(vector<pair<T,T>> v){for(auto e:v)print(e); cout<<endl;}
template<class T> inline void print(T v){for(auto e:v)cout<<e<<" ";cout<<endl;}

#define double long double

int gcd(int x,int y){
    return (x?gcd(y%x,x) : y);
}
template< typename T >
T extgcd(T a, T b, T &x, T &y) {
  T d = a;
  if(b != 0) {
    d = extgcd(b, a % b, y, x);
    y -= (a / b) * x;
  } else {
    x = 1;
    y = 0;
  }
  return d;
}

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);cout<<fixed<<setprecision(15);
    int n=in(),m=in();
    vec mp(m+1);
    vector<set<int>> v(m+1);
    rep(i,m){
        mp[gcd(i,m)]++;
        v[gcd(i,m)].insert(i);
    }
    rep(i,n){
        int s=in();
        if(s)
        mp[gcd(s,m)]--;
        else mp[m]--;
        v[gcd(s,m)].erase(s);
    }
    vec p;
    int M=m;
    for(int i=2;i*i<=M;i++){
        while(M%i==0){
            M/=i;p.pb(i);
        }
    }
    if(M>1)p.pb(M);
    int ma=0;
    vec mem;
    do{
        int prod=1;
        int tmp=mp[1];
        for(auto e:p){
            prod*=e;
            tmp+=mp[prod];
        }
        if(chmax(ma,tmp))mem=p;
    }
    while(next_permutation(all(p)));
    cout<<ma<<endl;
    ll now = 1;
    int prod=1;
    int pl=0;
    do{
        for(auto &e:v[prod]){
            ll x,y;
            int g = extgcd(now,(ll)m,x,y);
            x = (x%m +m)%m;
            ll X = (ll)(x*(e/g))%m;
            cout << X <<" ";
            now = e;
        }
        if(pl==mem.size())break;
        prod*=mem[pl];
        pl++;
    }while(1);
    cout<<endl;
}