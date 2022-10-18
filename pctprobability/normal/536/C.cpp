#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
#if __has_include(<atcoder/all>)
#include <atcoder/all>
using namespace atcoder;
#endif
using ll = long long;
using ld = long double;
using ull = long long;
#define endl "\n"
#define double ld
typedef pair<int, int> Pii;
#define REP3(i, m, n) for (int i = (m); (i) < int(n); ++ (i))
#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define ALL(x) begin(x), end(x)
#define all(s) (s).begin(),(s).end()
//#define rep2(i, m, n) for (int i = (m); i < (n); ++i)
//#define rep(i, n) rep2(i, 0, n)
#define PB push_back 
#define drep2(i, m, n) for (int i = (m)-1; i >= (n); --i)
#define drep(i, n) drep2(i, n, 0)
#define rever(vec) reverse(vec.begin(), vec.end())
#define sor(vec) sort(vec.begin(), vec.end())
//#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define fi first
#define se second
#define pb push_back
//#define P pair<ll,ll>
#define NP next_permutation
//const ll mod = 1000000009;
//const ll mod = 998244353;
const ll mod = 1000000007;
const ll inf = 9100000000000000000ll;
const ld eps = ld(0.0000000000001);
//static const long double pi = 3.141592653589793;
template<class T>void vcin(vector<T> &n){for(int i=0;i<int(n.size());i++) cin>>n[i];}
template<class T,class K>void vcin(vector<T> &n,vector<K> &m){for(int i=0;i<int(n.size());i++) cin>>n[i]>>m[i];}
template<class T>void vcout(vector<T> &n){for(int i=0;i<int(n.size());i++){cout<<n[i]<<" ";}cout<<endl;}
template<class T>void vcin(vector<vector<T>> &n){for(int i=0;i<int(n.size());i++){for(int j=0;j<int(n[i].size());j++){cin>>n[i][j];}}}
template<class T>void vcout(vector<vector<T>> &n){for(int i=0;i<int(n.size());i++){for(int j=0;j<int(n[i].size());j++){cout<<n[i][j]<<" ";}cout<<endl;}cout<<endl;}
void yes(bool a){cout<<(a?"yes":"no")<<endl;}
void YES(bool a){cout<<(a?"YES":"NO")<<endl;}
void Yes(bool a){cout<<(a?"Yes":"No")<<endl;}
void possible(bool a){ cout<<(a?"possible":"impossible")<<endl; }
void Possible(bool a){ cout<<(a?"Possible":"Impossible")<<endl; }
void POSSIBLE(bool a){ cout<<(a?"POSSIBLE":"IMPOSSIBLE")<<endl; }
template<class T>auto min(const T& a){ return *min_element(all(a)); }
template<class T>auto max(const T& a){ return *max_element(all(a)); }
template<class T,class F>void print(pair<T,F> a){cout<<a.fi<<" "<<a.se<<endl;}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0;}
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0;}
template<class T> void ifmin(T t,T u){if(t>u){cout<<-1<<endl;}else{cout<<t<<endl;}}
template<class T> void ifmax(T t,T u){if(t>u){cout<<-1<<endl;}else{cout<<t<<endl;}}
template<typename T,typename ...Args>auto make_vector(T x,int arg,Args ...args){if constexpr(sizeof...(args)==0)return vector<T>(arg,x);else return vector(arg,make_vector<T>(x,args...));}
ll modPow(ll a, ll n, ll mod) { if(mod==1) return 0;ll ret = 1; ll p = a % mod; while (n) { if (n & 1) ret = ret * p % mod; p = p * p % mod; n >>= 1; } return ret; }
vector<ll> divisor(ll x){ vector<ll> ans; for(ll i = 1; i * i <= x; i++){ if(x % i == 0) {ans.push_back(i); if(i*i!=x){ ans.push_back(x / ans[i]);}}}sor(ans); return ans; }
ll pop(ll a){ll res=0;while(a){res+=a%2;a/=2;}return res;}
template<class T>
struct Sum{
  vector<T> data;
  Sum(const vector<T>& v):data(v.size()+1){
    for(ll i=0;i<v.size();i++) data[i+1]=data[i]+v[i];
  }
  T get(ll l,ll r) const {
    return data[r]-data[l];
  }
};
template<class T>
struct Sum2{
  vector<vector<T>> data;
  Sum2(const vector<vector<T>> &v):data(v.size()+1,vector<T>(v[0].size()+1)){
    for(int i=0;i<v.size();i++) for(int j=0;j<v[i].size();j++) data[i+1][j+1]=data[i][j+1]+v[i][j];
    for(int i=0;i<v.size();i++) for(int j=0;j<v[i].size();j++) data[i+1][j+1]+=data[i+1][j];
  }
  T get(ll x1,ll y1,ll x2,ll y2) const {
    return data[x2][y2]+data[x1][y1]-data[x1][y2]-data[x2][y1];
  }
};
 
