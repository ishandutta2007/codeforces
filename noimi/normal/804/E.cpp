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


vec a;
void sw(int x,int y){
    swap(a[x],a[y]);
    cout<<x+1<<" "<<y+1<<endl;
}
int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);cout<<fixed<<setprecision(15);
    int n=in();
    if((n%4)>1 )cout<<"NO\n";
    else{
        cout<<"YES\n";
        if(n==1)return 0;
        rep(i,n)a.pb(i);
        int pre=-1;
        rep(i,n-4){
            if(pre==-1){
                if(a[i]==i){
                    sw(i,n-1);
                    rep3(j,n-2,i+2)sw(i,j);
                    sw(i+1,n-1);
                    sw(i,i+1);
                    pre=n-1;
                }
                else{
                    rep3(j,n-1,i+1)if(a[j]!=i)sw(i,j);
                    rep2(j,i+1,n-1)if(a[j]==i)sw(i,j);
                }
            }
            else{
                if(a[pre]==i){
                    if(i+1!=pre)
                    sw(i+1,pre);
                    else pre=-1;
                    rep3(j,n-1,i+1)if(j!=pre)sw(i,j);
                }
                else if(a[i]==i){
                    rep3(j,n-1,i+2)if(j!=pre)sw(i,j);
                    sw(i+1,(pre==n-1 ? n-2:n-1));
                    sw(i,i+1);
                    pre=(pre==n-1 ? n-2:n-1);
                }
                else{
                    rep3(j,n-1,i+1)if(a[j]!=i and j!=pre)sw(i,j);
                    rep2(j,i+1,n-1)if(a[j]==i)sw(i,j);
                    pre=-1;
                }
            }
        }
        vector<pii> v;
        rep2(i,n-4,n-2){
            rep2(j,i+1,n-1){
                if(i==n-4 and j==pre)continue;
                v.eb(i,j);
            }
        }
        sort(all(v));
        vec ans;
        rep(i,n)ans.pb(i);
        do{
            auto b=a;
            for(auto e:v){
                swap(b[e.fi],b[e.se]);
            }
            if(ans==b){
                for(auto e:v)sw(e.fi,e.se);
                break;
            }
        }while(next_permutation(all(v)));
    }

}