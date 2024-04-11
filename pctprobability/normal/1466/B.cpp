////////////////////////////////////////////////////////////////////////////////
//                          Give me AC!!!                                     //
////////////////////////////////////////////////////////////////////////////////
#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using ll = long long;
using ld = long double;
using graph = vector<vector<int>>; 
#define NDEBUG
using int64 = long long;
const int64 infll = (1LL << 62) - 1;
#define all(s) (s).begin(),(s).end()
#define sz(x) (int) (x).size()
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define bit(n,k) ((n>>k)&1) /*nk bit*/
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
#define drep2(i, m, n) for (int i = (m)-1; i >= (n); --i)
#define drep(i, n) drep2(i, n, 0)
const ll mod = 998244353;
const ll MOD = 998244353;
//const ll MOD=1000000007;
//const ll mod=1000000007;
constexpr ll MAX = 500000;
//const ll _max = 9223372036854775807;
const ll _max = 1223372036854775807;
const ll inf = 2000000000000000000ll;
static const long double pi = 3.141592653589793;
const int MAX_COL=350;
const int MAX_ROW=350;
ll fac[MAX],finv[MAX],inv[MAX];
typedef int FLOW;                //  int 
const int MAX_V = 6000;           // 
const FLOW INF = 100000000;
 
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
ll HOM(ll n,ll k){
  if(n+k-1>=n-1&&n-1>=0){
  return COM(n+k-1,n-1);
  }
  else{
    return 0;
  }
}
ll modPow(long long a, long long n, long long p) {
  if (a == 0 && n == 0) return 1;
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
ll zero(ll a){
  return max(ll(0),a);
}
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
template <class T, class U>
void chmin(T& t, const U& u) {
    if (t > u) t = u;
}
template <class T, class U>
void chmax(T& t, const U& u) {
    if (t < u) t = u;
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
ll binary(ll bina){
    ll ans = 0;
    for (ll i = 0; bina>0 ; i++)
    {
        ans = ans+(bina%2)*pow(10,i);
        bina = bina/2;
    }
    return ans;
}
 
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
struct BitMatrix {
    int H, W;
    bitset<MAX_COL> val[MAX_ROW];
    BitMatrix(int m = 1, int n = 1) : H(m), W(n) {}
    inline bitset<MAX_COL>& operator [] (int i) {return val[i];}
};
 
int GaussJordan(BitMatrix &A, bool is_extended = false) {
    int rank = 0;
    for (int col = 0; col < A.W; ++col) {
        if (is_extended && col == A.W - 1) break;
        int pivot = -1;
        for (int row = rank; row < A.H; ++row) {
            if (A[row][col]) {
                pivot = row;
                break;
            }
        }
        if (pivot == -1) continue;
        swap(A[pivot], A[rank]);
        for (int row = 0; row < A.H; ++row) {
            if (row != rank && A[row][col]) A[row] ^= A[rank];
        }
        ++rank;
    }
    return rank;
}
int pos(const char c){
  if('a' <= c && c <= 'z') return (c-'a');
  return -1;
}
// 
struct Edge {
    int rev, from, to;
    FLOW cap, icap;
    Edge(int r, int f, int t, FLOW c) : rev(r), from(f), to(t), cap(c), icap(c) {}
    friend ostream& operator << (ostream& s, const Edge& E) {
        if (E.cap > 0) return s << E.from << "->" << E.to << '(' << E.cap << ')';
        else return s;
    }
};
 
// 
struct Graph {
    int V;
    vector<Edge> list[MAX_V];
 
    Graph(int n = 0) : V(n) { for (int i = 0; i < MAX_V; ++i) list[i].clear(); }
    void init(int n = 0) { V = n; for (int i = 0; i < MAX_V; ++i) list[i].clear(); }
    void resize(int n = 0) { V = n; }
    void reset() { for (int i = 0; i < V; ++i) for (int j = 0; j < int(list[i].size()); ++j) list[i][j].cap = list[i][j].icap; }
    inline vector<Edge>& operator [] (int i) { return list[i]; }
 
    Edge &redge(Edge e) {
        if (e.from != e.to) return list[e.to][e.rev];
        else return list[e.to][e.rev + 1];
    }
 
    void addedge(int from, int to, FLOW cap) {
        list[from].push_back(Edge((int)list[to].size(), from, to, cap));
        list[to].push_back(Edge((int)list[from].size() - 1, to, from, 0));
    }
};
 
// 
static int level[MAX_V];
static int iter[MAX_V];
 
void dibfs(Graph &G, int s) {
    for (int i = 0; i < MAX_V; ++i) level[i] = -1;
    level[s] = 0;
    queue<int> que;
    que.push(s);
    while (!que.empty()) {
        int v = que.front();
        que.pop();
        for (int i = 0; i < int(G[v].size()); ++i) {
            Edge &e = G[v][i];
            if (level[e.to] < 0 && e.cap > 0) {
                level[e.to] = level[v] + 1;
                que.push(e.to);
            }
        }
    }
}
 
FLOW didfs(Graph &G, int v, int t, FLOW f) {
    if (v == t) return f;
    for (int &i = iter[v]; i < int(G[v].size()); ++i) {
        Edge &e = G[v][i], &re = G.redge(e);
        if (level[v] < level[e.to] && e.cap > 0) {
            FLOW d = didfs(G, e.to, t, min(f, e.cap));
            if (d > 0) {
                e.cap -= d;
                re.cap += d;
                return d;
            }
        }
    }
    return 0;
}
 
// 
FLOW Dinic(Graph &G, int s, int t) {
    FLOW res = 0;
    while (true) {
        dibfs(G, s);
        if (level[t] < 0) return res;
        memset(iter, 0, sizeof(iter));
        FLOW flow;
        while ((flow = didfs(G, s, t, INF)) > 0) {
            res += flow;
        }
    }
}
vector<ll> topological_sort(vector<vector<ll>> &G, vector<ll> &indegree, ll V) {
    // 
    vector<ll> sorted_vertices;
 
    // 0
    queue<ll> que;
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            que.push(i);
        }
    }
 
    // 1~3
    while (que.empty() == false) {
        // 
        int v = que.front();
        que.pop();
 
        // 0
        for (int i = 0; i < int(G[v].size()); i++) {
            int u = G[v][i];
            indegree[u] -= 1;
            if (indegree[u] == 0) que.push(u);
        }
        // v 
        sorted_vertices.push_back(v);
    }
 
    // 
    return sorted_vertices;
}
vector<vector<ll>> multi(vector<vector<ll>> a, vector<vector<ll>> b){
    ll n = a.size();
    vector<vector<ll>> res(n, vector<ll>(n, 0));
    for (ll i = 0; i < n; ++i){
        for (ll j = 0; j < n; ++j){
            for (ll x = 0; x < n; ++x){
                res[i][j] = (res[i][j] + (a[i][x] * b[x][j])) % mod;
            }
        }
    }
    return res;
}
vector<vector<ll>> mul_exp(vector<vector<ll>> adj, ll k, ll n){
    if (k == 1) return adj;
    vector<vector<ll>> res = mul_exp(adj, k / 2, n);
    if (k % 2 == 0) return multi(res, res);
    else return multi(adj, multi(res, res));
}
struct CHT {
 
