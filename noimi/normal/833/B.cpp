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
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
template<class T> inline void print(pair<T,T> p){cout<<"("<<p.first<<","<<p.second<<") ";}
template<class T> inline void print(vector<pair<T,T>> v){for(auto e:v)print(e); cout<<endl;}
template<class T> inline void print(T v){for(auto e:v)cout<<e<<" ";cout<<endl;}


template< typename T, typename Compare = less< T > >
vector< pair< int, T > > monotone_minima(int H, int W, const function< T(int, int) > &f, const Compare &comp = Compare()) {
  vector< pair< int, T > > dp(H);
  function< void(int, int, int, int) > dfs = [&](int top, int bottom, int left, int right) {
    if(top > bottom) return;
    int line = (top + bottom) / 2;
    T ma;
    int mi = -1;
    for(int i = left; i <= right; i++) {
      T cst = f(line, i);
      if(mi == -1 || comp(cst, ma)) {
        ma = cst;
        mi = i;
      }
    }
    dp[line] = make_pair(mi, ma);
    dfs(top, line - 1, left, mi);
    dfs(line + 1, bottom, mi, right);
  };
  dfs(0, H - 1, 0, W - 1);
  return dp;
}

template< typename T, typename Compare = less< T > >
vector< vector< T > > divide_and_conquer_optimization(int H, int W, T INF, const function< T(int, int) > &f, const Compare &comp = Compare()) {
  vector< vector< T > > dp(H + 1, vector< T >(W + 1, INF));
  dp[0][0] = 0;
  for(int i = 1; i <= H; i++) {
    function< T(int, int) > get_cost = [&](int y, int x) {
      if(x >= y) return INF;
      return dp[i - 1][x] + f(x, y);
    };
    auto ret = monotone_minima(W + 1, W + 1, get_cost, comp);
    for(int j = 0; j <= W; j++) dp[i][j] = ret[j].second;
  }
  return dp;
}


int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);cout<<fixed<<setprecision(15);
    
    int n=in(),k=in();
    vec a;rep(i,n)a.pb(in());
    vec cnt(n+1);
    int L=0,R=0,sum=0;
    auto add =[&](int idx){if(cnt[a[idx]]==0)sum++;cnt[a[idx]]++;};
    auto del =[&](int idx){if(cnt[a[idx]]==1)sum--;cnt[a[idx]]--;};
    function<int(int l,int r)> f =[&](int l,int r){
        while(L>l) add(--L);
        while(R<r) add(R++);
        while(L<l) del(L++);
        while(R>r) del(--R);
        return -sum;
    };
    cout<<-divide_and_conquer_optimization(k,n,INT_MAX,f).back().back()<<endl;

        
    
}