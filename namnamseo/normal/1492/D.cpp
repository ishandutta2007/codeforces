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

int a, b, k, n;

char ax[maxn];
char ay[maxn];

void fail() {
	cout << "No\n";
	exit(0);
}

void fin() {
	cout << "Yes\n" << ax << '\n' << ay << '\n';
	exit(0);
}

int main()
{
	cppio();
	cin >> a >> b >> k;
	n = a+b;

	if (!(0 <= k && k <= max(0, n-2))) fail();

	if (k == 0) {
		fill(ax, ax+b, '1');
		fill(ax+b, ax+n, '0');

		fill(ay, ay+b, '1');
		fill(ay+b, ay+n, '0');

		fin();
	}

	if (b < 2 || a < 1) fail();

	ax[0] = '1'; ax[1] = '1'; ax[k+1] = '0';
	ay[0] = '1'; ay[1] = '0'; ay[k+1] = '1';

	a -= 1; b -= 2;

	for (int i=0; i<n; ++i) if (i!=0 && i!=1 && i!=k+1) {
		if (a) {
			--a;
			ax[i] = ay[i] = '0';
		} else if (b) {
			--b;
			ax[i] = ay[i] = '1';
		} else {
			// implausible
			fail();
		}
	}

	fin();

	return 0;
}