    struct Line {
        ll slope, yIntercept;
 
        Line(ll slope, ll yIntercept) : slope(slope), yIntercept(yIntercept) {}
 
        ll val(ll x) {
            return slope * x + yIntercept;
        }
 
        ll intersect(Line y) {
            return (y.yIntercept - yIntercept + slope - y.slope - 1) / (slope - y.slope);
        }
    };
 
    deque<pair<Line, ll>> dq;
 
    void insert(ll slope, ll yIntercept) {
        Line newLine(slope, yIntercept);
 
        while (sz(dq) > 1 && dq.back().second >= dq.back().first.intersect(newLine))
            dq.pop_back();
 
        if (dq.empty()) {
            dq.emplace_back(newLine, 0);
            return;
        }
 
        dq.emplace_back(newLine, dq.back().first.intersect(newLine));
    }
 
    ll query(ll x) {
 
        while (sz(dq) > 1) {
            if (dq[1].second <= x) dq.pop_front();
            else break;
        }
 
        return dq[0].first.val(x);
    }
 
    ll query2(ll x) {
        auto qry = *lower_bound(dq.rbegin(), dq.rend(),
                                make_pair(Line(0, 0), x),
                                [&](const pair<Line, int> &a, const pair<Line, int> &b) {
                                    return a.second > b.second;
                                });
 
        return qry.first.val(x);
    }
};
template <typename T>
int compress(vector<T> x, map<T, int> &zip, vector<int> &unzip) {
    sort(x.begin(), x.end());
    x.erase(unique(x.begin(), x.end()), x.end());
    for (int i = 0; i < x.size(); i++) {
        zip[x[i]] = i;
        unzip[i] = x[i];
    }
    return x.size();
}
long long modlog(long long x,long long y,long long MOD){
    x %= MOD;
    y %= MOD;
 
    long long H = sqrt(MOD);
 
    vector<pair<long long,long long>> baby(H);
    // Baby-step
    long long Z = y;
    for(long long a=0;a<H;a++){ //yx^(H-1)
        baby[a] = make_pair(Z,a);
        Z = (Z*x) % MOD;
    }
    sort(baby.begin(),baby.end());
 
    // Giant step
    long long xH=1;
    for(int i=0;i<H;i++) xH = (xH*x) % MOD;
 
    long long xaH = 1;
    for(int a=1;a<=(MOD/H)+1;a++){
        xaH = (xaH*xH) % MOD;
        auto itr = lower_bound(baby.begin(),baby.end(),make_pair(xaH+1,0LL));
        if(itr->second==H) continue;
        itr--;
        if(itr->first==xaH) return a*H - itr->second;
    }
    return -1;
}
vector<pair<ll,ll>> lp(vector<ll> a){
  sor(a);
  ll x=a.at(0);
  ll y=1;
  vector<pair<ll,ll>> ans;
  for(int i=1;i<int(a.size());i++){
    if(a.at(i)!=a.at(i-1)){
      ans.push_back({x,y});
      x=a.at(i);
      y=1;
    }
    else{
      y++;
    }
  }
  if(y!=0){
    ans.push_back({x,y});
  }
  return ans;
}
typedef unsigned long long ull;
#define B1 100000007
#define B2 1000000007
bool rolling_hash(string const& S, int t_start, int m){
  int s_start = t_start + m;
 
  // B^m
  ull pow_B_m_1 = 1, pow_B_m_2 = 1;
  for(int k = 0; k < m; k++){
    pow_B_m_1 *= B1, pow_B_m_2 *= B2;
  }
 
  // stmsh,th
  ull sh1 = 0, sh2 = 0, th1 = 0, th2 = 0;
  for(int k = 0; k < m; k++){
    th1 = th1 * B1 + S[t_start + k], th2 = th2 * B2 + S[t_start + k];
    sh1 = sh1 * B1 + S[s_start + k], sh2 = sh2 * B2 + S[s_start + k];
  }
 
  // s
  for(int k = 0; s_start + k < int(S.length()); k++){
    if(sh1 == th1 && sh2 == th2) return true;
    if(k + s_start < int(S.length())){
      sh1 = sh1 * B1 + S[s_start + m + k] - S[s_start + k] * pow_B_m_1;
      sh2 = sh2 * B2 + S[s_start + m + k] - S[s_start + k] * pow_B_m_2;
    }
  }
  return false;
}
constexpr double PI = acosl(-1);
struct Comp {
    double real, imag;
    Comp(double real = 0, double imag = 0) : real(real), imag(imag) {}
    friend inline ostream& operator << (ostream &s, const Comp &c) {
        return s << '<' << c.real << ',' << c.imag << '>';
    }
    inline Comp operator + (const Comp &c) {
        return {real + c.real, imag + c.imag};
    }
    inline Comp operator - (const Comp &c) {
        return {real - c.real, imag - c.imag};
    }
    inline Comp operator * (const Comp &c) {
        return {real * c.real - imag * c.imag,
                real * c.imag + imag * c.real};
    }
    inline Comp operator * (double a) {
        return {real * a, imag * a};
    }
    inline Comp operator / (double a) {
        return {real / a, imag / a};
    }
};
// FFT
void trans(vector<Comp> &v, bool inv = false) {
    int n = SIZE(v);
    for (int i = 0, j = 1; j < n-1; j++) {
        for (int k = n>>1; k > (i ^= k); k >>= 1);
        if (i > j) swap(v[i], v[j]);
    }
    for (int t = 2; t <= n; t <<= 1) {
        double ang = acosl(-1.0) * 2 / t;
        if (inv) ang = -ang;
        for (int i = 0; i < n; i += t) {
            REP(j, t/2) {
                Comp w = {cos(ang * j), sin(ang * j)};
                int j1 = i + j, j2 = i + j + t/2;
                Comp c1 = v[j1], c2 = v[j2] * w;
                v[j1] = c1 + c2;
                v[j2] = c1 - c2;
            }
        }
    }
    if (inv) REP(i, n) v[i] = v[i]/n;
}

