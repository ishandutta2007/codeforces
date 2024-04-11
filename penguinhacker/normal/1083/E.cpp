#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ar array

const int mxN=1e6;
int n;
ar<ll, 3> a[mxN];

struct Line {
	ll m, b; //y=mx+b
	Line(ll m, ll b) : m(m), b(b) {}
	ll get(ll x) {return m*x+b;}
	ll div(ll a, ll b) {return a/b-((a^b)<0&&a%b);}
	ll isect(Line &o) {return div(b-o.b, o.m-m);}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i=0; i<n; ++i)
		for (int j=0; j<3; ++j)
			cin >> a[i][j];
	sort(a, a+n);

	deque<Line> dq;
	dq.push_front(Line(0, 0));
	ll ans=0;
	for (int i=0; i<n; ++i) {
		ll x=a[i][0], y=a[i][1], sub=a[i][2];
		while (dq.size()>=2&&dq.back().get(y)<=dq[dq.size()-2].get(y))
			dq.pop_back();
		ll f=dq.back().get(y)+x*y-sub;
		ans=max(ans, f);
		Line cur=Line(-x, f);
		while (dq.size()>=2&&cur.isect(dq[0])>=dq[0].isect(dq[1]))
			dq.pop_front();
		dq.push_front(cur);
	}
	cout << ans;
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/