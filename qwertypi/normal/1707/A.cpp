#include <bits/stdc++.h>
#define int long long
using namespace std;

priority_queue<pair<int, int>> pq;

int a[300013];
bool ex[300013];

string s;
int n, q;
bool test(int k, int v){
	for(int i = 0; i < k; i++){
		if(v >= a[i]){
			s[i] = '1';
		}else{
			s[i] = '0';
		}
	}
	for(int i = k; i < n; i++){
		s[i] = '1';
		if(v < a[i]){
			v--;
		}
	}
	return v >= 0;
}

void solve(){
	cin >> n >> q;
	for(int i = 0; i < n; i++) cin >> a[i];
	s.resize(n);
	int ans = n;
	int v = q;
	int l = 0, r = n;
	while(l != r){
		int m = (l + r) / 2;
		if(test(m, q)){
			r = m;
		}else{
			l = m + 1;
		}
	}
	test(l, q);
	cout << s << endl;
}

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}