// A * B
vector<ll> mult(const vector<ll> &A,
                const vector<ll> &B) {
    int size_a = 1; while (size_a < SIZE(A)) size_a <<= 1;
    int size_b = 1; while (size_b < SIZE(B)) size_b <<= 1;
    int size_fft = max(size_a, size_b) << 1;
    
    vector<Comp> cA(size_fft), cB(size_fft), cC(size_fft);
    for (int i = 0; i < SIZE(A); ++i) cA[i] = {(double)A[i], 0};
    for (int i = 0; i < SIZE(B); ++i) cB[i] = {(double)B[i], 0};
    
    trans(cA); trans(cB);
    REP(i, size_fft) cC[i] = cA[i] * cB[i];
    trans(cC, true);
    
    vector<ll> res(SIZE(A) + SIZE(B) - 1);
    for (int i = 0; i < SIZE(res); ++i) {
        res[i] = (ll)(cC[i].real + 0.5);
    }
    return res;
}
template<typename T>
struct BellmanFord {
    struct Vertex {
        int to; T cost;
        Vertex (int to_, T cost_) : to(to_), cost(cost_) {}
    };
    
    T INF;
    const int n;
    vector<vector<Vertex>> Graph, invGraph;
    vector<T> dt;
    vector<bool> reach;
    
