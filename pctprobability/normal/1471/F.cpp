#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define all(s) (s).begin(),(s).end()
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
#define vcin(n) for(ll i=0;i<ll(n.size());i++) cin>>n[i]
#define rep2(i, m, n) for (int i = (m); i < (n); ++i)
#define rep(i, n) rep2(i, 0, n)
#define drep2(i, m, n) for (int i = (m)-1; i >= (n); --i)
#define drep(i, n) drep2(i, n, 0)
#define rever(vec) reverse(vec.begin(), vec.end())
#define sor(vec) sort(vec.begin(), vec.end())
const ll mod = 998244353;
const ll inf = 2000000000000000000ll;
static const long double pi = 3.141592653589793;
template<class T,class U> void chmax(T& t,const U& u){if(t<u) t=u;}
template<class T,class U> void chmin(T& t,const U& u){if(t>u) t=u;}
ll modPow(ll a, ll n, ll mod) { ll ret = 1; ll p = a % mod; while (n) { if (n & 1) ret = ret * p % mod; p = p * p % mod; n >>= 1; } return ret; }
void solve(){
  ll n,m;
  cin>>n>>m;
  vector<vector<ll>> a(n);
  for(int i=0;i<m;i++){
    ll x,y;
    cin>>x>>y;
    x--;
    y--;
    a[x].push_back(y);
    a[y].push_back(x);
  }
  vector<bool> seen(n,false);
  seen[0]=true;
  queue<ll> q;
  q.push(0);
  while(!q.empty()){
    ll s=q.front();
    q.pop();
    for(ll d:a[s]){
      if(!seen[d]){
        seen[d]=true;
        q.push(d);
      }
    }
  }
  for(int i=0;i<n;i++){
    if(!seen[i]){
      cout<<"NO"<<endl;
      return;
    }
  }
  vector<ll> w(n,-1);//-101
  queue<ll> k;
  w[0]=0;
  for(ll h:a[0]){
    w[h]=1;
    k.push(h);
  }
  while(!k.empty()){
    ll e=k.front();
    k.pop();
    for(ll h:a[e]){
      if(w[h]==-1){
        w[h]=0;
        for(ll z:a[h]){
          if(w[z]==-1){
            w[z]=1;
            k.push(z);
          }
        }
      }
    }
  }
  ll count=0;
  cout<<"YES"<<endl;
  for(int i=0;i<n;i++){
    if(w[i]==0){
      count++;
    }
  }
  cout<<count<<endl;
  for(int i=0;i<n;i++){
    if(w[i]==0){
      cout<<i+1<<" ";
    }
  }
  cout<<endl;
}
int main() {
  /* mod  1e9+7 */
  ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
  cout<< fixed << setprecision(10);
  ll t;
  cin>>t;
  while(t--){
    solve();
  }
}