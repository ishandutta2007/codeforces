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

int r[11000000];
main(){
    int n=in();
    vec a;rep(i,n)a.pb(in());
    // int aa=0;
    // rep(i,n){
    //     rep2(j,i+1,n-1){
    //         aa^=(a[i]+a[j]);
    //     }
    // }
    // cout<<aa<<" ";
    int ans=0;
    rep(i,26){
        int t=1<<(i+1);
        vecpii b;
        rep(i,n)b.eb(a[i]%t,i);
        sort(all(b));
        int tmp=0;
        for(auto ee:b){
            int e=ee.first;
            int l=max(0,(1<<i)-e);
            int r=min(e,t-e-1);
            if(r<l)continue;
            int L=0,R=INT_MAX;
            if(r==e)R=ee.second;

            tmp^=( lb(b,make_pair(r,R)) - lb(b,make_pair(l,L)) )%2 ;
            l=(1<<i)+t-e;
            r=e;
            R=ee.second;
            if(l<=r)
            tmp^=( lb(b,make_pair(r,R)) - lb(b,make_pair(l,L)) )%2 ;
        }

        // cout<<tmp<<endl;
        ans+=tmp*(t/2);
    }
    cout<<ans<<endl;
            
}