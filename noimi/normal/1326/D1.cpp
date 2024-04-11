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
    tc=in();
    while(tc--){
        go();
    }
    return 0;
}

template< typename T >
struct SparseTable {
  vector< vector< T > > st;
  vector< int > lookup;

  SparseTable(const vector< T > &v) {
    int b = 0;
    while((1 << b) <= v.size()) ++b;
    st.assign(b, vector< T >(1 << b));
    for(int i = 0; i < v.size(); i++) {
      st[0][i] = v[i];
    }
    for(int i = 1; i < b; i++) {
      for(int j = 0; j + (1 << i) <= (1 << b); j++) {
        st[i][j] = max(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
      }
    }
    lookup.resize(v.size() + 1);
    for(int i = 2; i < lookup.size(); i++) {
      lookup[i] = lookup[i >> 1] + 1;
    }
  }

  inline T rmq(int l, int r) {
    int b = lookup[r - l];
    return max(st[b][l], st[b][r - (1 << b)]);
  }
};



// RMQ


vector< int > manacher(const string &s) {
  vector< int > radius(s.size());
  int i = 0, j = 0;
  while(i < s.size()) {
    while(i - j >= 0 && i + j < s.size() && s[i - j] == s[i + j]) {
      ++j;
    }
    radius[i] = j;
    int k = 1;
    while(i - k >= 0 && i + k < s.size() && k + radius[i - k] < j) {
      radius[i + k] = radius[i - k];
      ++k;
    }
    i += k;
    j -= k;
  }
  return radius;
}
int n;
int ma,pre,suf;
void solve(string &t,string &s){
    vec res = manacher(t);
    vec r;
    rep(i,res.size())r.pb(res[i]-i);
    SparseTable<int> sp(r);
    rep(i,n+1){
        int l=i*2+1,r=n+1;
        if(l>=r)break;
        while(l<r-1){
            int mid=(l+r)/2;
            if(sp.rmq(mid,n+1)>= -i*2 +1) l=mid;
            else r=mid;
        }
        int tmp = i*2 + l-i*2;
        if(chmax(ma,tmp)) pre=i+ (l-i*2) , suf = i;
        if(s[i]!=s[n-1-i])break;
    }
}
void go(){
    string s;cin>>s;
    n=s.size();
    string t=".";
    rep(i,n)t.pb(s[i]),t.pb('.');
    vec res = manacher(t);
    vec r;
    rep(i,res.size())r.pb(res[i]-i);
    SparseTable<int> sp(r);
    ma=0,pre=0,suf=0;
    solve(t,s);
    // cout<<ma<<" "<<pre<<" "<<suf<<endl;
    reverse(all(t));reverse(all(s));
    int mem=ma;
    solve(t,s);
    if(ma>mem){
        swap(pre,suf);
    }
    reverse(all(s));
    rep(i,pre)cout<<s[i];
    rep(i,suf)cout<<s[n-suf+i];
    cout<<endl;
        
}