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
#define INF INT_MAX
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

vector<vecpii> g;
void go(){
    ll a=lin(),b=lin();
    if(a>b){
        cout<<-1<<endl;return;
    }
    if(a==b){
        if(a==0)cout<<0<<endl;
        else cout<<1<<endl<<a<<endl;
        return;
    }
    if((a&1)^(b&1)){
        cout<<-1<<endl;return;
    }
    ll t=a+b;
    ll c=b-a;
    c/=2;
    ll x=0,y=0;
    rep(i,62){
        ll m=1ll<<(ll)i;
        // cout<<m<<endl;
        if(m&c){
            if(a&m){
                if((a&1)^(b&1)){
                cout<<-1<<endl;return;
                }
                else{
                    cout<<3<<endl;
                    cout<<a<<" "<<(b-a)/2<<" "<<(b-a)/2<<endl;
                    return;
                }
            }
            else{
                x+=m;
                y+=m;
            }
        }
        else{
            if(a&m){
                x+=m;
            }
        }
    }
    cout<<2<<endl;
    cout<<x<<" "<<y<<endl;

}