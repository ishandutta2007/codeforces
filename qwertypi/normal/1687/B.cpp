#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;

int query(string s){
	cout << "? " << s << endl;
	int r; cin >> r;
	return r;
}

void answer(int x){
	cout << "! " << x << endl;
}

int r[1001];
int a[1001];
void solve(){
	int n, m;
	cin >> n >> m;
	string s(m, '0');
	for(int i = 0; i < m; i++){
		s[i] = '1';
		a[i] = query(s);
		s[i] = '0';
	}
	vector<pair<int, int>> vp;
	for(int i = 0; i < m; i++){
		vp.push_back({a[i], i});
	}
	sort(vp.begin(), vp.end());
	int p = 0;
	for(int i = 0; i < m; i++){
		s[vp[i].second] = '1';
		r[i + 1] = query(s);
		if(r[i + 1] - r[p] != a[vp[i].second]) s[vp[i].second] = '0';
		else p = i + 1;
	}
	int ans = 0;
	for(int i = 0; i < m; i++) if(s[i] == '1') ans += a[i];
	answer(ans); 
}

int32_t main(){
	int t = 1;
	// cin >> t;
	while(t--){
		solve();
	}
}