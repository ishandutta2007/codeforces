#include <bits/stdc++.h>

using namespace std;

int a[100001], b[100001];

int ans = 0;
int n;
void check(int h){
	int v = ans + (1 << h);
	map<int, int> mp;
	for(int i = 0; i < n; i++){
		mp[(a[i] & ((1 << 30) - (1 << h))) & v]++;
	}
	
	for(int i = 0; i < n; i++){
		mp[((b[i] ^ v) & ((1 << 30) - (1 << h))) & v]--;
	}
	
	for(auto i : mp){
		if(i.second > 0){
			return;
		}
	}
	ans += (1 << h);
}

void solve(){
	cin >> n; ans = 0;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int i = 0; i < n; i++){
		cin >> b[i];
	}
	sort(a, a + n);
	sort(b, b + n);
	for(int h = 29; h >= 0; h--){
		check(h);
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