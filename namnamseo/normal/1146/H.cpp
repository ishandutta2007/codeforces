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
void cppio(){ ios_base::sync_with_stdio(0); cin.tie(0); }
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define eb emplace_back
#define x first
#define y second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define sz(x) (int)(x).size()
#define xy(a) a.x, a.y

inline bool ccw(pp a, pp b, pp c){
	return ll(c.y-a.y) * (b.x-a.x) > ll(c.x-a.x) * (b.y-a.y);
}
int n;
pp p[310];

int oi[310], oj[310];
int tmp[310];

int fen[310];
int F(int p){
	int ret=fen[0];
	while(p){
		ret += fen[p];
		p &= (p-1);
	}
	return ret;
}
void upd(int p, int v){
	if(!p){ fen[0] += v; return; }
	while(p <= n){
		fen[p] += v;
		p += (p & (-p));
	}
}

int main()
{
	cppio(); cin >> n;
	ll ans = ll(n) * (n-1) / 2 * (n-2) / 3 * (n-3) / 4 * (n-4) / 5;
	ll t4 = 0, t3 = 0;

	rrep(i, n){ cin >> p[i].x >> p[i].y; }
	rrep(i, n) for(int j=1; j<=n; ++j) if(i!=j){
		vector<int> l, r;
		for(int k=1; k<=n; ++k) if(k!=i && k!=j){
			(ccw(p[i], p[j], p[k]) ? l : r).pb(k);
		}

		auto calc = [&](int i, int j, vector<int>& v){
			int s=sz(v);
			sort(all(v), [&](const int& a, const int& b){ return ccw(p[i], p[a], p[b]); });
			rep(k, s) oi[v[k]] = k;
			sort(all(v), [&](const int& a, const int& b){ return ccw(p[j], p[b], p[a]); });
			rep(k, s) tmp[oi[v[k]]] = k;
			rep(k, s) fen[k]=0;
			int ss=0;
			int tri=0;
			rep(k, s){
				int v=tmp[k];
				int f=F(v);
				ss += f;
				tri += f * (f-1) / 2;
				upd(v, 1);
			}
			t4 += ss * ll(n-2-s);
			t3 += tri;
		};
		calc(i, j, l);
		calc(j, i, r);
	}

	assert(t4%4 == 0);
	assert(t3%6 == 0);
	t4 /= 4;
	t3 /= 6;

	t4 -= 2*t3;

	ans -= t4 + t3;
	cout << ans << endl;
	return 0;
}