    void reachable(const int now, vector<bool> &seen){
        if(seen[now]) return;
        seen[now] = true;
        for(const Vertex nxt : Graph[now]) reachable(nxt.to, seen); 
    }
 
    public:
    bool loop = false;
 
    BellmanFord (const int n_, const T INF_ = numeric_limits<T>::max()/2) 
    : INF(INF_), n(n_), Graph(n_), invGraph(n_), dt(n, INF), reach(n, true) {}
 
    T operator [] (const int i) { return dt[i]; }
 
    void AddEdge(const int from, const int to, const T cost){
        Graph[from].push_back(Vertex(to, cost));
    }
 
    void Build (const int from){
        dt[from] = 0;
        for(int i = 0; i < n; i++){
            bool update = false;
            for(int now = 0; now < n; now++){    
                if(!reach[now]) continue;
                for(const Vertex nxt : Graph[now]){
                    if(!reach[nxt.to] or dt[now] == INF) continue;
                    if(dt[nxt.to] > dt[now] + nxt.cost){
                        dt[nxt.to] = dt[now] + nxt.cost;
                        update = true;
                        if(i == n-1) loop = true;
                    }
                }    
            }
            if(!update) break;
        }
    }
    void Build (const int from, const int to){
        for(int i = 0; i < n; i++){
            vector<bool> seen(n, false);
            reachable(i, seen);
            reach[i] = seen[to];
        }
        Build(from);
    }
};
ll P(ll a,ll b){
  if(a<0||b<0||a<b) return -1;
  ll c=a-b;
  c=modPow(fac[c],mod-2,mod);
  a=fac[a];
  a*=c;
  a%=mod;
  return a;
}
class UnionFind {
public:
    vector <ll> par; // 
    vector <ll> siz; // (1 )
 
