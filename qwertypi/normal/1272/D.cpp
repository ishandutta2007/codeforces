#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define set unordered_set
#define map unordered_map
using namespace std;

vector<pair<int, int>> B;
int A[200000];

int32_t main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}

	int prev = -1;
	int cnt = 0;
	int end = -1;
	for(int i = 0; i < n; i++){
		if(A[i] > prev){
			cnt++;
			prev = A[i];
		}else{
			B.push_back({end + 1, i - 1});
			end = i - 1;
			cnt = 1;
			prev = A[i];
		}
	}
	B.push_back({end + 1, n - 1});
	int ans = 0;
	for(int i = 0; i < (int) B.size(); i++){
		ans = max(ans, B[i].se - B[i].fi + 1);
	}
	for(int i = 0; i < (int) B.size() - 1; i++){
		if(B[i].fi == B[i].se || B[i + 1].fi == B[i + 1].se){
			continue;
		}
		if(A[B[i].se] < A[B[i + 1].fi + 1] || A[B[i].se - 1] < A[B[i + 1].fi]){
			ans = max(ans, B[i].se - B[i].fi + 1 + B[i + 1].se - B[i + 1].fi + 1 - 1);
		}
	}
	cout << ans << endl;
	return 0;
}