#include <bits/stdc++.h>
#define int long long 
using namespace std;

int A[200000];
int prec[200000];
int32_t main(){
	int n, k;
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	sort(A, A + n);
	for(int i = 0; i < k; i++){
		prec[i] = A[i];
	}
	for(int i = k; i < n; i++){
		prec[i] = prec[i - k] + A[i];
	}
	int _max = 0;
	for(int i = 0; i < n; i++){
		_max += prec[i];
		cout << _max << ' ';
	}
}