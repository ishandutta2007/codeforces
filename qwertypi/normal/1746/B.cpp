#include <bits/stdc++.h>

using namespace std;

int a[100001];
int s[100001];
void solve(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int i = 0; i < n; i++){
		s[i + 1] = s[i] + a[i];
	}
	int ans = n;
	for(int i = -1; i < n; i++){
		int c1 = s[i + 1];
		int c2 = n - (i + 1) - (s[n] - s[i + 1]);
		ans = min(ans, max(c1, c2));
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