    // Constructor
    UnionFind(ll sz_): par(sz_), siz(sz_, 1LL) {
        for (ll i = 0; i < sz_; ++i) par[i] = i; // 
    }
    void init(ll sz_) {
        par.resize(sz_);
        siz.assign(sz_, 1LL);  // resize 
        for (ll i = 0; i < sz_; ++i) par[i] = i; // 
    }
 
    // Member Function
    // Find
    ll root(ll x) { // 
        while (par[x] != x) {
            x = par[x] = par[par[x]]; // x  x 
        }
        return x;
    }
 
    // Union(Unite, Merge)
    bool merge(ll x, ll y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        // merge technique
        if (siz[x] < siz[y]) swap(x, y);
        siz[x] += siz[y];
        par[y] = x;
        return true;
    }
 
    bool issame(ll x, ll y) { // 
        return root(x) == root(y);
    }
 
    ll size(ll x) { // 
        return siz[root(x)];
    }
};
template<class Monoid, class Action> struct SegTree {
    using FuncMonoid = function< Monoid(Monoid, Monoid) >;
    using FuncAction = function< void(Monoid&, Action) >;
    using FuncLazy = function< void(Action&, Action) >;
    FuncMonoid FM;
    FuncAction FA;
    FuncLazy FL;
    Monoid IDENTITY_MONOID;
    Action IDENTITY_LAZY;
    int SIZE, HEIGHT;
    vector<Monoid> dat;
    vector<Action> lazy;
    
    SegTree() { }
    SegTree(int n, const FuncMonoid fm, const FuncAction fa, const FuncLazy fl,
            const Monoid &identity_monoid, const Action &identity_lazy)
    : FM(fm), FA(fa), FL(fl), 
      IDENTITY_MONOID(identity_monoid), IDENTITY_LAZY(identity_lazy) {
        SIZE = 1, HEIGHT = 0;
        while (SIZE < n) SIZE <<= 1, ++HEIGHT;
        dat.assign(SIZE * 2, IDENTITY_MONOID);
        lazy.assign(SIZE * 2, IDENTITY_LAZY);
    }
    void init(int n, const FuncMonoid fm, const FuncAction fa, const FuncLazy fl,
              const Monoid &identity_monoid, const Action &identity_lazy) {
        FM = fm, FA = fa, FL = fl;
        IDENTITY_MONOID = identity_monoid, IDENTITY_LAZY = identity_lazy;
        SIZE = 1; HEIGHT = 0;
        while (SIZE < n) SIZE <<= 1, ++HEIGHT;
        dat.assign(SIZE * 2, IDENTITY_MONOID);
        lazy.assign(SIZE * 2, IDENTITY_LAZY);
    }
    
    // set, a is 0-indexed
    void set(int a, const Monoid &v) { dat[a + SIZE] = v; }
    void build() {
        for (int k = SIZE - 1; k > 0; --k)
            dat[k] = FM(dat[k*2], dat[k*2+1]);
    }
    
    // update [a, b)
    inline void evaluate(int k) {
        if (lazy[k] == IDENTITY_LAZY) return;
        if (k < SIZE) FL(lazy[k*2], lazy[k]), FL(lazy[k*2+1], lazy[k]);
        FA(dat[k], lazy[k]);
        lazy[k] = IDENTITY_LAZY;
    }
    inline void update(int a, int b, const Action &v, int k, int l, int r) {
        evaluate(k);
        if (a <= l && r <= b) FL(lazy[k], v), evaluate(k);
        else if (a < r && l < b) {
            update(a, b, v, k*2, l, (l+r)>>1);
            update(a, b, v, k*2+1, (l+r)>>1, r);
            dat[k] = FM(dat[k*2], dat[k*2+1]);
        }
    }
    inline void update(int a, int b, const Action &v) { 
        update(a, b, v, 1, 0, SIZE);
    }
    
    // get [a, b)
    inline Monoid get(int a, int b, int k, int l, int r) {
        evaluate(k);
        if (a <= l && r <= b)
            return dat[k];
        else if (a < r && l < b)
            return FM(get(a, b, k*2, l, (l+r)>>1), 
                      get(a, b, k*2+1, (l+r)>>1, r));
        else
            return IDENTITY_MONOID;
    }
    inline Monoid get(int a, int b) { 
        return get(a, b, 1, 0, SIZE);
    }
    inline Monoid operator [] (int a) {
        return get(a, a + 1);
    }
    
    // debug
    void print() {
        for (int i = 0; i < SIZE; ++i) {
            if (i) cout << ",";
            cout << (*this)[i];
        }
        cout << endl;
    }
};
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

  FormalPowerSeries(const vector< T > &v) : FormalPowerSeries(v.begin(), v.end()) {}

  P operator+(const P &r) const { return P(*this) += r; }

  P operator-(const P &r) const { return P(*this) -= r; }

  P operator*(const P &r) const { return P(*this) *= r; }

  P operator*(const T &v) const { return P(*this) *= v; }

  P operator/(const P &r) const { return P(*this) /= r; }

  P &operator+=(const P &r) {
    if(r.size() > this->size()) this->resize(r.size());
    for(int i = 0; i < r.size(); i++) (*this)[i] += r[i];
    return *this;
  }

  P &operator-=(const P &r) {
    if(r.size() > this->size()) this->resize(r.size());
    for(int i = 0; i < r.size(); i++) (*this)[i] -= r[i];
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
    auto ret = get_mult()(*this, r);
    this->resize(ret.size());
    for(int k = 0; k < ret.size(); k++) (*this)[k] = ret[k];
    return *this;
  }

  P operator-() const {
    P ret(this->size());
    for(int i = 0; i < this->size(); i++) ret[i] = -(*this)[i];
    return ret;
  }

  P &operator/=(const P &r) {
    return *this *= r.inverse();
  }

  P pre(int sz) const {
    return P(begin(*this), begin(*this) + min((int) this->size(), sz));
  }

  P rev() const {
    P ret(*this);
    reverse(begin(ret), end(ret));
    return ret;
  }

  P diff() const {
    const int n = (int) this->size();
    P ret(max(0, n - 1));
    for(int i = 1; i < n; i++) ret[i] = (*this)[i] * T(i);
    return ret;
  }

  P integral() const {
    const int n = (int) this->size();
    P ret(n + 1);
    ret[0] = T(0);
    for(int i = 0; i < n; i++) ret[i + 1] = (*this)[i] / T(i + 1);
  }

  // F(0) must not be 0
  P inv(int deg = -1) const {
    assert(((*this)[0]) != T(0));
    const int n = (int) this->size();
    if(deg == -1) deg = n;
    P ret({T(1) / (*this)[0]});
    for(int i = 1; i < deg; i <<= 1) {
      ret = (ret * T(2) - ret * ret * pre(i << 1)).pre(i << 1);
    }
    return ret.pre(deg);
  }

  // F(0) must be 1
  P log(int deg = -1) const {
    assert((*this)[0] == 1);
    const int n = (int) this->size();
    if(deg == -1) deg = n;
    return (this->diff() * this->inv(deg)).integral().pre(deg);
  }

  // F(0) must be 1
  P sqrt(int deg = -1) const {
    assert((*this)[0] == T(1));
    const int n = (int) this->size();
    if(deg == -1) deg = n;
    P ret({T(1)});
    T inv2 = T(1) / T(2);
    for(int i = 1; i < deg; i <<= 1) {
      ret = (ret + pre(i << 1) * ret.inv(i << 1)).pre(i << 1) * 2;
    }
    return ret.pre(deg);
  }

  // F(0) must be 0
  P exp(int deg) const {
    assert((*this)[0] == T(0));
    const int n = (int) this->size();
    P ret({T(1)}), g({T(1)});
    for(int i = 1; i < deg; i <<= 1) {
      ret = (ret * (pre(1 << i) + g) - ret.log(1 << i)).pre(1 << i);
    }
    return ret.pre(deg);
  }
};


