#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
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
	string s; cin >> s;
	int prev = 0;
	int cnt = 0;
	F0R(i, s.length()) {
		if(s[i] == 'v') prev++;
		else {
			if(prev != 0) cnt += prev-1;
			prev = 0;
		}
	}
	if(prev != 0) cnt += prev-1;
	ll ans = 0, cur = 0;
	prev = 0;
	F0R(i, s.length()) {
		if(s[i] == 'v') prev++;
		else {
			if(prev != 0) {
				cnt -= prev-1;
				cur += prev-1;
			}
			prev = 0;
			ans += cur * cnt;
		}
	}
	cout << ans << endl;
///
	return 0;
}