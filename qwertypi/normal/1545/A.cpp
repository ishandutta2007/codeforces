#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;

int mod = 998244353;
int powmod(int a, int b){
	int res = 1;
	while(b){
		if(b % 2){
			res = (res * a) % mod;
		}
		b /= 2;
		a = (a * a) % mod;
	}
	return res;
}

int A[100000], B[100000];
int odd[100000], even[100000];
void sub(){
	cin.tie(0);
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> A[i];
		if(i % 2) odd[i / 2] = A[i];
		if(i % 2 == 0) even[i / 2] = A[i];
	}
	sort(odd, odd + n / 2);
	sort(even, even + n / 2 + n % 2);
	for(int i = 0; i < n; i++){
		A[i] = (i % 2 ? odd[i / 2] : even[i / 2]);
		B[i] = A[i];
	}
	sort(B, B + n);
	
	for(int i = 0; i < n; i++){
		if(A[i] != B[i]){
			cout << "NO" << endl;
			return ;
		}
	}
	cout << "YES" << endl;
}

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		sub();
	}
}