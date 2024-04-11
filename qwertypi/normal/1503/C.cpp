#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<pair<int, int>> A;

int32_t main(){
	int n;
	cin >> n;
	int ans = 0;
	for(int i = 0; i < n; i++){
		int a, c;
		cin >> a >> c;
		ans += c;
		A.push_back({a, a + c});
	}
	sort(A.begin(), A.end());
	int h = A[0].second;
	for(int i = 1; i < n; i++){
		if(h < A[i].first){
			ans += A[i].first - h;
			h = A[i].second;
		}else{
			h = max(h, A[i].second);
		}
	}
	cout << ans << endl;
}