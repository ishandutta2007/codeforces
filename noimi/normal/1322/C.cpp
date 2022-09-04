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


unsigned xorshift()
{
    static unsigned x=123456789, y=362436069, z=521288629, w=8867512;
    unsigned t=(x^(x<<11));
    x=y; y=z; z=w;
    return w=(w^(w>>19))^(t^(t>>8));
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int n){
    return uniform_int_distribution<int>(0, INT_MAX)(rng)%n;
}
double drnd(){
    return (double)(rnd(INT_MAX))/INT_MAX;
}
void shuffle(vec &x){
    int n=x.size();
    rep3(i,n-1,1){
        swap(x[i],x[rnd(i-1)]);
    }
}
clock_t start;
double time(){
    return (double)(clock()-start)/CLOCKS_PER_SEC;
}
ll M[4]={1000000000000037,9007199254740997,92709568269121 ,999999999999937};

ll rh[4][510000];

ll gcd(ll x,ll y){
    if(y==0)return x;
    return gcd(y,x%y);
}
main(){
    ios
    int T=in();
    while(T--){
        int n=in(),m=in();
        vecll a;
        rep(i,n)a.pb(lin());
        vecll p[4];
        ll k[4];
        rep(i,4)k[i]=rnd(1000)+2;
        ll t[4]={1,1,1,1};
        rep(i,n+1){
            rep(j,4)p[j].pb(t[j]);
            rep(j,4)t[j]=t[j]*k[j]%M[j];
        }
        rep(i,4)rep(j,n+1)rh[i][j]=0;
        rep(i,m){
            int x=in(),y=in();
            rep(j,4){
                rh[j][y]=(rh[j][y]+p[j][x])%M[j];
            }
        }
        map<vecll,ll> mp;
        rep2(i,1,n){
            vecll v;
            rep(j,4) v.eb(rh[j][i]);
            bool flag=0;
            for(auto e:v)if(e)flag=1;
            if(!flag)continue;
            mp[v]+=a[i-1];
        }
        ll g=0;
        for(auto e:mp){
            g=gcd(g,e.second);
        }
        cout<<g<<endl;
    }
    
            
}