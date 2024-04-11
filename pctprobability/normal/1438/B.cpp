////////////////////////////////////////////////////////////////////////////////
//                          Give me AC!!!                                     //
////////////////////////////////////////////////////////////////////////////////
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using Graph = vector<vector<int>>; 
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
//xvector
#define ALL(x) (x).begin(),(x).end() //sort
#define SIZE(x) ((ll)(x).size()) //sizesize_tll
#define MAX(x) *max_element(ALL(x)) //
#define MIN(x) *min_element(ALL(x)) //
#define PQ priority_queue<vector<ll>,vector<vector<ll>>,greater<vector<ll>>>
#define PB push_back //vector
#define MP make_pair //pair
#define F first //pair
#define S second //pair
#define coutY cout<<"YES"<<endl
#define couty cout<<"Yes"<<endl
#define coutN cout<<"NO"<<endl
#define coutn cout<<"No"<<endl
#define coutdouble(a,b) cout << fixed << setprecision(a) << double(b) ;
#define vi(a,b) vector<int> a(b)
#define vl(a,b) vector<ll> a(b)
#define vs(a,b) vector<string> a(b)
#define vll(a,b,c)  vector<vector<ll>> a(b, vector<ll>(c));
#define intque(a) queue<int> a;
#define llque(a) queue<ll> a;
#define intque2(a) priority_queue<int, vector<int>, greater<int>> a;
#define llque2(a) priority_queue<ll, vector<ll>, greater<ll>> a;
#define pushback(a,b) a.push_back(b)
#define mapii(M1) map<int, int> M1;
#define cou(v,x) count(v.begin(), v.end(), x)
#define mapll(M1) map<ll,ll> M1;
#define mapls(M1) map<ll, string> M1;
#define mapsl(M1) map<string, ll> M1;
#define twolook(a,l,r,x) lower_bound(a+l, a+r, x) - a
#define sor(a) sort(a.begin(), a.end())
#define rever(a) reverse(a.begin(),a.end())
#define rep(i,a) for(ll i=0;i<a;i++)
#define vcin(n) for(ll i=0;i<ll(n.size());i++) cin>>n[i]
#define vcout(n) for(ll i=0;i<ll(n.size());i++) cout<<n[i]
#define vcin2(n) rep(i,ll(n.size())) rep(j,ll(n.at(0).size())) cin>>n[i][j]
//const ll mod = 998244353;
//const ll MOD = 998244353;
const ll MOD = 1000000007;
const ll mod = 1000000007;
constexpr ll MAX = 5000000;
//const ll _max = 9223372036854775807;
const ll _max = 1223372036854775807;
const ll INF = 2000000000000000000;
static const long double pi = 3.141592653589793;
  
ll fac[MAX],finv[MAX],inv[MAX];

// 
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}


int modPow(long long a, long long n, long long p) {
  if (n == 0) return 1; // 0
  if (n == 1) return a % p;
  if (n % 2 == 1) return (a * modPow(a, n - 1, p)) % p;
  long long t = modPow(a, n / 2, p);
  return (t * t) % p;
}

ll clocks(ll a,ll b,ll c){
  return a*3600+b*60+c;
}
ll divup(ll b,ll d){
   if(b%d==0){
    return b/d;
  }
  else{
    return b/d+1;
  }
}


struct Edge {
    int to;     // 
    int weight; // 
    Edge(int t, int w) : to(t), weight(w) { }
};

using Graphw = vector<vector<Edge>>;
ll zero(ll a){
  return max(ll(0),a);
}

template< typename T >
struct FormalPowerSeries : vector< T > {
  using vector< T >::vector;
  using P = FormalPowerSeries;

  using MULT = function< P(P, P) >;

  static MULT &get_mult() {
    static MULT mult = nullptr;
    return mult;
  }

  static void set_fft(MULT f) {
    get_mult() = f;
  }

  void shrink() {
    while(this->size() && this->back() == T(0)) this->pop_back();
  }

  P operator+(const P &r) const { return P(*this) += r; }

  P operator+(const T &v) const { return P(*this) += v; }

  P operator-(const P &r) const { return P(*this) -= r; }

  P operator-(const T &v) const { return P(*this) -= v; }

  P operator*(const P &r) const { return P(*this) *= r; }

  P operator*(const T &v) const { return P(*this) *= v; }

  P operator/(const P &r) const { return P(*this) /= r; }

  P operator%(const P &r) const { return P(*this) %= r; }

