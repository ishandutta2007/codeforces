#include <bits/stdc++.h>
 
using namespace std;

int a[10001];

void solve(){
	int n, k;
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	int s = accumulate(a, a + n, 0LL);
	cout << (s == 0 ? "NO" : "YES") << endl;
}
 
int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}