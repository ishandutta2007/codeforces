#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;
using ll = long long;
using ld = long double;
#define all(s) (s).begin(),(s).end()
#define vcin(n) for(ll i=0;i<ll(n.size());i++) cin>>n[i]
#define rever(vec) reverse(vec.begin(), vec.end())
#define sor(vec) sort(vec.begin(), vec.end())
#define fi first
#define se second
#define SIZE(n) int(n.size())
//const ll mod = 998244353;
const ll mod = 1000000007;
const ll inf = 2000000000000000000ll;
static const long double pi = 3.141592653589793;
template<class T,class U> void chmax(T& t,const U& u){if(t<u) t=u;}
template<class T,class U> void chmin(T& t,const U& u){if(t>u) t=u;}
ll modPow(ll a, ll n, ll mod) { ll ret = 1; ll p = a % mod; while (n) { if (n & 1) ret = ret * p % mod; p = p * p % mod; n >>= 1; } return ret; }
//abstruct lazy segment tree 
template<typename D, typename L>
struct segtree {
    using F = function<D(D, D)>;
    using G = function<D(L, D)>;
    using H = function<L(L, L)>;
    F f;
    G g;
    H h;
    D De;
    L Le;
    int n, height;
    vector<D> dat;
    vector<L> lazy;

    segtree(F f, G g, H h, D De, L Le):
        f(f), g(g), h(h), De(De), Le(Le){}
 
    void init(int n_) {
        n = 1;
        height = 0;
        while (n < n_) {
            n <<= 1;
            height++;
        }
        lazy.assign(2 * n, Le);
        dat.assign(2 * n, De);
    }

    void build(const vector<D> &v) {
        int n_ = v.size();
        init(n_);
        for (int i = 0; i < n_; i++) {
            dat[i + n] = v[i];
        }
        for (int i = n - 1; i > 0; i--) {
            dat[i] = f(dat[i << 1], dat[(i << 1) | 1]);
        }
    }

    D reflect(int k) {
        if (lazy[k] == Le) {
            return dat[k];
        } else {
            return g(lazy[k], dat[k]);
        }
    }

    void propagate(int k) {
        if (lazy[k] == Le) {
            return;
        }
        if (k < n) {
            lazy[k << 1] = h(lazy[k], lazy[k << 1]);
            lazy[(k << 1) | 1] = h(lazy[k], lazy[(k << 1) | 1]);
        }
        dat[k] = reflect(k);
        lazy[k] = Le;
    }

    void thrust(int k) {
        for (int i = height; i > 0; i--) {
            propagate(k >> i);
        }
    }

    void recalc(int k) {
        while (k >>= 1) {
            dat[k] = f(reflect(k << 1), reflect((k << 1) | 1));
        }
    }

    //[a, b)
    void update(int a, int b, L x) {
        if (a >= b) {
            return;
        }
        a += n;
        thrust(a);
        b += n - 1;
        thrust(b);
        for (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) {
                lazy[l] = h(x, lazy[l]);
                l++;
            }
            if (r & 1) {
                r--;
                lazy[r] = h(x, lazy[r]);
            }
        }
        recalc(a);
        recalc(b);
    }

    //ka
    void setval(int a, D x) {
        a += n;
        thrust(a);
        dat[a] = x;
        lazy[a] = Le;
        recalc(a);
    }

    //[a, b)
    D query(int a, int b) {
        if (a >= b) {
            return De;
        }
        a += n;
        thrust(a);
        b += n - 1;
        thrust(b);
        D vl = De, vr = De;
        for (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) {
                vl = f(vl, reflect(l));
                l++;
            }
            if (r & 1) {
                r--;
                vr = f(reflect(r), vr);
            }
        }
        return f(vl, vr);
    }
};
typedef pair<ll, ll> plglg;
void solve(){
  ll n,q;
  cin>>n>>q;
  string s;
  cin>>s;
  string f;
  cin>>f;
  vector<ll> a(q);
  vector<ll> b(q);
  for(int i=0;i<q;i++){
    cin>>a[i]>>b[i];
    a[i]--;
    b[i]--;
  }
  vector<ll> p(int(s.size()));
  for(int i=0;i<int(f.size());i++){
    p[i]=f[i]-'0';
  }
  auto fi = [](plglg a, plglg b){return plglg(a.first + b.first, a.second + b.second);};
    auto g = [](ll a, plglg b){return plglg(a * b.second, b.second);};
    auto h = [](ll a, ll b){return a;};
   segtree<plglg, ll> seg(fi, g, h, plglg(0, 0), inf);
   seg.build(vector<plglg>(n, plglg(0, 1)));
  for(int i=0;i<n;i++){
    seg.update(i,i+1,p[i]);
  }
  rever(a);
  rever(b);
   for(int j=0;j<n;j++){
//      cout<<seg.query(j,j+1).first;
    }
//  cout<<endl;
 // cout<<rmq.query(6,10)<<endl;
  for(int i=0;i<q;i++){
    ll s=b[i]-a[i]+1;
    for(int j=0;j<n;j++){
 //     cout<<seg.query(j,j+1).first;
    }
 //   cout<<endl;
    ll r=seg.query(a[i],b[i]+1).first;
 //   cout<<a[i]<<" "<<b[i]<<" "<<r<<endl;
    if(s==r*2){
      cout<<"NO"<<endl;
      return;
    }
    if(s>r*2){
      seg.update(a[i],b[i]+1,0);
    }
    if(s<r*2){
      seg.update(a[i],b[i]+1,1);
    }
  }
  for(int i=0;i<n;i++){
    if(s[i]-'0'!=seg.query(i,i+1).first){
      cout<<"NO"<<endl;
      return;
    }
  }
  cout<<"YES"<<endl;
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