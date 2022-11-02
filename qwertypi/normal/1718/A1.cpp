#include <bits/stdc++.h>

using namespace std;

int n;
int a[100002];
int s[100002];
void solve(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	int ans = n;
	for(int i = 0; i < n; i++){
		s[i + 1] = s[i] ^ a[i];
	}
	set<int> S {0};
	for(int i = 0; i < n; i++){
		if(S.count(s[i + 1])){
			ans--;
			S.clear();
			S.insert(s[i + 1]);
		}else{
			S.insert(s[i + 1]);
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