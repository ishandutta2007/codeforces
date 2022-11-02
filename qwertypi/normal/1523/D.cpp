#include <bits/stdc++.h>
#define int long long
using namespace std;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int A[200001];
int B[200001];
int dp[1 << 15];
int cnt[1 << 15];
int32_t main(){
	int n, m, p;
	cin >> n >> m >> p;
	for(int i = 0; i < n; i++){
		string s;
		cin >> s;
		int v = 0;
		for(int j = 0; j < m; j++){
			v += ((long long) (s[j] == '1')) << j;
		}
		A[i] = v;
	}
	int ans = 0;
	for(int iter = 0; iter < 30; iter++){
		fill(cnt, cnt + (1 << 15), 0);
		int idx = rng() % n;
		vector<int> bits;
		for(int i = 0; i < m; i++){
			if(A[idx] & (1LL << i)) bits.push_back(i);
		}
		for(int i = 0; i < n; i++){
			int v = 0;
			for(int j = 0; j < bits.size(); j++){
				v += ((A[i] & (1LL << bits[j])) > 0) * (1LL << j);
			}
			B[i] = v;
			cnt[v]++;
		}
		for(int i = 0; i < (1 << p); i++) dp[i] = 0;
		for(int i = 0; i < (1 << p); i++){
			for(int s = i; s; s = (s - 1) & i){
				dp[s] += cnt[i];
			}
		}
		int res = 0;
		for(int i = 0; i < (1 << p); i++){
			if(dp[i] >= (n + 1) / 2 && __builtin_popcountll(res) < __builtin_popcountll(i)) res = i;
		}
		int rres = 0;
		for(int i = 0; i < bits.size(); i++){
			if(res & (1LL << i)) rres |= (1LL << bits[i]);
		}
		if(__builtin_popcountll(rres) > __builtin_popcountll(ans)) ans = rres;
	}
	for(int i = 0; i < m; i++){
		cout << ((ans & (1LL << i)) > 0);
	}
	cout << endl;
}