void cincout(){
  ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
  cout<< fixed << setprecision(6);
}
const double EPS = 1e-20, PI = acos(-1);
inline bool eq(double a,double b){ return abs(b - a) < EPS; }
#define curr(P,i) P[i]
#define next(P,i) P[(i+1)%P.size()]
#define prev(P,i) P[(i+P.size()-1) % P.size()]
enum { OUT, ON, IN };
  
struct Geometory { // Geometory Library
  struct Point {
    double x, y;
    Point(){};
    Point(double x,double y):x(x),y(y){};
    Point operator+(const Point& b) const { return Point(x + b.x,y + b.y); }
    Point operator-(const Point& b) const { return Point(x - b.x,y - b.y); }
    Point operator*(const double b) const { return Point(x * b,y * b); }
    Point operator*(const Point& b) const { return Point(x * b.x - y * b.y,x * b.y + y * b.x); }
    Point operator/(const double b) const { return Point(x / b,y / b); }
    bool operator< (const Point& b) const { return x != b.x ? x < b.x : y < b.y;}
    bool operator==(const Point& b) const { return eq(x,b.x) && eq(y,b.y); }
    double norm(){ return x * x + y * y; }
    double arg(){ return atan2(x,y); }
    double abs(){ return sqrt(norm()); }
    Point rotate(double theta){ return Point(cos(theta) * x - sin(theta) * y,sin(theta) * x + cos(theta) * y); }
    Point rotate90(){ return Point(-y,x); }
    friend ostream& operator<<(ostream& os, Point& p){ return os<<"("<<p.x<<","<<p.y<<")"; }
    friend istream& operator>>(istream& is, Point& a){ return is>>a.x>>a.y; }
  };
  
  struct Line {
    Point a, b;
    Line(){};
    Line(Point a,Point b):a(a),b(b){};
    friend ostream& operator<<(ostream& os, Line& p){ return os<<"("<<p.a.x<<","<<p.a.y<<") to ("<<p.b.x<<","<<p.b.y<<")"; }
    friend istream& operator>>(istream& is, Line& a){ return is>>a.a.x>>a.a.y>>a.b.x>>a.b.y; }
  };
  struct Segment {
    Point a, b;
    Segment(){};
    Segment(Point a,Point b):a(a),b(b){};
    friend ostream& operator<<(ostream& os, Segment& p){ return os<<"("<<p.a.x<<","<<p.a.y<<") to ("<<p.b.x<<","<<p.b.y<<")"; }
    friend istream& operator>>(istream& is, Segment& a){ return is>>a.a.x>>a.a.y>>a.b.x>>a.b.y; }
  };
  struct Circle {
    Point p; double r;
    Circle(){};
    Circle(Point p, double r) : p(p),r(r){};
  };
  typedef vector< Point > Polygon;
  typedef vector< Segment > Segments;
  typedef vector< Line > Lines;
  typedef vector< Circle > Circles;
  typedef pair< Point, Point > PointPoint;
  
