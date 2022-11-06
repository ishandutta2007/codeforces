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

char getC(int i) {
	if(i == 0) return 'R';
	if(i == 1) return 'G';
	return 'B';
}
///
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
	int q; cin >> q;
	while(q--) {
		string s;
		int n, k; cin >> n >> k >> s;
		int cnt[3];
		cnt[0] = cnt[1] = cnt[2] = 0;
		F0R(i, k) {
			if(getC(i % 3) != s[i]) cnt[0]++;
			if(getC((i+1) % 3) != s[i]) cnt[1]++;
			if(getC((i+2) % 3) != s[i]) cnt[2]++;
		}
		int ans = min(cnt[0], min(cnt[1], cnt[2]));
		FOR(i, k, n) {
			if(getC((i-k) % 3) != s[i-k]) cnt[0]--;
			if(getC((i-k+1) % 3) != s[i-k]) cnt[1]--;
			if(getC((i-k+2) % 3) != s[i-k]) cnt[2]--;
			if(getC(i % 3) != s[i]) cnt[0]++;
			if(getC((i+1) % 3) != s[i]) cnt[1]++;
			if(getC((i+2) % 3) != s[i]) cnt[2]++;
			ans = min(ans, min(cnt[0], min(cnt[1], cnt[2])));
		}
		cout << ans << endl;
	}
///
	cin >> q;
	return 0;
}