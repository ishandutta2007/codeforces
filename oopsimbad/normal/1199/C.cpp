#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
 
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define f first
#define s second
#define mp make_pair
#define pb push_back

///
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
	int n, I; cin >> n >> I;
	int k = I*8/n;
	if(k >= 20 || 1<<k > n) {
		cout << 0 << endl;
		return 0;
	}
	int cnt = 1 << k;
	map<int,int> m;
	F0R(i, n) {
		int a; cin >> a;
		m[a]++;
	}
	auto l = m.begin(), r = m.begin();
	int sum = 0;
	int ans = n;
	int cnt2 = 0;
	while(r != m.end()) {
		sum += r->s;
		r++;
		cnt2++;
		while(l != m.end() && cnt2 > cnt) {
			sum -= l->s;
			l++;
			cnt2--;
		}
		ans = min(ans, n-sum);
	}
	cout << ans << endl;
///
	int qwertyuiop;
	cin >> qwertyuiop;
	return 0;
}