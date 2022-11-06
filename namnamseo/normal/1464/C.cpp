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

const int maxn = int(1e5) + 10;
int n;
ll t;

char s[maxn];

void die() { cout << "No\n"; exit(0); }

ll bc[30];
int main()
{
	cppio();
	cin >> n >> t >> (s+1);

	t -= (1ll << (s[n]-'a'));
	t += (1ll << (s[n-1]-'a'));
	t = abs(t);
	n -= 2;
	if (!n) {
		if (t) die();
		cout << "Yes\n";
		return 0;
	}

	ll sm = 0;
	rrep(i, n) sm += (1ll << (s[i]-'a'));

	if (sm < t) die();
	sm -= t;
	if (sm & 1) die();
	sm /= 2;

	rrep(i, n) ++bc[s[i]-'a'];

	for(int i=0; i<30; ++i) {
		rep(unit, i) {
			if (bc[unit] >= (1ll<<(i-unit))) {
				bc[unit] += bc[i] * (1ll<<(i-unit));
				bc[i] = 0;
				break;
			}
		}
	}

	int ci = 0;
	rep(i, 30) if (1 & (sm >> i)) {
		while (ci <= i && bc[ci] < (1ll << (i - ci))) ++ci;
		if (ci > i) die();
		bc[ci] -= (1ll << (i-ci));
	}

	cout << "Yes\n";

	return 0;
}