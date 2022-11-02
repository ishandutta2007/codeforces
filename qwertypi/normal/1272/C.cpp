#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define set unordered_set
#define map unordered_map
using namespace std;

int f(int x){
	return x * (x + 1) / 2;
}

int32_t main(){
	int n, k;
	cin >> n >> k;
	string s;
	set<char> S;
	cin >> s;
	for(int i = 0; i < k; i++){
		char c;
		cin >> c; 
		S.insert(c);
	}
	int cnt = 0;
	int ans = 0;
	for(int i = 0; i < n; i++){
		if(S.find(s[i]) != S.end()){
			cnt++;
		}else{
			ans += f(cnt);
			cnt = 0;
		}
	}
	ans += f(cnt);
	cout << ans << endl;
	return 0;
}