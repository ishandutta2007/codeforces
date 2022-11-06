#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
typedef pair<ll,ll> pll;
void read(int& x){ scanf("%d",&x); }
void read(ll& x){ scanf("%lld",&x); }
void read(pp& x){ scanf("%d%d",&x.first, &x.second); }
void read(pll& x){ scanf("%lld%lld",&x.first, &x.second); }
template<typename T,typename... Args>
void read(T& a,Args&... b){ read(a); read(b...); }
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define eb emplace_back
#define x first
#define y second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define sz(x) (int)(x).size()

pp p[5001];
int n;
ll S;

pp operator+(pp a, pp b){ return {a.x+b.x, a.y+b.y}; }
pp operator-(pp a, pp b){ return {a.x-b.x, a.y-b.y}; }
ll dot(pp a, pp b){ return ll(a.x)*b.x + ll(a.y)*b.y; }

vector<pp> hull;
int hn;

bool ccw(pp a, pp b){
	return ll(a.x)*b.y - ll(a.y)*b.x >= 0;
}

bool ccw(pp a, pp b, pp c){ return ccw(b-a, c-a); }

vector<pp> get_hull(){
	vector<int> stk;

	rrep(i, n){
		while(sz(stk)>=2 && ccw(p[*(stk.rbegin()+1)], p[*stk.rbegin()], p[i])) stk.pop_back();
		stk.pb(i);
	}

	vector<pp> v;
	for(int x:stk) v.pb(p[x]);
	return v;
}

void build(){
	sort(p+1, p+n+1);
	auto tmp = get_hull();
	hull.insert(hull.end(), all(tmp));
	hull.pop_back();
	reverse(p+1, p+n+1);
	tmp = get_hull();
	hull.insert(hull.end(), all(tmp));
	hull.pop_back();
	hn = hull.size();
}

pp rcw(pp v){ return {v.y, -v.x}; }

bool further(pp vec, pp a, pp b){
	vec = rcw(vec);
	return dot(b-a, vec) >= 0;
}

ll get_area(pp a, pp b, pp c){
	pll va = b-a, vb = c-a;
	return abs(va.x*vb.y - va.y*vb.x);
}

ll ar;
pp aa, ab, ac;
void upd(pp a, pp b, pp c){
	ll A = get_area(a,b,c);
	if(ar < A){
		ar = A;
		tie(aa, ab, ac) = make_tuple(a,b,c);
	}
}

int main()
{
	read(n, S);
	rrep(i, n) read(p[i]);
	build();

	rep(a, hn){
		int pt = (a+1)%hn;
		for(int b=a+1; b<hn; ++b){
			while(further(hull[b]-hull[a], hull[pt], hull[(pt+1)%hn])) (pt+=1)%=hn;
			upd(hull[a], hull[b], hull[pt]);
		}
	}

	pp a = aa+ab-ac;
	pp b = ab+ac-aa;
	pp c = ac+aa-ab;

	for(pp x:vector<pp>{a, b, c}){
		printf("%d %d\n", x.x, x.y);
	}
	return 0;
}