  double cross(const Point& a,const Point& b){
    return a.x * b.y - a.y * b.x;
  }
  double dot(const Point& a,const Point& b){
    return a.x * b.x + a.y * b.y;
  }
  
  int ccw(const Point& a,Point b,Point c){
    b = b - a, c = c - a;
    if(cross(b,c) > EPS)    return +1;  // a  b   c
    if(cross(b,c) < -EPS)    return -1; // a  b   c
    if(dot(b,c) < 0)      return +2;  // c -- a -- b
    if(b.norm() < c.norm()) return -2; // a -- b -- c
    return 0;  // a -- c -- b
  }
  Point Projection(const Line& l, const Point& p){
    double t = dot( p - l.a, l.a - l.b) / (l.a - l.b).norm();
    return l.a + (l.a - l.b) * t;
  }
  Point Projection(const Segment& l, const Point& p){
    double t = dot( p - l.a, l.a - l.b) / (l.a - l.b).norm();
    return l.a + (l.a - l.b) * t;
  }
  Point Reflection(const Line& l, const Point& p){
    return p + (Projection( l, p) - p) * 2.0;
  }
  
  double Distance( const Line& l,const Point& p) { //OK
    return (p - Projection( l, p)).abs();
  }
  
  bool Intersect(const Line& l, const Line& m){
    return abs(cross(l.b - l.a, m.b - m.a)) > EPS || abs(cross(l.b-l.a, m.b-l.a)) < EPS;
  }
  bool Intersect(const Line& l, const Segment& s){
    return cross( l.b - l.a, s.a - l.a) * cross( l.b - l.a, s.b - l.a) < EPS;
  }
  bool Intersect(const Line& l, const Point& p){
    return abs(ccw(l.a, l.b, p)) != -1;
  }
  bool Intersect(Segment s, Segment t){
    return ccw(s.a, s.b, t.a) * ccw(s.a, s.b, t.b) <= 0 && ccw(t.a, t.b, s.a) * ccw(t.a, t.b, s.b) <= 0;
  }
  bool Intersect(const Segment& s, const Point& p){
    return ccw(s.a, s.b, p) == 0;
  }
  bool Intersect(const Circle& c,const Line& l){
    return Distance( l, c.p) <= c.r + EPS;
  }
  bool Intersect(const Circle& c,const Point& p){
    return abs( ( p - c.p).abs() - c.r ) < EPS;
  }
  int Intersect(const Circle& c, const Segment& l){
    if( (Projection( l, c.p) - c.p).norm() - c.r * c.r > EPS) return 0;
    const double d1 = ( c.p - l.a).abs(), d2 = ( c.p - l.b).abs();
    if( d1 < c.r + EPS && d2 < c.r + EPS) return 0;
    if( d1 < c.r - EPS && d2 > c.r + EPS || d1 > c.r + EPS && d2 < c.r - EPS ) return 1;
    const Point h = Projection( l, c.p);
    if( dot( l.a - h, l.b - h) < 0) return 2;
    return 0;
  }
  bool Intersect(const Circle& a,const Circle& b){
    return ( ( a.p - b.p).norm() - ( a.r + b.r) * ( a.r + b.r) < EPS) &&
      ( ( a.p - b.p).norm() - ( a.r - b.r) * ( a.r - b.r) > -EPS);
  }
  double Distance(const Segment& s,const Point& p){
    Point r = Projection(s, p);
    if ( Intersect( s, r)) return ( r - p).abs();
    return min( ( s.a - p).abs(), ( s.b - p).abs());
  }
  double Distance(const Segment& a,const Segment& b){
    if(Intersect( a, b)) return 0;
    return min( min( Distance( a, b.a), Distance( a, b.b)), min( Distance( b, a.a), Distance( b, a.b)));
  }
  double Distance(const Line& l,const Line& m) {
    return Intersect( l, m) ? 0 : Distance( l, m.a);
  }
  double Distance(const Line& l,const Segment& s) { //OK
    if (Intersect(l, s)) return 0;
    return min(Distance(l, s.a), Distance(l, s.b));
  }
  double Distance(const Point& a,const Point& b){ //OK
    return ( a - b).abs();
  }
  Point Crosspoint(const Segment& l,const Segment& m) { //OK
    double A = cross(l.b - l.a, m.b - m.a);
    double B = cross(l.b - l.a, l.b - m.a);
    if (abs(A) < EPS && abs(B) < EPS) return m.a; // same line
    return m.a + (m.b - m.a) * B / A;
  }
  PointPoint Crosspoint(const Circle& c,const Line l){
    Point hp = Projection( l, c.p), h =  hp - c.p;
    const double d2 = h.norm();
    Point v = ( l.b - l.a) * sqrt( c.r * c.r - d2) / ( l.b - l.a).abs();
    return PointPoint(hp - v, hp + v);
  }
  PointPoint Crosspoint(const Circle& c,const Segment& l) {
    Line aa = Line( l.a, l.b);
    if(Intersect(c, l) == 2) return Crosspoint(c, aa);
    PointPoint ret = Crosspoint(c, aa);
    if(dot(l.a - ret.first, l.b - ret.first) < 0) ret.second = ret.first;
    else ret.first = ret.second;
    return ret;
  }
  PointPoint Crosspoint(const Circle& c1,const Circle& c2){ //OK
    double d = (c1.p - c2.p).abs();
    double s = (c1.r + c2.r + d) / 2;
    double S = sqrt( s * ( s - c1.r) * ( s - c2.r) * ( s - d));
    double h = 2 * S / d;
    Point v = ( c2.p - c1.p) / ( c2.p - c1.p).abs();
    double m = sqrt( c1.r * c1.r - h * h);
    return PointPoint( c1.p + v * m + Point(0,1) * h * v, c1.p + v * m - Point(0,1) * h * v);
  }
  bool parallel(const Line& a,const Line& b){
    return abs(cross( a.b - a.a, b.b - b.a)) < EPS;
  }
  bool orthogonal(const Line& a,const Line& b){
    return abs(dot( a.a - a.b, b.a - b.b)) < EPS;
  }
  int Contains(const Polygon& Q,const Point& p){
    bool in = false;
    for(int i = 0 ; i < Q.size() ; i++ ){
      Point a = curr(Q,i) - p, b = next(Q,i) - p;
      if(a.y > b.y) swap(a,b);
      if(a.y <= 0 && 0 < b.y && cross(a,b) < 0) in = !in;
      if(cross(a,b) == 0 && dot(a,b) <= 0) return ON;
    }
    return in ? IN : OUT;
  }
  bool Contains(const Circle& c,const Point& p){
    return ( c.p - p).abs() < c.r + EPS;
  }
  double Area2(const Polygon& p){ //OK
    double A = 0;
    for (int i = 0; i < p.size(); ++i){
      A += cross(curr(p, i), next(p, i));
    }
    return A;
  }
  bool IsConvex(const Polygon& p){
    for(int i = 0; i < p.size(); i++){
      if(ccw(prev(p,i),curr(p,i),next(p,i)) == -1) return false;
    }
    return true;
  }
  Polygon Convex_Hull(Polygon& p){
  int n = p.size(), k = 0;
  if(n >= 3){
    sort(p.begin(), p.end());
    vector< Point > ch(2 * n);
   // cout<<k<<endl;
    for(int i = 0; i < n; ch[k++] = p[i++]){
   //   cout<<ch[k-2].x<<" "<<ch[k-2].y<<" "<<cross(ch[k - 1] - ch[k - 2], p[i] - ch[k - 1])<<" "<<int(cross(ch[k - 1] - ch[k - 2], p[i] - ch[k - 1])<=0)<<endl;
      while(k >= 2 &&( cross(ch[k - 1] - ch[k - 2], p[i] - ch[k - 1]) <=0)){
      //  cout<<cross(ch[k-1]-ch[k-2],p[i]-ch[k-1])<<endl;
        --k;
      }
    }
  //  cout<<k<<endl;
    for(int i = n - 2, t = k + 1; i >= 0; ch[k++] = p[i--]){
    //  cout<<cross(ch[k - 1] - ch[k - 2], p[i] - ch[k - 1])<<endl;
      while(k >= t && cross(ch[k - 1] - ch[k - 2], p[i] - ch[k - 1]) <= 0){
        --k;
       //  cout<<cross(ch[k-1]-ch[k-2],p[i]-ch[k-1])<<endl;
      }
    }
   // cout<<k<<endl;
    ch.resize(k - 1);
    return ch;
  } else {
    return p;
  }
  }
};

