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

int p, q;

ll x, y;
int gcd(int a, int b) {
	if (!b) { x=1, y=0; return a; }
	int q = a/b;
	int ret = gcd(b, a%b);
	tie(x, y) = make_pair(y, x-y*q);
	return ret;
}

int ans[maxn][3];

int main()
{
	cppio();

	cin >> n;
	rrep(i, n) cin >> a[i];

	if (n == 1) {
		cout << "1 1\n" << (-a[1]) << "\n1 1\n0\n1 1\n0\n";
		return 0;
	}

	cout << 1 << ' ' << n << "\n0 ";
	for(int i=2; i<=n; ++i) {
		cout << (-n*1ll*a[i]) << ' ';
	}
	cout << '\n';

	cout << 1 << ' ' << 1 << '\n';
	cout << (-a[1]) << '\n';

	cout << 2 << ' ' << n << '\n';
	for(int i=2; i<=n; ++i) {
		int x = a[i];
		cout << ((n-1)*1ll*x) << ' ';
	}
	cout << '\n';

	return 0;
}