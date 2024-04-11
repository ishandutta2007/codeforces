#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=100000;
int n, a[mxN], b[mxN];
ll ps[mxN], dp[mxN];

struct Line {
	ll m, b;
	Line(ll m, ll b) : m(m), b(b) {}
	ll div(ll a, ll b) {return a/b-((a^b)<0&&a%b);}
	ll eval(ll x) {return m*x+b;}
	ll isect(Line &o) {return div(b-o.b, o.m-m);}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> a[i];
		ps[i]=a[i]+(i?ps[i-1]:0);
	}
	for (int i=0; i<n; ++i)
		cin >> b[i];

	const ll C=b[n-1];
	deque<Line> dq;
	dq.push_back(Line(b[0], -C*ps[0]));
	for (int i=1; i<n; ++i) {
		/*dp[i]=5e18;
		for (int j=0; j<i; ++j)
			dp[i]=min(dp[i], dp[j]+1ll*b[j]*a[i]+(ps[i-1]-ps[j])*b[n-1]);*/
		while (dq.size()>=2&&dq[0].eval(a[i])>=dq[1].eval(a[i]))
			dq.pop_front();
		dp[i]=dq[0].eval(a[i])+C*ps[i-1];
		Line cur(b[i], dp[i]-C*ps[i]);
		while(dq.size()>=2&&cur.isect(dq.back())<=cur.isect(dq[dq.size()-2]))
			dq.pop_back();
		dq.push_back(cur);
	}
	cout << dp[n-1];
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/