Geometory geo;
typedef Geometory::Point P;
typedef Geometory::Line L;
typedef Geometory::Segment S;
typedef Geometory::Circle C;
int main() {
  cincout();
  ll n;
  cin>>n;
  map<pair<double,double>,ll> m;
  map<pair<double,double>,vector<ll>> mm;
  vector<ll> k={14034, 28469, 48747, 51162, 105995 ,106984, 129798, 134880 ,136414 ,150082 ,175766 };
  ll tyo=0;
  for(int i=0;i<n;i++){
    ll x,y;
    cin>>x>>y;
    if(m[{-10000000.0/ld(y),10000000.0/ld(x)}]==0){
      tyo++;
      m[{-10000000.0/ld(y),10000000.0/ld(x)}]=i+1;
      mm[{-10000000.0/ld(y),10000000.0/ld(x)}].pb(i+1);
    }
    else{
      mm[{-10000000.0/ld(y),10000000.0/ld(x)}].pb(i+1);
    }
   // cout<<"{"<<-10000000.0/ld(y)<<" "<<10000000.0/ld(x)<<"}"<<endl;
  }
  Geometory::Polygon p(tyo);
  ll now=0;
  for(auto e:m){
    Geometory::Point x(e.fi.fi,e.fi.se);
    p[now]=x;
    now++;
  }
  p=geo.Convex_Hull(p);
  map<ll,ll> ans;
 // cout<<p.size()<<endl;
  if(p.size()<=2){
    vector<ll> solve;
    for(int i=0;i<int(p.size());i++){
      auto e=p[i];
      ans[m[{e.x,e.y}]]++;
      for(auto E:mm[{e.x,e.y}]){
        solve.pb(E);
      }
    }
    sor(solve);
    for(auto e:solve) cout<<e<<" ";
    return 0;
  }
  ll q=p.size();
  Geometory::Point X;
  X.x=0,X.y=0;
  vector<ll> solve;
  for(int i=0;i<int(p.size());i++){
    auto e=p[i];
    bool FF=true;
    for(int j=0;j<int(p.size());j++){
     if(p[i]==p[j]) continue;
     if(p[i].x<=p[j].x&&p[i].y>=p[j].y) FF=false;
    }
   if(p.size()<=10){ for(int j=0;j<int(p.size());j++){
     if(i==j||(j+1)%q==i) continue;
      auto f=p[j],g=p[(j+1)%q];
      Geometory::Segment F,G;
      F.a=f,F.b=g;
      G.a=X,G.b=e;
      if((geo.Intersect(F,G))) FF=false;
    }
                   }
    if(FF){
    //  cout<<"K"<<endl;
    //  cout<<e.x<<" "<<e.y<<" "<<mm[{e.x,e.y}].size()<<endl;
      for(auto E:mm[{e.x,e.y}]){
     //   cout<<"E"<<" "<<E<<endl;
        solve.pb(E);
      }
    }
  }
  sor(solve);
  for(auto e:solve) cout<<e<<" ";
}