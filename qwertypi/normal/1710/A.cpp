#include <bits/stdc++.h>
#define int long long
using namespace std;
 
int a[100001];
void solve(){
	int n, m, k;
	cin >> n >> m >> k;
	for(int i = 0; i < k; i++){
		cin >> a[i];
	}
	{
		int a1 = 0, b1 = 0;
		for(int i = 0; i < k; i++){
			int c = a[i] / n;
			if(c >= 2) a1 += c, b1 += c - 2;
		}
		if(a1 >= m && (b1 != 0 || a1 % 2 == m % 2)){
			cout << "Yes" << endl;
			return;
		}
	}
	{
		int a2 = 0, b2 = 0;
		for(int i = 0; i < k; i++){
			int c = a[i] / m;
			if(c >= 2) a2 += c, b2 += c - 2;
		}
		if(a2 >= n && (b2 != 0 || a2 % 2 == n % 2)){
			cout << "Yes" << endl;
			return;
		}
	}
	cout << "No" << endl;
}
 
int32_t main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}