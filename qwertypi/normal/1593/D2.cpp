#include <bits/stdc++.h>

using namespace std;

int A[41];

vector<int> factor(int x){
	x = abs(x);
	if(x == 0) return {};
	vector<int> res {1};
	map<int, int> M;
	for(int i = 2; i * i <= x; i++){
		while(x % i == 0){
			M[i]++;
			x /= i;
		}
	}
	if(x != 1) M[x]++;
	for(auto i : M){
		int v = res.size();
		for(int j = 0; j < i.second; j++){
			for(int k = 0; k < v; k++){
				res.push_back(res[j * v + k] * i.first);
			}
		}
	}
	return res;
}

int ans = 1;
int n;
void test(int k){
	map<int, int> M;
	for(int i = 0; i < n; i++){
		M[(A[i] % k + k) % k]++;
	}
	for(auto i : M){
		if(i.second >= n / 2){
			ans = max(ans, k);
		}
	}
}

void solve(){
	ans = 1;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	sort(A, A + n);
	map<int, int> M;
	for(int i = 0; i < n; i++) M[A[i]]++;
	for(auto i : M){
		if(i.second >= n / 2){
			cout << -1 << endl;
			return;
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			if(A[i] != A[j]){
				for(auto k : factor(A[i] - A[j])){
					test(k);
				}
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