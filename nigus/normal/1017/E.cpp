#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<double,double> pdd;


const ll big = 998244353;
//const ll mod = 998244353;

#define R(x) const { return x; }
template <class T>
struct Point {
	typedef Point P;
	T x, y;
	explicit Point(T x=0, T y=0) : x(x), y(y) {}
	bool operator<(P p) R(x<p.x || (x==p.x && y<p.y))
	bool operator==(P p) R(x==p.x && y==p.y)
	P operator+(P p) R(P(x+p.x, y+p.y))
	P operator-(P p) R(P(x-p.x, y-p.y))
	P operator*(T d) R(P(x*d, y*d))
	P operator/(T d) R(P(x/d, y/d))
	T dot(P p) R(x*p.x + y*p.y)
	T cross(P p) R(x*p.y - y*p.x)
	T dist2() R(x*x + y*y) // distance^2
	double dist() R(sqrt((double)dist2())) //length
	// angle to x-axis in interval [-pi, pi]
	double angle() R(atan2(y, x))
	P unit() R(*this/(T)dist()) // makes dist()=1
	P perp() R(P(-y, x)) // rotates +pi/2 radians
	P normal() R(perp().unit())
	// returns point rotated 'a' radians ccw around the origin
	P rotate(double a) R(P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)))
};

typedef Point<ll> ptype;
ptype Ref;
bool comp(const ptype &p, const ptype &q) {
	return (p-Ref).cross(q-p)>0 ||
	  ((p-Ref).cross(q-p)==0 && (p-Ref).dist2()<(q-Ref).dist2());
}

template <class It>
It convexHull(It begin, It end) {
	//zero or one point always form a hull
	if (end-begin < 2) return end;
	//find a guaranteed hull point to use as origo
	Ref = *min_element(begin,end);
	sort(begin, end, comp); //sort in scan order
	//place hull points first by doing a Graham scan
	It r = begin + 1;
	for (It i = begin+2; i != end; ++i) {
		while (r > begin && (*r-*(r-1)).cross(*i-*r) <= 0) --r;
		swap(*++r, *i);
	}
	if (r-begin == 1 && *begin == *r) r--;
	return ++r; //return the iterator past the last hull point
}

ll n,m,k,T,q;

vector<Point<ll> > P1;
vector<Point<ll> > P2;

vl L1;
vl L2;

vl SC1;
vl SC2;

ll const base = 12334785;
ll const num2 = 52747372;

ll mod(ll i){
    if(i < 0)return mod(big-mod(-i));
    return i%big;
}

ll thing(ll i, ll j){
    return (num2*(mod(i))+mod(j))%big;
}

ll has1(){
    ll ans = 0;
    for(int c1 = 0; c1 < n; c1++){
        ll l = mod(L1[c1]);
        ll sc = mod(SC1[c1]);
        ll a = num2*sc+l;
        a %= big;
        ans *= base;
        ans += a;
        ans %= big;
    }
    return ans;
}

ll has2(){
    ll ans = 0;
    for(int c1 = 0; c1 < n; c1++){
        ll l = mod(L2[c1]);
        ll sc = mod(SC2[c1]);
        ll a = num2*sc+l;
        a %= big;
        ans *= base;
        ans += a;
        ans %= big;
    }
    return ans;
}


bool check(ll i){
    for(int c1 = 0; c1 < n; c1++){
        if(L1[c1] != L2[(c1+i)%n])return 0;
        if(SC1[c1] != SC2[(c1+i)%n])return 0;
    }
    return 1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c;

    cin >> n >> m;
    for(int c1 = 0; c1 < n; c1++){
        cin >> a >> b;
        Point<ll> pt(a,b);
        P1.push_back(pt);
    }
    for(int c1 = 0; c1 < m; c1++){
        cin >> a >> b;
        Point<ll> pt(a,b);
        P2.push_back(pt);
    }

    vector<Point<ll> > hull1(P1.begin(),convexHull(P1.begin(),P1.end()));
  	P1.resize(convexHull(P1.begin(),P1.end())-P1.begin());

  	vector<Point<ll> > hull2(P2.begin(),convexHull(P2.begin(),P2.end()));
  	P2.resize(convexHull(P2.begin(),P2.end())-P2.begin());

  	if(sz(P1) != sz(P2)){
        cout << "NO\n";
        return 0;
  	}
  	n = sz(P1);
  	if(n==1){
        cout << "YES\n";
        return 0;
  	}
    for(int c1 = 0; c1 < n; c1++){
        ll j = (c1+1)%n;
        ll i = (c1+n-1)%n;
        Point<ll> Q1 = P1[c1]-P1[i];
        Point<ll> Q2 = P1[j]-P1[c1];
        L1.push_back(Q2.dist2());
        SC1.push_back(Q1.dot(Q2));
    }

    for(int c1 = 0; c1 < n; c1++){
        ll j = (c1+1)%n;
        ll i = (c1+n-1)%n;
        Point<ll> Q1 = P2[c1]-P2[i];
        Point<ll> Q2 = P2[j]-P2[c1];
        L2.push_back(Q2.dist2());
        SC2.push_back(Q1.dot(Q2));
    }

/*
    for(int c1 = 0; c1 < n; c1++){
        cout << L1[c1] << "," << SC1[c1] << "  ";
    }cout << "\n";

    for(int c1 = 0; c1 < n; c1++){
        cout << L2[c1] << "," << SC2[c1] << "  ";
    }cout << "\n";
*/
    ll h1 = has1();
    ll h2 = has2();

    ll basen = 1;
    for(int c1 = 0; c1 < n-1; c1++){
        basen *= base;
        basen %= big;
    }

    for(int c1 = 0; c1 < n; c1++){
      //  cout << h1 << " " << h2 << "\n";
        if(h1 == h2){
            if(check(c1)){
                cout << "YES\n";
                return 0;
            }
        }

        h2 -= (basen*thing(SC2[c1],L2[c1]))%big;
        h2 += 2*big;
        h2 %= big;
        h2 *= base;
        h2 += thing(SC2[c1],L2[c1]);
        h2 %= big;

    }

    cout << "NO\n";


    return 0;
}