#include <bits/stdc++.h>

using namespace std;

int s[200001];
int sum(int l, int r){
	return s[r + 1] - s[l];
}

void solve(){
	int n;
	cin >> n;
	string S;
	cin >> S;
	for(int i = 0; i < n; i++){
		s[i + 1] = s[i] + (S[i] == '+' ? 1 : -1);
	}
	int ans = 0;
	for(int i = 0; i < n; i++){
		for(int j = i; j < n; j++){
			if(sum(i, j) % 3 == 0 && sum(i, j) <= 0){
				ans++;
			}
		}
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