#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

double x1, x2, r1, r2, y1, y2, ans=0;
double sq(int d) {return d*d;}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> x1 >> y1 >> r1;
	cin >> x2 >> y2 >> r2;
	if (r1<r2) {
		swap(x1, x2);
		swap(y1, y2);
		swap(r1, r2);
	}
	double d=sqrt(sq(x1-x2)+sq(y1-y2));
	if (d>=r1+r2)
		ans=(d-r1-r2)/2;
	if (d+r2<=r1)
		ans=(r1-d-r2)/2;
	cout << fixed << setprecision(15) << ans;
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/