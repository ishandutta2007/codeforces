#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;

int mod = 1e9 + 7;
int powmod(int a, int b){
	int res = 1;
	while(b){
		if(a % 2){
			res = (res * a) % mod;
		}
		b /= 2;
		a = (a * a) % mod;
	}
	return res;
}

vector<int> A, B;
	
int n, k, o;

bool okay(int t){
	int l = 0, r = k - 1;
	for(int i = 0; i < n; i++){
		while(l < k && abs(A[i] - B[l]) + abs(B[l] - o) > t) l++;
		if(l == k) return false;
		l++; 
	}
	return true;
}

void sub(){
	cin >> n >> k >> o;
	for(int i = 0; i < n; i++){
		int v; cin >> v;
		A.push_back(v);
	}
	sort(A.begin(), A.end());
	for(int i = 0; i < k; i++){
		int v; cin >> v;
		B.push_back(v);
	}
	sort(B.begin(), B.end());
	int l = 0, r = (1LL << 32);
	while(l != r){
		int mid = (l + r) / 2;
		if(okay(mid)){
			r = mid;
		}else{
			l = mid + 1;
		}
	}
	cout << l << endl;
}

int32_t main(){
	int t = 1;
	// cin >> t;
	while(t--){
		sub();
	}
}