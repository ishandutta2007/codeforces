#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e5;
const double INF=1e18;
int n, x[mxN], y[mxN];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> x[i] >> y[i];
	if (*min_element(y, y+n)<0&&*max_element(y, y+n)>0) {
		cout << -1;
		return 0;
	}
	if (y[0]<0)
		for (int i=0; i<n; ++i)
			y[i]=-y[i];
	double lb=*max_element(y, y+n)/2.0, rb=1e14;
	for (int k=0; k<70; ++k) {
		double mid=(lb+rb)/2;
		double ls=-INF, rs=INF;
		for (int i=0; i<n; ++i) {
			double dy=abs(mid-y[i]);
			double r=sqrt(mid*mid-dy*dy);
			ls=max(ls, x[i]-r);
			rs=min(rs, x[i]+r);
		}
		if (ls<=rs)
			rb=mid;
		else
			lb=mid;
	}
	cout << fixed << setprecision(6) << lb;
	return 0;
}