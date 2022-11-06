#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lsb(x) (x & (-x)) 

using namespace std;



int main() {
	//ifstream cin("A.in");
	//ofstream cout("A.out");
	int i, n, k, a;
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> n >> k;

	vector <int> x(n + 1);
	for(i = 1; i <= n; i++) {
		cin >> x[i];
	}
	cin >> a;
	multiset <int> mst;
	ll ans = 0;
	for(i = 1; i <= n; i++) {
		int c;
		cin >> c;
		mst.insert(c);
		while(mst.size() && k < x[i]) {
			k += a;
			ans += *mst.begin();
			mst.erase(mst.begin());
		}
		if(k < x[i]) {
			cout << -1;
			return 0;
		}
	}
	cout << ans;
	
	return 0;
}