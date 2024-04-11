#include <bits/stdc++.h>
#define int long long
using namespace std;

int s[100011], a[100001];

void solve(){
	int n, k;
	cin >> n >> k;
	for(int i = n - k; i < n; i++)
		cin >> s[i];
	
	if(k == 1){
		cout << "Yes" << endl;
		return;
	}
	
	for(int i = n - k + 1; i < n; i++){
		a[i] = s[i] - s[i - 1];
	}
	
	for(int i = n - k + 1; i < n - 1; i++){
		if(a[i] > a[i + 1]){
			cout << "No" << endl;
			return;
		}
	}
	
	if(s[n - k + 1] > (n - k + 2) * a[n - k + 1]){
		cout << "No" << endl;
	}else{
		cout << "Yes" << endl;
	}
}

int32_t main(){
	int t = 1;
	cin >> t;
	while(t--){
		solve();
	}
}