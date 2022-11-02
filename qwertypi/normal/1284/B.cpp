/* Hello, 2020! */

#include <bits/stdc++.h>

#define int long long
#define fi first
#define se second
#define pii pair<int, int>
#define vpii vector<pair<int, int>>
#define vppii vector<pair<pair<int, int>, pair<int, int>>>

using namespace std;

vector<pair<int, int>> A;

int32_t main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		vector<int> B;
		int k;
		cin >> k;
		int prev;
		cin >> prev;
		int st = prev;
		bool OK = 0;
		for(int j = 1; j < k; j++){
			int v;
			cin >> v;
			if(v > prev){
				OK = 1;
			}
			prev = v;
		}
		int en = prev;
		if(!OK){
			A.push_back({st, en});
		}
	}
	vector<int> C;
	for(int i = 0; i < A.size(); i++){
		C.push_back(A[i].fi);
	}
	int ans = 0;
	sort(C.begin(), C.end());
	for(int i = 0; i < A.size(); i++){
		int pos = upper_bound(C.begin(), C.end(), A[i].se) - C.begin();
		ans += pos;
	}
	ans = n * n - ans;
	cout << ans << endl;
}