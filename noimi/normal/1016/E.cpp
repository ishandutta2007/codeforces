#pragma region Macros
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
#define ld long double
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
#define vecpll vector<pll>
#define vec2(a,b) vector<vec>(a,vec(b))
#define vec2ll(a,b) vector<vecll>(a,vecll(b))
#define vec3(a,b,c) vector<vector<vec>>(a,vec2(b,c))
#define vec3ll(a,b,c) vector<vector<vecll>>(a,vec2ll(b,c))
#define fi first
#define se second
#define all(c) begin(c),end(c)
#define ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(c,x) distance((c).begin(),lower_bound(all(c),(x)))
#define ub(c,x) distance((c).begin(),upper_bound(all(c),(x)))
using namespace std;
int in() {int x;cin>>x;return x;}
ll lin() {unsigned long long x;cin>>x;return x;}
string stin() {string s;cin>>s;return s;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
vec iota(int n){vec a(n);iota(all(a),0);return a;}
void print(){putchar(' ');}
void print(bool a){cout<<a;}
void print(int a){cout<<a;}
void print(long long a){cout<<a;}
void print(char a){cout<<a;}
void print(string &a){cout<<a;}
void print(double a){cout<<a;}
template<class T> void print(const vector<T>&);
template<class T, size_t size> void print(const array<T, size>&);
template<class T, class L> void print(const pair<T, L>& p);
template<class T, size_t size> void print(const T (&)[size]);
template<class T> void print(const vector<T>& a){ if(a.empty()) return; print(a[0]); for(auto i = a.begin(); ++i != a.end(); ){ cout<<" "; print(*i); } cout<<endl;}
template<class T> void print(const deque<T>& a){ if(a.empty()) return; print(a[0]); for(auto i = a.begin(); ++i != a.end(); ){ cout<<" "; print(*i); } }
template<class T, size_t size> void print(const array<T, size>& a){ print(a[0]); for(auto i = a.begin(); ++i != a.end(); ){ cout<<" "; print(*i); } }
template<class T, class L> void print(const pair<T, L>& p){ cout<<'(';print(p.first); cout<<","; print(p.second);cout<<')'; }
template<class T, size_t size> void print(const T (&a)[size]){ print(a[0]); for(auto i = a; ++i != end(a); ){ cout<<" "; print(*i); } }
template<class T> void print(const T& a){ cout << a; }
int out(){ putchar('\n'); return 0; }
template<class T> int out(const T& t){ print(t); putchar('\n'); return 0; }
template<class Head, class... Tail> int out(const Head& head, const Tail&... tail){ print(head); putchar(' '); out(tail...); return 0; }
ll gcd(ll a, ll b){ while(b){ ll c = b; b = a % b; a = c; } return a; }
ll lcm(ll a, ll b){ if(!a || !b) return 0; return a * b / gcd(a, b); }
vector<pll> factor(ll x){ vector<pll> ans; for(ll i = 2; i * i <= x; i++) if(x % i == 0){ ans.push_back({i, 1}); while((x /= i) % i == 0) ans.back().second++; } if(x != 1) ans.push_back({x, 1}); return ans; }
vector<int> divisor(int x){ vector<int> ans; for(int i=1;i*i<=x;i++)if(x%i==0){ans.pb(i);if(i*i!=x)ans.pb(x/i);} return ans;}
int popcount(ll x){return __builtin_popcountll(x);}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int n){return uniform_int_distribution<int>(0, n)(rng);}
// #define _GLIBCXX_DEBU
#define endl '\n'
#ifdef _MY_DEBUG
    #undef endl
    #define debug(x) cout<<#x<<": "<<x<<endl
    void err(){}
    template<class T> void err(const T& t){ print(t);  cout<<" ";}
    template<class Head, class... Tail> void err(const Head& head, const Tail&... tail){ print(head); putchar(' '); out(tail...); }
#else
    #define debug(x)
    template<class... T> void err(const T&...){}
#endif
#pragma endregion

using Real = double;
using Point = complex< Real >;
const Real EPS = 1e-8, PI = acos(-1);

inline bool eq(Real a, Real b) { return fabs(b - a) < EPS; }

Point operator*(const Point &p, const Real &d) {
  return Point(real(p) * d, imag(p) * d);
}

