#include <bits/stdc++.h>

// Pls don't give me expert
// Back to the origin in 2019...

using namespace std;

int c[100001];
void solve(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> c[i];
	}
	int uni = -1, cnt = 0;
	for(int i = 0; i < n; i++){
		if(c[i] == 1){
			uni = i;
			cnt++;
		}
	}
	if(cnt != 1){
		cout << "NO" << endl;
		return; 
	}
	
	for(int i = 0; i < n - 1; i++){
		int j = (i + uni) % n;
		if(c[(j + 1) % n] == 1 || c[(j + 1) % n] > c[j] + 1){
			cout << "NO" << endl;
			return;
		}
	}
	cout << "YES" << endl;
}

int main(){
	int t = 1;
	cin >> t;
	while(t--){
		solve();
	}
}