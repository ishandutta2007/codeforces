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
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);cout<<fixed<<setprecision(15);
    int tc=1;
    // tc=in();
    while(tc--){
        go();
    }
    return 0;
}


int mp[2010][2010];
void go(){
    int n=in(),k=in();
    vector<string> s;
    rep(i,n){
        string t;cin>>t;
        s.pb(t);
    }
    string best;
    if(k){
        best="a";
        if(s[0][0]!='a')k--;
    }
    else best=s[0][0];
    rep(i,2010)rep(j,2010)mp[i][j]=-1;
    mp[0][0]=k;
    rep2(i,1,n*2-2){
        char now='z';
        rep(x,n){
            int y=i-x;
            if(y<0 or y>n-1)continue;
            if(x and mp[x-1][y]!=-1){
                if(mp[x-1][y]){
                    now='a';
                }
                else {
                    chmin(now,s[x][y]);
                }
            }
            if(y and mp[x][y-1]!=-1){
                if(mp[x][y-1]){
                    now='a';
                }
                else chmin(now,s[x][y]);
            }
        }
        rep(x,n){
            int y=i-x;
            if(y<0 or y>n-1)continue;
            if(x and mp[x-1][y]!=-1){
                if(mp[x-1][y]){
                    chmax(mp[x][y],mp[x-1][y]-(s[x][y]!='a'));
                }
                else {
                    if(s[x][y]==now)mp[x][y]=0;
                }
            }
            if(y and mp[x][y-1]!=-1){
                if(mp[x][y-1]){
                    chmax(mp[x][y],mp[x][y-1]-(s[x][y]!='a'));
                }
                else {
                    if(s[x][y]==now)chmax(mp[x][y],0);
                }
            }
        }
        best+=now;
    }
    cout<<best<<endl;
}