  P &operator+=(const P &r) {
    if(r.size() > this->size()) this->resize(r.size());
    for(int i = 0; i < r.size(); i++) (*this)[i] += r[i];
    return *this;
  }

  P &operator+=(const T &r) {
    if(this->empty()) this->resize(1);
    (*this)[0] += r;
    return *this;
  }

  P &operator-=(const P &r) {
    if(r.size() > this->size()) this->resize(r.size());
    for(int i = 0; i < r.size(); i++) (*this)[i] -= r[i];
    shrink();
    return *this;
  }

  P &operator-=(const T &r) {
    if(this->empty()) this->resize(1);
    (*this)[0] -= r;
    shrink();
    return *this;
  }

  P &operator*=(const T &v) {
    const int n = (int) this->size();
    for(int k = 0; k < n; k++) (*this)[k] *= v;
    return *this;
  }

  P &operator*=(const P &r) {
    if(this->empty() || r.empty()) {
      this->clear();
      return *this;
    }
    assert(get_mult() != nullptr);
    return *this = get_mult()(*this, r);
  }

  P &operator%=(const P &r) {
    return *this -= *this / r * r;
  }

  P operator-() const {
    P ret(this->size());
    for(int i = 0; i < this->size(); i++) ret[i] = -(*this)[i];
    return ret;
  }

  P &operator/=(const P &r) {
    if(this->size() < r.size()) {
      this->clear();
      return *this;
    }
    int n = this->size() - r.size() + 1;
    return *this = (rev().pre(n) * r.rev().inv(n)).pre(n).rev(n);
  }

  P pre(int sz) const {
    return P(begin(*this), begin(*this) + min((int) this->size(), sz));
  }

  P operator>>(int sz) const {
    if(this->size() <= sz) return {};
    P ret(*this);
    ret.erase(ret.begin(), ret.begin() + sz);
    return ret;
  }

  P operator<<(int sz) const {
    P ret(*this);
    ret.insert(ret.begin(), sz, T(0));
    return ret;
  }

  P rev(int deg = -1) const {
    P ret(*this);
    if(deg != -1) ret.resize(deg, T(0));
    reverse(begin(ret), end(ret));
    return ret;
  }

  P diff() const {
    const int n = (int) this->size();
    P ret(max(0, n - 1));
    for(int i = 1; i < n; i++) ret[i - 1] = (*this)[i] * T(i);
    return ret;
  }

  P integral() const {
    const int n = (int) this->size();
    P ret(n + 1);
    ret[0] = T(0);
    for(int i = 0; i < n; i++) ret[i + 1] = (*this)[i] / T(i + 1);
    return ret;
  }

  // F(0) must not be 0
  P inv(int deg = -1) const {
    assert(((*this)[0]) != T(0));
    const int n = (int) this->size();
    if(deg == -1) deg = n;
    P ret({T(1) / (*this)[0]});
    for(int i = 1; i < deg; i <<= 1) {
      ret = (ret + ret - ret * ret * pre(i << 1)).pre(i << 1);
    }
    return ret.pre(deg);
  }

  // F(0) must be 1
  P log(int deg = -1) const {
    assert((*this)[0] == 1);
    const int n = (int) this->size();
    if(deg == -1) deg = n;
    return (this->diff() * this->inv(deg)).pre(deg - 1).integral();
  }

  P sqrt(int deg = -1) const {
    const int n = (int) this->size();
    if(deg == -1) deg = n;

    if((*this)[0] == T(0)) {
      for(int i = 1; i < n; i++) {
        if((*this)[i] != T(0)) {
          if(i & 1) return {};
          if(deg - i / 2 <= 0) break;
          auto ret = (*this >> i).sqrt(deg - i / 2) << (i / 2);
          if(ret.size() < deg) ret.resize(deg, T(0));
          return ret;
        }
      }
      return P(deg, 0);
    }

    P ret({T(1)});
    T inv2 = T(1) / T(2);
    for(int i = 1; i < deg; i <<= 1) {
      ret = (ret + pre(i << 1) * ret.inv(i << 1)) * inv2;
    }
    return ret.pre(deg);
  }

  // F(0) must be 0
  P exp(int deg = -1) const {
    assert((*this)[0] == T(0));
    const int n = (int) this->size();
    if(deg == -1) deg = n;
    P ret({T(1)});
    for(int i = 1; i < deg; i <<= 1) {
      ret = (ret * (pre(i << 1) + T(1) - ret.log(i << 1))).pre(i << 1);
    }
    return ret.pre(deg);
  }

