#include <bits/stdc++.h>
#define int long long
#define inf (1LL << 60)
using namespace std;

bool correct[200001];
int A[200001], B[200001];

int query(vector<int>& a, vector<int>& b){
	int n = a.size(), m = b.size();
	// cout << "QUERY " << a.size() << ' ' << b.size() << endl;
	set<int> S;
	for(auto i : b) S.insert(i);
	vector<int> ok, s;
	ok.resize(a.size() + 1); s.resize(a.size() + 1);
	for(int i = 0; i < a.size(); i++){
		ok[i] = S.find(a[i]) != S.end();
	}
	for(int i = n - 1; i >= 0; i--){
		s[i] = s[i + 1] + ok[i];
	}
	int ans = s[0];
	a.push_back(inf);
	for(int i = 0; i < n; i++){
		int res1 = s[i + 1], res2 = 0;
		int l = lower_bound(b.begin(), b.end(), a[i] - i) - b.begin();
		while(l < m && b[l] < a[i + 1] - i - 1){
			int r = upper_bound(b.begin(), b.end(), min(b[l] + i, a[i + 1] - 1)) - b.begin() - 1;
			res2 = max(res2, r - l + 1);
			l++;
		}
		ans = max(ans, res1 + res2);
	}
	// cout << ans << endl;
	return ans;
}

void solve(){
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	for(int j = 0; j < m; j++){
		cin >> B[j];
	}
	
	int ans = 0;
	vector<int> a, b;
	for(int i = 0; i < n; i++){
		if(A[i] > 0) a.push_back(A[i]);
	}
	for(int i = 0; i < m; i++){
		if(B[i] > 0) b.push_back(B[i]);
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	ans += query(a, b);
	a.clear(); b.clear();
	
	for(int i = 0; i < n; i++){
		if(A[i] < 0) a.push_back(-A[i]);
	}
	for(int i = 0; i < m; i++){
		if(B[i] < 0) b.push_back(-B[i]);
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	ans += query(a, b);
	cout << ans << endl;
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--){
		solve();
	}
}