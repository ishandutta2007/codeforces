#include <bits/stdc++.h>

// nothing to say
using namespace std;

int a[200001];
void solve(){
	int n, k;
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	long long tot = accumulate(a, a + n, 0LL);
	for(int i = 0; i < n; i++){
		a[i] -= n - 1 - i;
	}
	vector<int> s;
	for(int i = 0; i < n; i++) s.push_back(a[i]);
	sort(s.begin(), s.end(), [](int a, int b){
		return a > b;
	});
	
	long long ans = tot;
	for(int i = 0; i < k; i++){
		tot -= s[i];
		tot -= i;
		ans = min(ans, tot);
	}
	cout << ans << endl;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}