istream &operator>>(istream &is, Point &p) {
  Real a, b;
  is >> a >> b;
  p = Point(a, b);
  return is;
}

ostream &operator<<(ostream &os, Point &p) {
  return os << fixed << setprecision(10) << p.real() << " " << p.imag();
}

//  p  theta 
Point rotate(Real theta, const Point &p) {
  return Point(cos(theta) * p.real() - sin(theta) * p.imag(), sin(theta) * p.real() + cos(theta) * p.imag());
}

Real radian_to_degree(Real r) {
  return (r * 180.0 / PI);
}

Real degree_to_radian(Real d) {
  return (d * PI / 180.0);
}

// a-b-c 
Real get_angle(const Point &a, const Point &b, const Point &c) {
  const Point v(b - a), w(c - b);
  Real alpha = atan2(v.imag(), v.real()), beta = atan2(w.imag(), w.real());
  if(alpha > beta) swap(alpha, beta);
  Real theta = (beta - alpha);
  return min(theta, 2 * acos(-1) - theta);
}

namespace std {
  bool operator<(const Point &a, const Point &b) {
    return a.real() != b.real() ? a.real() < b.real() : a.imag() < b.imag();
  }
}


struct Line {
  Point a, b;

  Line() = default;

  Line(Point a, Point b) : a(a), b(b) {}

  Line(Real A, Real B, Real C) // Ax + By = C
  {
    if(eq(A, 0)) a = Point(0, C / B), b = Point(1, C / B);
    else if(eq(B, 0)) b = Point(C / A, 0), b = Point(C / A, 1);
    else a = Point(0, C / B), b = Point(C / A, 0);
  }

  friend ostream &operator<<(ostream &os, Line &p) {
    return os << p.a << " to " << p.b;
  }

  friend istream &operator>>(istream &is, Line &a) {
    return is >> a.a >> a.b;
  }
};

struct Segment : Line {
  Segment() = default;

  Segment(Point a, Point b) : Line(a, b) {}
};

struct Circle {
  Point p;
  Real r;

  Circle() = default;

  Circle(Point p, Real r) : p(p), r(r) {}
};

using Points = vector< Point >;
using Polygon = vector< Point >;
using Segments = vector< Segment >;
using Lines = vector< Line >;
using Circles = vector< Circle >;

Real cross(const Point &a, const Point &b) {
  return real(a) * imag(b) - imag(a) * real(b);
}

Real dot(const Point &a, const Point &b) {
  return real(a) * real(b) + imag(a) * imag(b);
}

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_C
// 
int ccw(const Point &a, Point b, Point c) {
  b = b - a, c = c - a;
  if(cross(b, c) > EPS) return +1;  // "COUNTER_CLOCKWISE"
  if(cross(b, c) < -EPS) return -1; // "CLOCKWISE"
  if(dot(b, c) < 0) return +2;      // "ONLINE_BACK"
  if(norm(b) < norm(c)) return -2;  // "ONLINE_FRONT"
  return 0;                         // "ON_SEGMENT"
}

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_A
// 
bool parallel(const Line &a, const Line &b) {
  return eq(cross(a.b - a.a, b.b - b.a), 0.0);
}

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_A
// 
bool orthogonal(const Line &a, const Line &b) {
  return eq(dot(a.a - a.b, b.a - b.b), 0.0);
}

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_A
// 
//  l  p 
Point projection(const Line &l, const Point &p) {
  double t = dot(p - l.a, l.a - l.b) / norm(l.a - l.b);
  return l.a + (l.a - l.b) * t;
}

Point projection(const Segment &l, const Point &p) {
  double t = dot(p - l.a, l.a - l.b) / norm(l.a - l.b);
  return l.a + (l.a - l.b) * t;
}

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_B
// 
//  l  p  
Point reflection(const Line &l, const Point &p) {
  return p + (projection(l, p) - p) * 2.0;
}

bool intersect(const Line &l, const Point &p) {
  return abs(ccw(l.a, l.b, p)) != 1;
}

bool intersect(const Line &l, const Line &m) {
  return abs(cross(l.b - l.a, m.b - m.a)) > EPS || abs(cross(l.b - l.a, m.b - l.a)) < EPS;
}

bool intersect(const Segment &s, const Point &p) {
  return ccw(s.a, s.b, p) == 0;
}

