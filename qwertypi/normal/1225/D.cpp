#include <bits/stdc++.h>
#define int long long
using namespace std;
 
int A[100001];
 
int p = 998424323, q = 15829583, mod = 1e9 + 7;
 
int n, k;
pair<int, int> _hash(map<int, int> M){
	int hash1 = 0, hash2 = 0;
	for(auto i : M){
		i.second %= mod;
		if(i.second == 0) continue;
		hash1 = hash1 * p % mod * p % mod + i.first * p % mod + i.second;
		hash2 = hash2 * q % mod * q % mod + i.first * q % mod + i.second;
		hash1 %= mod;
		hash2 %= mod;
	}
	return {hash1, hash2};
}
 
map<pair<int, int>, int> M;
int32_t main(){
	cin >> n >> k;
	int ans = 0;
	for(int i = 0; i < n; i++){
		cin >> A[i];
		map<int, int> cnt;
		for(int j = 2; j * j <= A[i]; j++){
			while(A[i] % j == 0) A[i] /= j, cnt[j]++;
		}
		if(A[i] != 1) cnt[A[i]]++;
		for(auto& i : cnt){
			i.second %= k;
		}
		map<int, int> inv_cnt;
		for(auto i : cnt){
			inv_cnt[i.first] = (k - i.second) % k;
		}
		pair<int, int> h = _hash(cnt), hi = _hash(inv_cnt);
		ans += M[hi];
		M[h]++;
	}
	cout << ans << endl;
}