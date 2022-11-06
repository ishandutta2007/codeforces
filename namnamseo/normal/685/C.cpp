#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
typedef pair<ll,ll> pll;
void read(int& x){ scanf("%d",&x); }
void read(ll& x){ scanf("%lld",&x); }
template<typename T,typename... Args>
void read(T& a,Args&... b){ read(a); read(b...); }
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define eb emplace_back
#define x first
#define y second

pll sect(pll a, pll b){ return pll{max(a.x, b.x), min(a.y, b.y)}; }
bool nonempty(pll a){ return a.x<=a.y; }
pll cr(ll c, ll r){ return {c-r, c+r}; }
const pll R{-ll(1e18)*4, ll(1e18)*4};
pll div2(pll a){ return {(a.x+1)>>1, a.y>>1}; }
pll operator-(pll a, ll d){ return {a.x-d, a.y-d}; }
pll operator-(pll a){ return {-a.x, -a.y}; }

ll ansa, ansb, ansc;

bool solvable(pll a, pll b, pll c, pll abc){
	if(nonempty(a) && nonempty(b) && nonempty(c) && nonempty(abc)){
		if(nonempty(sect(pll{a.x+b.x+c.x, a.y+b.y+c.y}, abc))){
			ll va = a.x;
			ll vb = b.x;
			ll vc = c.x;
			va += max(0ll, min(a.y - va, abc.x - (va+vb+vc)));
			vb += max(0ll, min(b.y - vb, abc.x - (va+vb+vc)));
			vc += max(0ll, min(c.y - vc, abc.x - (va+vb+vc)));
			ansa = va;
			ansb = vb;
			ansc = vc;
			return 1;
		} else return 0;
	} else return 0;
}

int coeff[4][3]={
	{1, 1, 1},
	{-1, 1, 1},
	{1, -1, 1},
	{1, 1, -1}
};

int n;
ll p[100010][3];

ll ansx, ansy, ansz;

bool check(ll d){
	pll r[4]; for(int i=0; i<4; ++i) r[i]=R;
	for(int i=0; i<n; ++i){
		for(int j=0; j<4; ++j){
			ll s = 0;
			for(int k=0; k<3; ++k) s += p[i][k]*coeff[j][k];
			r[j] = sect(r[j], cr(s, d));
		}
	}
	for(int i=0; i<4; ++i) if(!nonempty(r[i])) return 0;
	for(int par=0; par<2; ++par){
		pll ar = div2(r[1]-par);
		pll br = div2(r[2]-par);
		pll cr = div2(r[3]-par);
		pll abcr = div2(r[0]-3*par);
		if(solvable(ar, br, cr, abcr)){
			ll a = ansa * 2 + par;
			ll b = ansb * 2 + par;
			ll c = ansc * 2 + par;
			ansx = (b+c)/2;
			ansy = (c+a)/2;
			ansz = (a+b)/2;
			return 1;
		}
	}
	return 0;
}

int main()
{
	int tc; read(tc);
for(;tc--;){
	read(n);
	for(int i=0; i<n; ++i) for(int j=0; j<3; ++j) read(p[i][j]);
	ll L=-1, R=ll(1e18)*3 + 10;
	while(L+1 < R){
		ll mid = (L+R)/2;
		(check(mid)?R:L) = mid;
	}
	check(R);
	printf("%lld %lld %lld\n", ansx, ansy, ansz);
}
	return 0;
}