bool intersect(const Line &l, const Segment &s) {
  return cross(l.b - l.a, s.a - l.a) * cross(l.b - l.a, s.b - l.a) < EPS;
}

Real distance(const Line &l, const Point &p);

bool intersect(const Circle &c, const Line &l) {
  return distance(l, c.p) <= c.r + EPS;
}

bool intersect(const Circle &c, const Point &p) {
  return abs(abs(p - c.p) - c.r) < EPS;
}

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_B
bool intersect(const Segment &s, const Segment &t) {
  return ccw(s.a, s.b, t.a) * ccw(s.a, s.b, t.b) <= 0 && ccw(t.a, t.b, s.a) * ccw(t.a, t.b, s.b) <= 0;
}

int intersect(const Circle &c, const Segment &l) {
  if(norm(projection(l, c.p) - c.p) - c.r * c.r > EPS) return 0;
  auto d1 = abs(c.p - l.a), d2 = abs(c.p - l.b);
  if(d1 < c.r + EPS && d2 < c.r + EPS) return 0;
  if(d1 < c.r - EPS && d2 > c.r + EPS || d1 > c.r + EPS && d2 < c.r - EPS) return 1;
  const Point h = projection(l, c.p);
  if(dot(l.a - h, l.b - h) < 0) return 2;
  return 0;
}

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_A&lang=jp
int intersect(Circle c1, Circle c2) {
  if(c1.r < c2.r) swap(c1, c2);
  Real d = abs(c1.p - c2.p);
  if(c1.r + c2.r < d) return 4;
  if(eq(c1.r + c2.r, d)) return 3;
  if(c1.r - c2.r < d) return 2;
  if(eq(c1.r - c2.r, d)) return 1;
  return 0;
}

Real distance(const Point &a, const Point &b) {
  return abs(a - b);
}

Real distance(const Line &l, const Point &p) {
  return abs(p - projection(l, p));
}

Real distance(const Line &l, const Line &m) {
  return intersect(l, m) ? 0 : distance(l, m.a);
}

Real distance(const Segment &s, const Point &p) {
  Point r = projection(s, p);
  if(intersect(s, r)) return abs(r - p);
  return min(abs(s.a - p), abs(s.b - p));
}

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_D
Real distance(const Segment &a, const Segment &b) {
  if(intersect(a, b)) return 0;
  return min({distance(a, b.a), distance(a, b.b), distance(b, a.a), distance(b, a.b)});
}

Real distance(const Line &l, const Segment &s) {
  if(intersect(l, s)) return 0;
  return min(distance(l, s.a), distance(l, s.b));
}

Point crosspoint(const Line &l, const Line &m) {
  Real A = cross(l.b - l.a, m.b - m.a);
  Real B = cross(l.b - l.a, l.b - m.a);
  if(eq(abs(A), 0.0) && eq(abs(B), 0.0)) return m.a;
  return m.a + (m.b - m.a) * B / A;
}

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_C
Point crosspoint(const Segment &l, const Segment &m) {
  return crosspoint(Line(l), Line(m));
}


signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);cout<<fixed<<setprecision(15);
    int sy=in(),a=in(),b=in();
    Point left(a,sy),right(b,sy);
    int n=in();
    Real len = b-a;
    vector<pair<Real,Real>> v;rep(i,n){int x=in(),y=in();v.eb(x,y);}
    vector<double> rui(n+1);
    rep(i,n)rui[i+1]+=rui[i]+v[i].se-v[i].fi;
    int q=in();
    Line y0(Point(0,0),Point(1,0));
    while(q--){
        int x=in(),y=in();
        Point now(x,y);
        Line A(now,left),B(now,right);
        Point T = crosspoint(A,y0),S=crosspoint(B,y0);
        double t = T.real(),s=S.real();
        using P = pair<Real,Real>;
        P TT = {t,1e18},SS={s,1e18};
        int tnum = lb(v,TT),snum=lb(v,SS);
        if(snum==-1){
            cout<<0<<endl;
        }
        else{
            double ans = rui[snum]-rui[tnum];
            if(tnum and v[tnum-1].se>t) ans+=v[tnum-1].se-t;
            if(snum and v[snum-1].se>s) ans-=v[snum-1].se-s;
            cout<<ans*(y-sy)/y<<endl;
        }
    }


}