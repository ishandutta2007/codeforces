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
char s[maxn];

void f(int t, int l, int r) {
	cout << t << ' ' << l << ' ' << r << '\n';
}

int main()
{
	cppio();
	int tc; cin >> tc;
for(;tc--;) {
	cin >> n;
	{ int x; for (int i=1; i<=n; ++i) cin >> x; }
	cout << ((n/2)*6) << '\n';
	for (int i=1; i<=n; i+=2) {
		int l = i, r = i+1;
		// a b
		f(2, l, r);
		// a b-a
		f(1, l, r);
		// b b-a
		f(2, l, r);
		// b -a

		f(2, l, r);
		f(1, l, r);
		f(2, l, r);
		// -a -b
	}

}

	return 0;
}