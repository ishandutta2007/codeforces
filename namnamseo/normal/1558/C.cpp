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

int n;
int a[maxn];

int ans[maxn], an;

void Swap(int r) {
	int l = 1;
	if (l == r) return;
	ans[an++] = r;
	reverse(a+l, a+r+1);
}

void Work() {
	cin >> n;
	rrep(i, n) cin >> a[i];

	rrep(i, n) if ((i&1) != (a[i]&1)) {
		cout << "-1\n";
		return;
	}

	an = 0;
	for (int z=n; 1<z; z-=2) {
		int zp = find(a+1, a+z+1, z) - a;
		int z2p = find(a+2, a+z, z-1) - a;

		if (zp < z2p) {
			Swap(zp);
			Swap(z2p-1);
			Swap(z2p+1);
			Swap(3);
			Swap(z);
		} else {
			Swap(zp);
			z2p = 1+zp-z2p;
			Swap(z2p-1);
			Swap(z2p+1);
			Swap(3);
			Swap(z);
		}
	}

	cout << an << '\n';
	rep(i, an) cout << ans[i] << " \n"[i+1 == an];
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