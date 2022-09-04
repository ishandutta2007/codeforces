// #pragma GCC optimize("O3")
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

long double eps=1e-8;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int n){
    return uniform_int_distribution<int>(0, n)(rng);
}
double drnd(){
    return (double)(rnd(INT_MAX))/INT_MAX;
}
const ll MOD=1e9+7;
const int N=2100000;


main(){
    int t=in();
    while(t--){
        int n=in();
        vec a;
        rep(i,n)a.pb(in());
        int mi=INT_MAX,ma=0;
        rep2(i,1,n-2){
            if(a[i+1]==-1 or a[i-1]==-1){
                if(a[i]!=-1){
                mi=min(mi,a[i]);
                ma=max(ma,a[i]);
                }
            }
            if(a[i]==-1){
                if(a[i-1]!=-1){
                    mi=min(mi,a[i-1]),ma=max(ma,a[i-1]);
                }
                if(a[i+1]!=-1){
                    mi=min(mi,a[i+1]),ma=max(ma,a[i+1]);
                }
            }
        }
        int k=(mi+ma)/2;
        int ans=0;
        if(n==2){
            if(a[0]==-1 and a[1]==-1){
                cout<<"0 0\n";
            }
            else if(a[0]==-1){
                cout<<0<<" "<<a[1]<<endl;
            }
            else cout<<0<<" "<<a[0]<<endl;
            continue;
        }
        if(mi==INT_MAX)k=1;
        rep(i,n)if(a[i]==-1)a[i]=k;
        rep(i,n-1){
            ans=max(ans,abs(a[i+1]-a[i]));
        }
        if(mi!=INT_MAX)
        cout<<ans<<" "<<k<<endl;
        else{
            cout<<ans<<" "<<1<<endl;
        }
    }
}