  P pow(int64_t k, int deg = -1) const {
    const int n = (int) this->size();
    if(deg == -1) deg = n;
    for(int i = 0; i < n; i++) {
      if((*this)[i] != T(0)) {
        T rev = T(1) / (*this)[i];
        P C(*this * rev);
        P D(n - i);
        for(int j = i; j < n; j++) D[j - i] = C[j];
        D = (D.log() * k).exp() * (*this)[i].pow(k);
        P E(deg);
        if(i * k > deg) return E;
        auto S = i * k;
        for(int j = 0; j + S < deg && j < D.size(); j++) E[j + S] = D[j];
        return E;
      }
    }
    return *this;
  }


  T eval(T x) const {
    T r = 0, w = 1;
    for(auto &v : *this) {
      r += w * v;
      w *= x;
    }
    return r;
  }
};

//ab,(a,10)a
ll expless(ll a,ll b){
  ll k=0;
  ll o=1;
  while(a>=o){
    k++;
    o=o*b;
  }
  return k;
}
//ab

//ba10
ll tenbase(ll a,ll b){
  ll c=expless(a,10);
  ll ans=0;
  ll k=1;
  for(int i=0;i<c;i++){
    ans+=(a%10)*k;
    k=k*b;
    a=a/10;
  }
  return ans;
}
vector<pair<long long, long long> > prime_factorize(long long N) {
    vector<pair<long long, long long> > res;
    for (long long a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        long long ex = 0; // 

        // 
        while (N % a == 0) {
            ++ex;
            N /= a;
        }

        //  push
        res.push_back({a, ex});
    }

    // 
    if (N != 1) res.push_back({N, 1});
    return res;
}

//ab
ll exp(ll a,ll b){
  ll ans=0;
  while(a%b==0){
    a=a/b;
    ans++;
  }
  return ans;
}
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int X[6]={1,1,0,-1,-1,0};
const int Y[6]={0,1,1,0,-1,-1};

