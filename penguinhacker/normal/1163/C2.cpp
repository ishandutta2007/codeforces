#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const double EPS=1e-9;
const double INF=1e18;

bool eq(double a, double b) {return abs(a-b)<EPS; }
struct Line {
	double m, b;
	Line(double x1, double y1, double x2, double y2) {
		if (x1==x2) {m=INF; b=x1;}
		else  {
			m=(y2-y1)/(x2-x1);
			b=(-x1)*m+y1;
		}
	}
	bool operator==(const Line &o) const {return eq(b, o.b)&eq(m, o.m); }
	bool operator<(const Line &o) const {return make_pair(b, m)<make_pair(o.b, o.m); }
};

const int mxN=1000;
int n, x[mxN], y[mxN];
map<double, set<Line>> s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> x[i] >> y[i];
	for (int i=0; i<n; ++i)
		for (int j=i+1; j<n; ++j) {
			Line l(x[i], y[i], x[j], y[j]);
			s[l.m].insert(l);
		}
	ll ans=0, cnt=0;
	for (auto &x : s) {
		int k=x.second.size();
		cnt+=k;
		ans-=k*(k-1)/2;
		//cout << "\n\n\n";
		//for (auto &i : x.second)
		//	cout << i.m << ' ' << i.b << '\n';
	}
	ans+=cnt*(cnt-1)/2;
	cout << ans;
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/