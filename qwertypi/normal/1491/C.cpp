#include <bits/stdc++.h>
#define int long long
using namespace std;

int A[200001];
int L[200001], R[200001];

void init(int n){
	for(int i = 0; i < n; i++){
		R[i] = i;
	}
	R[n] = n;
}

void remove(int x){
	R[x] = x + 1;
}

int n;

int root(int x){
	if(x >= n) return n + 1;
	if(x == R[x]) return x;
	return R[x] = root(R[x]);
}

void sub(){
	cin >> n;
	int ans = 0;
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	init(n);
	for(int i = 0; i < n; i++){
		if(A[i] >= n - i){
			ans += A[i] - (n - i);
			A[i] = n - i;
		}
		while(A[i] > 1){
			int _i = i;
			while(_i < n){
				int _next = _i + A[_i];
				A[_i] = max(1LL, A[_i] - 1);
				if(A[_i] == 1) remove(_i);
				_i = root(_next);
			}
			ans++;
		}
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