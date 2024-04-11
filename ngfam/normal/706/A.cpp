#include <bits/stdc++.h>

using namespace std;

typedef long double db;

db dist(db x, db y, db xx, db yy){
	return sqrt((x - xx) * (x - xx) + (y - yy) * (y - yy));
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("1.inp", "r", stdin);
		freopen("1.out", "w", stdout);
	#endif

	double a, b;
	cin >> a >> b;

	int n; cin >> n;

	cout << fixed << setprecision(10);

	db ans = 1e7;

	for(int i = 1; i <= n; ++i){
		db x, y, v;
		cin >> x >> y >> v;	
		ans = min(ans, dist(a, b, x, y) / v);
	}

	cout << ans;
	
	return 0;
}