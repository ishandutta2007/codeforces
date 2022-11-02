#include <bits/stdc++.h>

#define int long long
using namespace std;

int w[100000];
int cnt[100000];
void sub(){
	multiset<int> S;
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> w[i];
		cnt[i] = -1;
	}
	
	for(int i = 0; i < n - 1; i++){
		int u, v;
		cin >> u >> v;
		u--, v--;
		cnt[u]++, cnt[v]++;
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < cnt[i]; j++){
			S.insert(w[i]);
		}
	}
	
	int ans = 0;
	for(int i = 0; i < n; i++){
		ans += w[i];
	}
	cout << ans << ' ';
	for(int i = 0; i < n - 2; i++){
		int val = *--S.end();
		S.erase(--S.end());
		ans += val;
		cout << ans << ' ';
	}
	cout << endl;
}

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		sub();
	}
}