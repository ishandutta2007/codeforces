#include <bits/stdc++.h> 

using namespace std;
 
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define fst first
#define snd second
#define sz(x) (int) ((x).size()) 
#define forn(i, n) for (int i = 0; (i) < (n); ++i)
#define fornr(i, n) for (int i = (n) - 1; (i) >= 0; --i)
#define forab(i, a, b) for (int i = (a); (i) < (b); ++i)
#define forba(i, a, b) for (int i = (b) - 1; (i) >= (a); --i)
#define forit(it, c) for (__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define all(c) (c).begin(), (c).end() 

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) static_cast<void>(0)   
#endif

#ifdef _WIN32
	#define I64 "%I64d"
#else
	#define I64 "%lld"
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned int uint;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef double dbl;

#define FNAME ""

const double EPS = 1e-6, PI = 3.1415926535897932384626433832795;

inline bool eq(dbl a, dbl b){ return abs(a-b)<=EPS; }
inline bool gr(dbl a, dbl b){ return a>b+EPS; }
inline bool geq(dbl a, dbl b){ return a>=b-EPS; }
inline bool ls(dbl a, dbl b){ return a<b-EPS; }
inline bool leq(dbl a, dbl b){ return a<=b+EPS; }
struct Pnt{
    int x,y;
    Pnt():x(0),y(0){}
    Pnt(int _x, int _y):x(_x),y(_y){}

    inline Pnt operator +(const Pnt &B) const{ return Pnt(x+B.x, y+B.y); }
    inline Pnt operator -(const Pnt &B) const{ return Pnt(x-B.x, y-B.y); }
    inline ll operator *(const Pnt &B) const{ return x*1ll*B.x + y*1ll*B.y; } // LL
    inline ll operator %(const Pnt &B) const{ return x*1ll*B.y - y*1ll*B.x; } // LL

    inline Pnt operator -() const{ return Pnt(-x, -y); }

    inline void operator +=(const Pnt &B){ x+=B.x, y+=B.y; }
    inline void operator -=(const Pnt &B){ x-=B.x, y-=B.y; }

    inline bool operator ==(const Pnt &B){ return abs(x-B.x)<=EPS && abs(y-B.y)<=EPS; }
    inline bool operator !=(const Pnt &B){ return abs(x-B.x)>EPS || abs(y-B.y)>EPS; }
    inline bool operator <(const Pnt &B){ return abs(x-B.x)<=EPS ? y<B.y-EPS : x<B.x; }

    inline ll len2() const{ return x*1ll*x+y*1ll*y; } // LL

    inline void read(){
        int _x,_y;
        scanf("%d%d",&_x,&_y);
        x=_x, y=_y;
    }
    inline void write() const{
    }
};


typedef vector<Pnt> vpnt;

inline bool byAngle(const Pnt &a, const Pnt &b){
	ll x = a % b;
	return x == 0 ? a.len2() < b.len2() : x < 0;
}

vpnt convexHull(vpnt p){
	int n = sz(p);
	assert(n > 0);
	swap(p[0], *min_element(all(p)));
	forab(i, 1, n)
	p[i] = p[i] - p[0];
	sort(p.begin() + 1, p.end(), byAngle);

/*	    ,  (1)  (2)
	(1):
	int k = p.size() - 1;
	while(k > 0 && eq((p[k - 1] - p.back()) % p.back(), 0))
		--k;
	reverse(pi.begin() + k, pi.end());*/

	int rn = 0;
	vpnt r(n);
	r[rn++] = p[0];
	forab(i, 1, n){
		Pnt q = p[i] + p[0];
		while(rn >= 2 && (r[rn - 1] - r[rn - 2]) % (q - r[rn - 2]) >= 0) // (2) ge
			--rn;
		r[rn++] = q;
	}
	r.resize(rn);
	return r;
}

vector<int> pr(vector<pair<ll, double>> s) {
	int n = (int) s.size();
	vector<int> pi (n);
	for (int i=1; i<n; ++i) {
		int j = pi[i-1];
		while (j > 0 && (s[i].fs != s[j].fs || abs(s[i].sc - s[j].sc) > EPS))
			j = pi[j-1];
		if (s[i].fs == s[j].fs && abs(s[i].sc - s[j].sc) <= EPS)  ++j;
		pi[i] = j;
	}
	return pi;
}

double norm(double x) {
 	while (x >= -EPS)
 		x -= PI;
 	while (x < -PI)	
 		x += PI;
   	return x;
}

int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    

	int n, m;
	scanf("%d%d", &n, &m);
	vpnt a(n);
	forn (i, n)
		a[i].read();	
	vpnt b(m);
	forn (i, m)
		b[i].read();	
	a = convexHull(a);
	b = convexHull(b);
	if (sz(a) != sz(b)) {
	 	puts("NO");
	 	return 0;
	}
	if (sz(a) == 2) {
		if ((a[0] - a[1]).len2() == (b[0] - b[1]).len2())
			puts("YES");
		else
	 		puts("NO");
	 	return 0;
	}
	int k = sz(a);
	a.pb(a[0]);
	a.pb(a[1]);
	b.pb(b[0]);
	b.pb(b[1]);
	vector<pair<ll, double>> v;
	forn (i, k) {
	 	v.pb(mp((a[i + 1] - a[i]).len2(), norm(atan2(a[i + 2].y - a[i].y, a[i + 2].x - a[i].x) - atan2(a[i + 1].y - a[i].y, a[i + 1].x - a[i].x))));
	}
	v.pb(mp(0, 0));
	forn (i, k) {
	 	v.pb(mp((b[i + 1] - b[i]).len2(), norm(atan2(b[i + 2].y - b[i].y, b[i + 2].x - b[i].x) - atan2(b[i + 1].y - b[i].y, b[i + 1].x - b[i].x))));
	}
	forn (i, k)
		v.pb(v[k + 1 + i]);
	auto ans = pr(v);
	for (int z : ans)
		if (z == k) {
			puts("YES");
			return 0;
		}
	puts("NO");
	return 0;
}