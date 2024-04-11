#include <bits/stdc++.h>
using namespace std;
#define int long long

int A[100000];
map<int, int> cnt;
void sub(){
	cnt.clear();
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		cin >> A[i];
		cnt[A[i]]++;
	}
	sort(A, A + m);
	int sum = accumulate(A, A + m, 0LL);
	if(sum < n){
		cout << -1 << endl;
		return;
	}
	int ans = 0;
	for(int i = 0; i <= 60; i++){
		if(n & (1LL << i)){
			if(cnt.find(1LL << i) == cnt.end() || cnt[(1LL << i)] == 0){
				int id = cnt.upper_bound((1LL << i)) -> first;
				while(id != (1LL << i)){
					ans++;
					cnt[id]--;
					cnt[id >> 1] += 2;
					id >>= 1; 
				}
			}
			cnt[1LL << i]--;
		}
		if(cnt.find(1LL << i) != cnt.end()) cnt[1LL << (i + 1)] += cnt[1LL << i] / 2;
	}
	cout << ans << endl;
}

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		sub();
	}
}