namespace FastFourierTransform {
  using real = double;

  struct C {
    real x, y;

    C() : x(0), y(0) {}

    C(real x, real y) : x(x), y(y) {}

    inline C operator+(const C &c) const { return C(x + c.x, y + c.y); }

    inline C operator-(const C &c) const { return C(x - c.x, y - c.y); }

    inline C operator*(const C &c) const { return C(x * c.x - y * c.y, x * c.y + y * c.x); }

    inline C conj() const { return C(x, -y); }
  };

  const real PI = acosl(-1);
  int base = 1;
  vector< C > rts = {{0, 0},
                     {1, 0}};
  vector< int > rev = {0, 1};


  void ensure_base(int nbase) {
    if(nbase <= base) return;
    rev.resize(1 << nbase);
    rts.resize(1 << nbase);
    for(int i = 0; i < (1 << nbase); i++) {
      rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (nbase - 1));
    }
    while(base < nbase) {
      real angle = PI * 2.0 / (1 << (base + 1));
      for(int i = 1 << (base - 1); i < (1 << base); i++) {
        rts[i << 1] = rts[i];
        real angle_i = angle * (2 * i + 1 - (1 << base));
        rts[(i << 1) + 1] = C(cos(angle_i), sin(angle_i));
      }
      ++base;
    }
  }

  void fft(vector< C > &a, int n) {
    assert((n & (n - 1)) == 0);
    int zeros = __builtin_ctz(n);
    ensure_base(zeros);
    int shift = base - zeros;
    for(int i = 0; i < n; i++) {
      if(i < (rev[i] >> shift)) {
        swap(a[i], a[rev[i] >> shift]);
      }
    }
    for(int k = 1; k < n; k <<= 1) {
      for(int i = 0; i < n; i += 2 * k) {
        for(int j = 0; j < k; j++) {
          C z = a[i + j + k] * rts[j + k];
          a[i + j + k] = a[i + j] - z;
          a[i + j] = a[i + j] + z;
        }
      }
    }
  }

  vector< int64_t > multiply(const vector< int > &a, const vector< int > &b) {
    int need = (int) a.size() + (int) b.size() - 1;
    int nbase = 1;
    while((1 << nbase) < need) nbase++;
    ensure_base(nbase);
    int sz = 1 << nbase;
    vector< C > fa(sz);
    for(int i = 0; i < sz; i++) {
      int x = (i < (int) a.size() ? a[i] : 0);
      int y = (i < (int) b.size() ? b[i] : 0);
      fa[i] = C(x, y);
    }
    fft(fa, sz);
    C r(0, -0.25 / (sz >> 1)), s(0, 1), t(0.5, 0);
    for(int i = 0; i <= (sz >> 1); i++) {
      int j = (sz - i) & (sz - 1);
      C z = (fa[j] * fa[j] - (fa[i] * fa[i]).conj()) * r;
      fa[j] = (fa[i] * fa[i] - (fa[j] * fa[j]).conj()) * r;
      fa[i] = z;
    }
    for(int i = 0; i < (sz >> 1); i++) {
      C A0 = (fa[i] + fa[i + (sz >> 1)]) * t;
      C A1 = (fa[i] - fa[i + (sz >> 1)]) * t * rts[(sz >> 1) + i];
      fa[i] = A0 + A1 * s;
    }
    fft(fa, sz >> 1);
    vector< int64_t > ret(need);
    for(int i = 0; i < need; i++) {
      ret[i] = llround(i & 1 ? fa[i >> 1].y : fa[i >> 1].x);
    }
    return ret;
  }
};

