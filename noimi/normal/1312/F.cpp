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


    
void go();




main(){
    ios
    // int Testcases=1;
    int Testcases=in();
    while(Testcases--){
        go();
    }
    return 0;
}


int g[3000][2][2];
int calc(ll x,int a,int b){
    if(x<0)x=0;
    if(x<3000)return g[x][a][b];
    x=(x-400)%2520+400;
    return g[x][a][b];
}
void go(){
    int n=in(),x=in(),y=in(),z=in();
    g[0][0][0]=g[0][0][1]=g[0][1][0]=g[0][1][1]=0;
    rep2(i,1,2999){
        rep(j,2){
            rep(k,2){
                set<int> s;
                s.insert(g[max(0ll,i-x)][1][1]);
                if(j)s.insert(g[max(0ll,i-y)][0][1]);
                if(k)s.insert(g[max(0ll,i-z)][1][0]);
                int now=0;
                for(auto e:s){
                    if(e==now)now++;
                    else break;
                }
                g[i][j][k]=now;
            }
        }
    }
    int X=0;
    vecll a;
    rep(i,n){
        a.pb(lin());
        X^=calc(a.back(),1,1);
    }
    // if(X==0){
    //     cout<<0<<endl;
    //     return ;
    // }
    // rep(i,100){
    //     rep(j,2)rep(k,2)cout<<g[i][j][k]<<" ";
    //     cout<<endl;
    // }
    int ans=0;
    rep(i,n){
        ll t=a[i];
        if(calc(t-x,1,1)==(X^calc(t,1,1)))ans++;
        if(calc(t-y,0,1)==(X^calc(t,1,1)))ans++;
        if(calc(t-z,1,0)==(X^calc(t,1,1)))ans++;
    }
    cout<<ans<<endl;
}