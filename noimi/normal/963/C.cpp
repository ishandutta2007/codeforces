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
#define INF 100000000
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


struct query{
    ll a,b,c;
};
ll gcd(ll x,ll y){
    return (y ? gcd(y,x%y):x);
}
ll lcm(ll x,ll y){
    return x/gcd(x,y)*y;
}
void go(){
    int n=in();
    vector<query> v;
    int cntx=0,cnty=0;
    map<ll,int> x,y;
    rep(i,n){
        ll a=lin(),b=lin(),c=lin();
        v.pb(query{a,b,c});
        if(!x.count(a))x[a]=cntx++;
        if(!y.count(b))y[b]=cnty++;
    }
    if((ll)x.size()*(ll)y.size() != n){
        cout<<0<<endl;return ;
    }
    vector<vecll> mp(x.size()+10,vecll(y.size()+10));
    for(auto q:v){
        mp[x[q.a]][y[q.b]]=q.c;
    }
    int m;
    n=x.size(),m=y.size();
    rep(i,n-1){
        rep(j,m-1){
            ll A=mp[i][j],B=mp[i+1][j],C=mp[i][j+1],D=mp[i+1][j+1];
            ll g1=gcd(A,B),g2=gcd(C,D);
            A/=g1,B/=g1;
            C/=g2,D/=g2;
            bool f=((A==C)&&(B==D));
            if(!f){
                cout<<0<<endl;return;
            }
        }
    }
    ll g=0;
    rep(i,n){
        g=gcd(g,mp[i][0]);
    }
    ll T=mp[0][0];
    ll l=1;
    rep(j,m){
        ll S=mp[0][j];
        ll G=gcd(T,S);
        l=lcm(l,T/G);
    }
    ll ans=0;
    // cout<<g<<" "<<l<<endl;
    for(ll i=1;i*i<=T;i++){
        if(T%i==0){
            if(g%i==0 and i%l==0)ans++;
            if(i*i!=T and g%(T/i)==0 and (T/i)%l==0)ans++;
        }
    }
    cout<<ans<<endl;

}