#include <bits/stdc++.h>
#define int long long

using namespace std;

int A[300001], B[300001];
void solve(){
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	for(int i = 0; i < n; i++){
		cin >> B[i];
	}
	
	vector<int> b1, b2;
	vector<int> s1, s2;
	for(int i = 0; i < n; i++){
		(B[i] == 1 ? b1.push_back(A[i]) : b2.push_back(A[i]));
	}
	sort(b1.begin(), b1.end(), [](int a, int b){
		return a > b;
	});
	sort(b2.begin(), b2.end(), [](int a, int b){
		return a > b;
	});
	s1.resize(b1.size() + 1); s2.resize(b2.size() + 1);
	for(int i = 0; i < b1.size(); i++){
		s1[i + 1] = s1[i] + b1[i];
	}
	for(int i = 0; i < b2.size(); i++){
		s2[i + 1] = s2[i] + b2[i];
	}
	int ans = (1LL << 60);
	for(int i = 0; i <= b1.size(); i++){
		if(s1[i] + s2[b2.size()] < m) continue;
		int idx = lower_bound(s2.begin(), s2.end(), m - s1[i]) - s2.begin();
		ans = min(ans, idx * 2 + i);
	}
	cout << (ans == (1LL << 60) ? -1 : ans) << endl;
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--) solve();
}