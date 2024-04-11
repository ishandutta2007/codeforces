#include <bits/stdc++.h>
#define int long long
using namespace std;

int d[200001];
int a[200001];
void solve(){
	int n;
	cin >> n;
	for(int i = 0; i < n * 2; i++) cin >> d[i];
	sort(d, d + n * 2);
	for(int i = 0; i < n; i++){
		if(d[i * 2] != d[i * 2 + 1]){
			cout << "NO" << endl;
			return;
		}
	}
	for(int i = 0; i < n / 2; i++){
		swap(d[i * 2], d[(n - 1 - i) * 2]);
	}
	for(int i = 0; i < n - 1; i++){
		if((d[i * 2] - d[(i + 1) * 2]) % ((n - (i + 1)) * 2) != 0 || d[i * 2] == d[(i + 1) * 2]){
			cout << "NO" << endl;
			return;
		}
	}
	for(int i = n - 2; i >= 0; i--){
		a[i] = a[i + 1] + -(d[(i + 1) * 2] - d[i * 2]) / ((n - (i + 1)) * 2);
	}
	/*
	for(int i = 0; i < n; i++){
		cout << a[i] << ' ';
	}
	cout << endl;
	*/
	int dis = 0;
	for(int i = 1; i < n; i++){
		a[i] -= a[0];
	}
	a[0] = 0;
	for(int i = 0; i < n - 1; i++){
		dis += abs(a[i] - a[n - 1]);
	}
	dis *= 2;
	// cout << d[(n - 1) * 2] << ' ' << dis << endl;
	if(dis >= d[(n - 1) * 2] || (d[(n - 1) * 2] - dis) % (n * 2) != 0){
		cout << "NO" << endl;
		return;
	}
	cout << "YES" << endl;
	return;
}

int32_t main(){
	int t; cin >> t;
	while(t--) solve();
}