template< typename T >
struct ArbitraryModConvolution {
  using real = FastFourierTransform::real;
  using C = FastFourierTransform::C;

  ArbitraryModConvolution() = default;

  vector< T > multiply(const vector< T > &a, const vector< T > &b, int need = -1) {
    if(need == -1) need = a.size() + b.size() - 1;
    int nbase = 0;
    while((1 << nbase) < need) nbase++;
    FastFourierTransform::ensure_base(nbase);
    int sz = 1 << nbase;
    vector< C > fa(sz);
    for(int i = 0; i < a.size(); i++) {
      fa[i] = C(a[i].x & ((1 << 15) - 1), a[i].x >> 15);
    }
    fft(fa, sz);
    vector< C > fb(sz);
    if(a == b) {
      fb = fa;
    } else {
      for(int i = 0; i < b.size(); i++) {
        fb[i] = C(b[i].x & ((1 << 15) - 1), b[i].x >> 15);
      }
      fft(fb, sz);
    }
    real ratio = 0.25 / sz;
    C r2(0, -1), r3(ratio, 0), r4(0, -ratio), r5(0, 1);
    for(int i = 0; i <= (sz >> 1); i++) {
      int j = (sz - i) & (sz - 1);
      C a1 = (fa[i] + fa[j].conj());
      C a2 = (fa[i] - fa[j].conj()) * r2;
      C b1 = (fb[i] + fb[j].conj()) * r3;
      C b2 = (fb[i] - fb[j].conj()) * r4;
      if(i != j) {
        C c1 = (fa[j] + fa[i].conj());
        C c2 = (fa[j] - fa[i].conj()) * r2;
        C d1 = (fb[j] + fb[i].conj()) * r3;
        C d2 = (fb[j] - fb[i].conj()) * r4;
        fa[i] = c1 * d1 + c2 * d2 * r5;
        fb[i] = c1 * d2 + c2 * d1;
      }
      fa[j] = a1 * b1 + a2 * b2 * r5;
      fb[j] = a1 * b2 + a2 * b1;
    }
    fft(fa, sz);
    fft(fb, sz);
    vector< T > ret(need);
    for(int i = 0; i < need; i++) {
      int64_t aa = llround(fa[i].x);
      int64_t bb = llround(fb[i].x);
      int64_t cc = llround(fa[i].y);
      aa = T(aa).x, bb = T(bb).x, cc = T(cc).x;
      ret[i] = aa + (bb << 15) + (cc << 30);
    }
    return ret;
  }
};


