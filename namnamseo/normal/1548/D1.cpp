#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
typedef pair<ll,ll> pll;
void cppio(){ ios_base::sync_with_stdio(0); cin.tie(0); }
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define eb emplace_back
#define x first
#define y second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define sz(x) (int)(x).size()

const int maxn = int(6e3) + 10;

int n;
pp d[maxn];

pp operator-(pp a, pp b) { return {a.x-b.x, a.y-b.y}; }

int Gcd(int a, int b) { return b?gcd(b, a%b) : a; }
int G(pp v) { return Gcd(abs(v.x), abs(v.y)); }

int main()
{
	cppio();
	cin >> n;
	rrep(i, n) cin >> d[i].x >> d[i].y;

	ll ans = 0;

	rrep(i, n) {
		static int T[4][4][4]; memset(T, 0, sizeof(T));
		rrep(j, n) if (i != j) {
			auto p = d[i]-d[j];
			int ma = G(p)%4;
			int mb = abs(p.x)%4;
			int mc = abs(p.y)%4;
			++T[ma][mb][mc];
		}
		rep(aa, 4)
		rep(ab, 4)
		rep(ac, 4)
		rep(ba, 4)
		rep(bb, 4)
		rep(bc, 4) {
			int ora = aa + ba + Gcd(abs(ab-bb), abs(ac-bc));
			if (ora % 4 == 0) {
				int ca = T[aa][ab][ac];
				int cb = T[ba][bb][bc];
				if (aa == ba && ab == bb && ac == bc) {
					ans += ca * (cb-1);
				} else {
					ans += ca * cb;
				}
			}
		}
	}

	ans /= 6;
	cout << ans << '\n';

	return 0;
}