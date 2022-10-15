#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;
	
	vector<pair<int, int>> a(n);
	for(int i = 0; i < n; ++i)
	  cin >> a[i].first >> a[i].second;
	  
	double ans = 1e18;
	for(int i = 0; i < n; ++i) {
	  int l = (i-1+n)%n;
	  int r = (i+1)%n;
	  auto i_l = make_pair(a[i].first-a[l].first, a[i].second-a[l].second);
	  auto r_l = make_pair(a[r].first-a[l].first, a[r].second-a[l].second);
	  auto x = i_l.first;
	  auto y = i_l.second;
	  auto dx = 1.0*r_l.first;
	  auto dy = 1.0*r_l.second;
	  auto h = fabs(x*dy - y*dx) / sqrt(dx*dx+dy*dy);
	  ans = min(ans, h);
	}
	cout << fixed << setprecision(10) << ans/2 << endl;
}