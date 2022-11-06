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

int main()
{
	cppio();

	ll n, m, k;
	cin >> n >> m >> k;
	deque<ll> v(m);
	for(ll& x:v) cin >> x;
	int ans = 0;

	int p = 0;

	while(v.size()) {
		int s = sz(v);
		int c = 0;
		rep(i, s) {
			ll x = v[i];
			if((x - p - 1) / k == (v[0] - p - 1) / k) {
				++c;
				continue;
			} else break;
		}

		for(;c--;) {
			v.pop_front();
			++p;
		}

		++ans;
	}

	cout << ans << endl;

	return 0;
}