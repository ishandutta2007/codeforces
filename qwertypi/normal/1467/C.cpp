#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<vector<int>> bags(3);

int32_t main(){
	int a, b, c;
	cin >> a >> b >> c;
	for(int i = 0; i < a; i++){
		int v; cin >> v; bags[0].push_back(v);
	}
	
	for(int i = 0; i < b; i++){
		int v; cin >> v; bags[1].push_back(v);
	}
	
	for(int i = 0; i < c; i++){
		int v; cin >> v; bags[2].push_back(v);
	}
	sort(bags[0].begin(), bags[0].end());
	sort(bags[1].begin(), bags[1].end());
	sort(bags[2].begin(), bags[2].end());
	vector<int> _m;
	int ans = 0;
	for(int i = 0; i < 3; i++){
		_m.push_back(bags[i][0]);
		for(auto j : bags[i]) ans += j;
	}
	sort(_m.begin(), _m.end());
	ans -= 2LL * (_m[0] + _m[1]);
	
	vector<int> A;
	for(int i = 0; i < 3; i++){
		A.push_back(accumulate(bags[i].begin(), bags[i].end(), 0LL));
	}
	sort(A.begin(), A.end());
	ans = max(ans, -A[0] + A[1] + A[2]);
	cout << ans << endl;
}