template<typename T>
vector<T> smallest_prime_factors(T n) {

    vector<T> spf(n + 1);
    for (int i = 0; i <= n; i++) spf[i] = i;


    for (T i = 2; i * i <= n; i++) {

        // 
        if (spf[i] == i) {

            for (T j = i * i; j <= n; j += i) {

                // i
                if (spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }

    return spf;
}

vector<pair<ll,ll>> factolization(ll x, vector<ll> &spf) {
  vector<pair<ll,ll>> ret;
  ll p;
  ll z;
    while (x != 1) {
     p=(spf[x]);
      z=0;
      while(x%p==0){
        z++;
        x /= p;
      }
      ret.push_back({p, z});
    }
    return ret;
}
vector<bool> is;
vector<long long int> prime_(ll n){
    is.resize(n+1, true);
    is[0] = false; 
    is[1] = false;
 
    vector<long long int> primes;
    for (int i=2; i<=n; i++) {
        if (is[i] == true){
            primes.push_back(i);
            for (int j=i*2; j<=n; j+=i){
                is[j] = false;
            }
        }
    }
    return primes;
}
 vector<ll> dijkstra(ll f,ll n,vector<vector<vector<ll>>>& edge){
    //
    vector<ll> confirm(n,false);
    //
    //0,INF
    vector<ll> mincost(n,INF);mincost[f]=0;
    //Priority queue
    PQ mincand;mincand.push({mincost[f],f});

    //mincand
    while(!mincand.empty()){
        //
        vector<ll> next=mincand.top();mincand.pop();
        //
        if(confirm[next[1]]) continue;
        //
        confirm[next[1]]=true;
        //()l
        vector<vector<ll>>& v=edge[next[1]];ll l=SIZE(v);
        REP(i,l){
            //((2)(1))
            if(confirm[v[i][0]]) continue; //(1)
            //mincost()
            if(mincost[v[i][0]]<=next[0]+v[i][1]) continue; //(2)
            //
            mincost[v[i][0]]=next[0]+v[i][1];
            //()mincand
            mincand.push({mincost[v[i][0]],v[i][0]});
        }
    }
    return mincost;
}
ll so(ll a){
  ll ans=0;
  if(a==0){
    return 0;
  }
   while(a%2==0){
    a/=2;
    ans++;
  }
  return ans;
}
ll HOM(ll n,ll r){
  return COM(n+r-1,r);
}
ll binary(ll bina){
    ll ans = 0;
    for (ll i = 0; bina>0 ; i++)
    {
        ans = ans+(bina%2)*pow(10,i);
        bina = bina/2;
    }
    return ans;
}
class UnionFind {
public:
    vector<ll> parent; //parent[i]i
    vector<ll> siz; //(1)
    map<ll,vector<ll>> group;//(keyvalue)

    //
    UnionFind(ll n):parent(n),siz(n,1){ 
        //
        for(ll i=0;i<n;i++){parent[i]=i;}
    }

    //x()
    ll root(ll x){
        if(parent[x]==x) return x;
        return parent[x]=root(parent[x]);//
    }

    //xy
    void unite(ll x,ll y){
        ll rx=root(x);//x
        ll ry=root(y);//y
        if(rx==ry) return;//
        //(ryrx)
        if(siz[rx]<siz[ry]) swap(rx,ry);
        siz[rx]+=siz[ry];
        parent[ry]=rx;//xyyryxrx
    }

    //xy
    bool same(ll x,ll y){
        ll rx=root(x);
        ll ry=root(y);
        return rx==ry;
    }

    //x
    ll size(ll x){
        return siz[root(x)];
    }

    //
    void grouping(ll n){
        //
        REP(i,n)root(i);
        //map()
        REP(i,n)group[parent[i]].PB(i);
    }
};

vector<long long> enum_divisors(long long N) {
    vector<long long> res;
    for (long long i = 1; i * i <= N; ++i) {
        if (N % i == 0) {
            res.push_back(i);
            //  i  N/i  push
            if (N/i != i) res.push_back(N/i);
        }
    }
    // 
    sort(res.begin(), res.end());
    return res;
}
vector<ll> zaatu(vector<ll> a,ll n){
   map<ll,ll> mp;
   for (int i = 0; i < n; i++) {
      cin >> a[i];
      mp[a[i]] = 0;
   }
 
   // 
   ll num = 0;
   for (auto x : mp) {
      mp[x.first] = num;
      num++;
   }
 vector<ll> ans;
  for(int i=0;i<n;i++){
    ans.push_back(mp[a[i]]);
}
  return ans;
}
ll vectorcheck(vector<ll> t,ll key){
  auto iter = lower_bound(ALL(t), key);
  auto iter2 = upper_bound(ALL(t), key);
  if((iter-t.begin())!=(iter2-t.begin())){
    return 1;
  }
  else{
    return 0;
  }
}
template<class Monoid>
struct SegmentTree {
    using T = typename Monoid::value_type;
 
    std::vector<T> tree;
 
    SegmentTree() = default;
    explicit SegmentTree(ll n)
        :tree(n << 1, Monoid::identity()) {};
 
    template<class InputIterator>
    SegmentTree(InputIterator first, InputIterator last) {
        tree.assign(distance(first, last) << 1, Monoid::identity());
 
        ll i;
        i = size();
        for (InputIterator itr = first; itr != last; itr++) {
            tree[i++] = *itr;
        }
        for (i = size() - 1; i > 0; i--) {
            tree[i] = Monoid::operation(tree[(i << 1)], tree[(i << 1) | 1]);
        }
    };
 
    inline ll size() {
        return tree.size() >> 1;
    };
 
    inline T operator[] (ll k) {
        return tree[k + size()];
    };
    void add(ll k, const T dat) {
        k += size();
        tree[k] += dat;
        
        while(k > 1) {
            k >>= 1;
            tree[k] = Monoid::operation(tree[(k << 1)], tree[(k << 1) | 1]);
        }
    };
    void update(ll k, const T dat) {
        k += size();
        tree[k] = dat;
        
        while(k > 1) {
            k >>= 1;
            tree[k] = Monoid::operation(tree[(k << 1)], tree[(k << 1) | 1]);
        }
    };
 
    T fold(ll l, ll r) {
        l += size(); //points leaf
        r += size();
 
        T lv = Monoid::identity();
        T rv = Monoid::identity();
        while (l < r) {
            if (l & 1) lv = Monoid::operation(lv, tree[l++]);
            if (r & 1) rv = Monoid::operation(tree[--r], rv);
            l >>= 1;
            r >>= 1;
        }
 
        return Monoid::operation(lv, rv);
    };
 
    template<class F>
    inline ll sub_tree_search(ll i, T sum, F f) {
        while (i < size()) {
            T x = Monoid::operation(sum, tree[i << 1]);
            if (f(x)) {
                i = i << 1;
            }
            else {
                sum = x;
                i = (i << 1) | 1;
            }
        }
        return i - size();
    }
 
    template<class F>
    ll search(ll l, F f) {
        l += size();
        ll r = size() * 2; //r = n;
        ll tmpr = r;
        ll shift = 0;
 
        T sum = Monoid::identity();
        while (l < r) {
            if (l & 1) {
                if (f(Monoid::operation(sum, tree[l]))) {
                    return sub_tree_search(l, sum, f);
                }
                sum = Monoid::operation(sum, tree[l]);
                l++;
            }
            l >>= 1;
            r >>= 1;
            shift++;
        }
 
        while (shift > 0) {
            shift--;
            r = tmpr >> shift;
            if (r & 1) {
                r--;
                if (f(Monoid::operation(sum, tree[r]))) {
                    return sub_tree_search(r, sum, f);
                }
                sum = Monoid::operation(sum, tree[r]);
            }
        }
 
        return -1;
    };
};
 
using namespace std;
using llong = long long;
 
struct Monoid {
    using value_type = ll;
    inline static ll identity() {
        return 0;
    };
    inline static ll operation(ll a, ll b) {
        return max(a,b);
    };
};
class mint {
    long long x;
public:
    mint(long long x=0) : x((x%mod+mod)%mod) {}
    mint operator-() const { 
      return mint(-x);
    }
    mint& operator+=(const mint& a) {
        if ((x += a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator-=(const mint& a) {
        if ((x += mod-a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator*=(const  mint& a) {
        (x *= a.x) %= mod;
        return *this;
    }
    mint operator+(const mint& a) const {
        mint res(*this);
        return res+=a;
    }
    mint operator-(const mint& a) const {
        mint res(*this);
        return res-=a;
    }
    mint operator*(const mint& a) const {
        mint res(*this);
        return res*=a;
    }
    mint pow(ll t) const {
        if (!t) return 1;
        mint a = pow(t>>1);
        a *= a;
        if (t&1) a *= *this;
        return a;
    }
    // for prime mod
    mint inv() const {
        return pow(mod-2);
    }
    mint& operator/=(const mint& a) {
        return (*this) *= a.inv();
    }
    mint operator/(const mint& a) const {
        mint res(*this);
        return res/=a;
    }

    friend ostream& operator<<(ostream& os, const mint& m){
        os << m.x;
        return os;
    }
};
ll f(ll a){
  if(a==0){
    return 1;
  }
  ll ans=1;
  for(int i=1;i<=a;i++){
    ans*=i;
    ans%=mod;
  }
  return ans;
}
ll met(ll a,ll b){
  if(a!=0&&b!=0){
    return 0;
  }
  else{
    ll k=max(a,b);
    if(k==0){
      return 1;
    }
    if(k==1){
      return 2;
    }
    return 1;
  }
}
ll p(ll x1,ll y1,ll x2,ll y2,ll x3,ll y3){
  if(x1==x2&&x2==x3){
    return 1;
  }
  if(y1==y2&&y2==y3){
    return 1;
  }
  if((y3-y1)*(x2-x1)==(y2-y1)*(x3-x1)){
    return 1;
  }
  return 2;
}
int ctoi(const char c){
  switch(c){
    case '0': return 0;
    case '1': return 1;
    case '2': return 2;
    case '3': return 3;
    case '4': return 4;
    case '5': return 5;
    case '6': return 6;
    case '7': return 7;
    case '8': return 8;
    case '9': return 9;
    default : return -1;
  }
}
ll ord(ll a,ll b){
  ll ans=0;
  while(a%b==0){
    ans++;
    a/=b;
  }
  return ans;
}
ll atll(ll a,ll b){
  b++;
  ll c=expless(a,10);
  ll d=c-b;
  ll f=1;
  for(int i=0;i<d;i++){
    f=f*10;
  }
  a=(a/f);
  return a%10;
}
void solve(){
  ll n;
  cin>>n;
  vector<ll> a(n);
  vcin(a);
  sor(a);
  string ans="NO";
  for(int i=0;i<n-1;i++){
    if(a.at(i)==a.at(i+1)){
      ans="YES";
    }
  }
  cout<<ans<<endl;
}
int main() {
  ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
   cout << fixed << setprecision(30);
  ll a;
  cin>>a;
  for(int i=0;i<a;i++){
    solve();
  }
}