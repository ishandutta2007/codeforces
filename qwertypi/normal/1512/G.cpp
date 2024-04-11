#include <bits/stdc++.h>
#define int long long
using namespace std;
#define N 10000001
int d[N];
int ans[N];
int32_t main(){
	for(int i = 1; i <= N; i++){
		for(int j = i; j <= N; j += i){
			d[j] += i;
		}
	}
	for(int i = 1; i <= N; i++){
		if(d[i] <= N && ans[d[i]] == 0) ans[d[i]] = i;
	}
	int t;
	cin >> t;
	while(t--){
		int n; cin >> n;
		cout << (ans[n] ? ans[n] : -1) << endl;
	}
}