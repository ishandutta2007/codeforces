#include<vector>
#include<list>
#include<map>
#include<set>
#include<deque>
#include<queue>
#include<stack>
#include<bitset>
#include<algorithm>
#include<functional>
#include<numeric>
#include<utility>
#include<iostream>
#include<sstream>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cctype>
#include<string>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<climits>
#include<complex>
using namespace std;

#define xx         first
#define yy         second
#define pb         push_back
#define mp         make_pair
#define LL         long long
#define inf        INT_MAX/3
#define mod        998244353ll
#define PI         acos(-1.0)
#define linf       (1ll<<60)-1
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     ((A).begin(), (A).end())
#define set0(ar)   memset(ar,0,sizeof ar)
#define vsort(v)   sort(v.begin(),v.end())
#define setinf(ar) memset(ar,126,sizeof ar)

//cout << fixed << setprecision(20) << p << endl;

template <class T> inline T bigmod(T p,T e,T M){
    LL ret = 1;
    for(; e > 0; e >>= 1){
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    }
    return (T)ret;
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}

const double EPS = 1E-9;
 
struct pt {
	double x, y;

  pt(){}
  pt(double _x, double _y){
    x = _x; y = _y;
  }
};
 
struct seg {
	pt p, q;
	int id;

  seg(){}
  seg(pt a, pt b, int i){
    p = a; q = b; id = i;
  }
 
	double get_y(double x) const {
		if (abs(p.x - q.x) < EPS)  return p.y;
		return p.y + (q.y - p.y) * (x - p.x) / (q.x - p.x);
	}
};
 
 
inline bool intersect1d(double l1, double r1, double l2, double r2) {
	if (l1 > r1)  swap(l1, r1);
	if (l2 > r2)  swap(l2, r2);
	return max(l1, l2) <= min(r1, r2) + EPS;
}
 
inline int vec(const pt & a, const pt & b, const pt & c) {
	double s = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
	return abs(s) < EPS ? 0 : s > 0 ? +1 : -1;
}
 
bool intersect(const seg & a, const seg & b) {
	return intersect1d(a.p.x, a.q.x, b.p.x, b.q.x)
		&& intersect1d(a.p.y, a.q.y, b.p.y, b.q.y)
		&& vec(a.p, a.q, b.p) * vec(a.p, a.q, b.q) <= 0
		&& vec(b.p, b.q, a.p) * vec(b.p, b.q, a.q) <= 0;
}
 
 
bool operator< (const seg & a, const seg & b) {
	double x = max(min(a.p.x, a.q.x), min(b.p.x, b.q.x));
	return a.get_y(x) < b.get_y(x) - EPS;
}
 
 
struct event {
	double x;
	int tp, id;
 
	event() { }
	event(double x, int tp, int id)
		: x(x), tp(tp), id(id)
	{ }
 
	bool operator< (const event & e) const {
		if (abs(x - e.x) > EPS)  return x < e.x;
		return tp > e.tp;
	}
};

set<seg> s;
vector < set<seg>::iterator > where;
 
inline set<seg>::iterator prev(set<seg>::iterator it) {
	return it == s.begin() ? s.end() : --it;
}
 
inline set<seg>::iterator next(set<seg>::iterator it) {
	return ++it;
}
 
pair<int, int> findIntersection(const vector<seg> & a) {
 
	int n = (int)a.size();
	vector<event> e;
	for (int i = 0; i < n; ++i) {
		e.push_back(event(min(a[i].p.x, a[i].q.x), +1, i));
		e.push_back(event(max(a[i].p.x, a[i].q.x), -1, i));
	}
	sort(e.begin(), e.end());
 
	s.clear();
	where.resize(a.size());
	for (size_t i = 0; i < e.size(); ++i) {
		int id = e[i].id;
		if (e[i].tp == +1) {
			set<seg>::iterator
				nxt = s.lower_bound(a[id]),
				prv = prev(nxt);
			if (nxt != s.end() && intersect(*nxt, a[id]))
				return make_pair(nxt->id, id);
			if (prv != s.end() && intersect(*prv, a[id]))
				return make_pair(prv->id, id);
			where[id] = s.insert(nxt, a[id]);
		}
		else {
			set<seg>::iterator
				nxt = next(where[id]),
				prv = prev(where[id]);
			if (nxt != s.end() && prv != s.end() && intersect(*nxt, *prv))
				return make_pair(prv->id, nxt->id);
			s.erase(where[id]);
		}
	}
 
	return make_pair(-1, -1);
}

int ar[25555][5];
vector < seg > vc;

double pp[25555][4];

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n = 4; cin >> n;
  REP(i, n) REP(j, 5) cin >> ar[i][j];
  REP(i, n){
    pp[i][0] = ar[i][0];
    pp[i][1] = ar[i][1];
    double d = hypot(ar[i][2], ar[i][3]);
    pp[i][2] = (double)ar[i][2] * (double)ar[i][4] / d;
    pp[i][3] = (double)ar[i][3] * (double)ar[i][4] / d;
  }
  
  double lo = 0, hi = 1e14;
  REP(i, 70){
    double t = (lo + hi) / 2.0;
    vc.clear();
    REP(i, n){
      //cout << pp[i][0] << " " << pp[i][1] << " " << pp[i][0] + t * pp[i][2] << " " << pp[i][1] + t * pp[i][3] << endl;
      vc.pb(seg(pt(pp[i][0], pp[i][1]), pt(pp[i][0] + t * pp[i][2], pp[i][1] + t * pp[i][3]), i));
    }
    pair<int,int> p = findIntersection(vc);
    //cout << t << " " << p.xx << " " << p.yy << endl;
    if(p.xx == -1) lo = t;
    else hi = t;
  }

  if(lo > 1e13) cout << "No show :(" << endl;
  else cout << fixed << setprecision(12) << lo << endl;
  
}