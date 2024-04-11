#include <bits/stdc++.h>
#define N 1000001
#define int long long
using namespace std;
int A[N];
int cnt[N];
int ans[N];
int solve(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	for(int i = 0; i <= n; i++){
		cnt[i] = 0;
	}
	for(int i = 0; i < n; i++){
		cnt[A[i]]++;
	}
	fill(ans, ans + n + 1, -1);
	sort(A, A + n);
	vector<int> left;
	int res = 0;
	for(int i = 0; i <= n; i++){
		ans[i] = res + cnt[i];
		for(int j = 0; j < cnt[i] - 1; j++){
			left.push_back(i);
		}
		if(cnt[i] == 0){
			if(left.size() == 0) break;
			res += i - left.back();
			left.pop_back();
		}
	}
	for(int i = 0; i <= n; i++){
		cout << ans[i] << ' ';
	}
	cout << endl;
	return 0;
} 

int32_t main(){
	int t;
	cin >> t;
	while(t--) solve();
}