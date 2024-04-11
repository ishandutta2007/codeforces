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

const int maxn = int(2e5) + 10;

int a, b;

void Work() {
	int a, b; cin >> a >> b;
	static int ans[maxn];
	int an = 0;
	int g[2];
	g[0] = (a+b+1)/2; g[1] = a+b-g[0];
	for (int k=0; k<=a+b; ++k) {
		if ([&]{
		for (int i=0; i<2; ++i) {
			int gx = g[i], gy = g[i^1];
			int t2 = k + gx - b;
			if (t2%2) continue;
			int t = t2/2;
			if (!(0<=t && t<=gx && t<=a)) continue;
			int u = k-t;
			if (!(0<=u && u<=gy && u<=b)) continue;
			return true;
		} return false; }()) ans[an++] = k;
	}

	cout << an << '\n';
	rep(i, an) cout << ans[i] << " \n"[i==an-1];
}

int main()
{
	cppio();
	int tc; cin >> tc;
rrep(tci, tc) {
	Work();
}
	return 0;
}