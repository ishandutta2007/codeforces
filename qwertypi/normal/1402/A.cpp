#include <bits/stdc++.h>

#define int long long

using namespace std;

int A[100000], P[100000], Q[100000];

int c1[100001], c2[100001];

int32_t main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	
	for(int i = 0; i < n; i++){
		c1[i] = c2[i] = (1LL << 60);
	}
	
	c1[1] = -1;
	c2[1] = 1;
	for(int i = 1; i < n; i++){
		P[i] = c1[1] * A[i] * (n);
		Q[i] = c2[1] * A[i] * (n - 1);
	}
	int a = n, b = 1, c = n - 1;
	
	if(n == 1){
		cout << 1 << ' ' << 1 << endl;
		cout << 0 << endl;
		cout << 1 << ' ' << 1 << endl;
		cout << 0 << endl;
		cout << 1 << ' ' << 1 << endl;
		cout << -A[0] << endl;
		return 0;
	}
	cout << 1 << ' ' << n << endl;
	cout << 0 << ' ';
	for(int i = 1; i < n; i++){
		cout << P[i] << ' ';
	}
	cout << endl;
	cout << 1 << ' ' << 1 << endl;
	cout << -A[0] << ' ';
	cout << endl;
	cout << 2 << ' ' << n << endl;
	for(int i = 1; i < n; i++){
		cout << Q[i] << ' ';
	}
	cout << endl;
}