template< int mod >
struct ModInt {
  int x;

  ModInt() : x(0) {}

  ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}

  ModInt &operator+=(const ModInt &p) {
    if((x += p.x) >= mod) x -= mod;
    return *this;
  }

  ModInt &operator-=(const ModInt &p) {
    if((x += mod - p.x) >= mod) x -= mod;
    return *this;
  }

  ModInt &operator*=(const ModInt &p) {
    x = (int) (1LL * x * p.x % mod);
    return *this;
  }

  ModInt &operator/=(const ModInt &p) {
    *this *= p.inverse();
    return *this;
  }

  ModInt operator-() const { return ModInt(-x); }

  ModInt operator+(const ModInt &p) const { return ModInt(*this) += p; }

  ModInt operator-(const ModInt &p) const { return ModInt(*this) -= p; }

  ModInt operator*(const ModInt &p) const { return ModInt(*this) *= p; }

  ModInt operator/(const ModInt &p) const { return ModInt(*this) /= p; }

  bool operator==(const ModInt &p) const { return x == p.x; }

  bool operator!=(const ModInt &p) const { return x != p.x; }

  ModInt inverse() const {
    int a = x, b = mod, u = 1, v = 0, t;
    while(b > 0) {
      t = a / b;
      swap(a -= t * b, b);
      swap(u -= t * v, v);
    }
    return ModInt(u);
  }

  ModInt pow(int64_t n) const {
    ModInt ret(1), mul(x);
    while(n > 0) {
      if(n & 1) ret *= mul;
      mul *= mul;
      n >>= 1;
    }
    return ret;
  }

  friend ostream &operator<<(ostream &os, const ModInt &p) {
    return os << p.x;
  }

  friend istream &operator>>(istream &is, ModInt &a) {
    int64_t t;
    is >> t;
    a = ModInt< mod >(t);
    return (is);
  }
};

using modint = ModInt< mod >;
void solve(){
  ll n;
  cin>>n;
  vector<ll> a(n);
  vcin(a);
  map<ll,ll> m;
  ll ans=0;
  for(int i=0;i<n;i++){
    if(m[a[i]]==0){
      ans++;
      m[a[i]]++;
    }
    else if(m[a[i]+1]==0){
      ans++;
      m[a[i]+1]++;
    }
  }
  cout<<ans<<endl;
}
int main() {
  /* mod  1e9+7 */
  ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
  cout<< fixed << setprecision(10);
  ll a;
  cin>>a;
  for(int i=0;i<a;i++){
    solve();
  }
}