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
vec ans;
void shift(string &s,int x){
    string t=s.substr(0,x);
    s = s.substr(x,s.size()-x);
    reverse(all(s));
    s+=t;
    ans.pb(s.size()-x);
}
void go(){
    int n=in();
    string s,t;cin>>s>>t;
    string p=s,q=t;
    sort(all(p));
    sort(all(q));
    if(p!=q){
        cout<<-1<<endl;
        return ;
    }
    int l=(n-2)/2, r = (n+1)/2;
    vector<char> a;
    if(n&1)a.pb(t[n/2]);
    rep(i,n/2){
        a.pb(t[l--]);
        a.pb(t[r++]);
    }
    int fi;
    rep(i,n){
        if(s[i] == a[0]){
            shift(s,i+1);
            shift(s,0);
            break;
        }
    }
    rep2(i,1,n-1){
        int t;
        rep2(j,i,n-1){
            if(s[j]==a[i]){t=j;break;}
        }
        shift(s,t);
        // cout<<n-t+i<<" "<<t<<" "<<i<<endl;cout.flush();
        shift(s,n-t+i);
        shift(s,n-i-1);
        // cout<<s<<endl;
    }
    // if(n&1)shift(s,0);
    // cout<<s<<endl;
    cout<<ans.size()<<endl;
    print(ans);
}