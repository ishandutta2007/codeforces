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

ll ans=0;

bool solve(int l,int r,vec &a,ll k,ll m){
    int n=r-l;
    int pre;
    rep(i,n){
        if(a[i+l]!=a[l]){
            pre=i+l;break;
        }
        if(i==n-1){
            ll T=((ll)n*m)%k;
            ans+=T;
            if(T) return false;
            else return true;
        }
    }
    int suf;
    rep3(i,r-1,l){
        if(a[i]!=a[l]){
            suf=i+1;
            break;
        }
    }
    int con= n-(suf-pre);
    if(con < k){
        ans += (ll)n*m;
    }
    else if(con > k){
        ans += (ll)n*m-(ll)(m-1)*k;
    }
    else {
        ans+=k;
        if(solve(pre,suf,a,k,m)){
            ans-=k;
            return true;
        }
    }
    return false;
}


int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);cout<<fixed<<setprecision(15);
    int n=in(),k=in(),m=in();
    vec a;
    rep(i,n)a.pb(in());
    vec b;
    stack<pii> st;
    rep(i,n){
        if(st.empty())st.push(pii{a[i],1});
        else{
            if(st.top().fi==a[i]){
                st.top().second++;
                if(st.top().second==k)st.pop();
            }
            else st.push(pii{a[i],1});
        }
    }
    while(!st.empty()){
        rep(j,st.top().se)b.pb(st.top().fi);
        st.pop();
    }
    reverse(all(b));
    if(b.empty()){
        cout<<0<<endl;
        return 0;
    }
    solve(0,b.size(),b,k,m);
    cout << ans << endl;
}