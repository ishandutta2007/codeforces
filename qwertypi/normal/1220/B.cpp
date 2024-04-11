#include <bits/stdc++.h>

using namespace std;
#define int long long
int A[1000][1000];
int32_t main(){
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin >> A[i][j];
		} 
	}
	int gcd = 0;
	for(int i=0;i<n;i++){
		gcd = __gcd(gcd, A[0][i]);
	}
	int se = A[0][1] / gcd;
	int th = A[0][2] / gcd;
	int mul = (int)sqrt(A[1][2] / (se * th));
	int _0 = gcd / mul;
	cout << _0 << ' ';
	for(int i=1;i<n;i++){
		cout << A[0][i] / _0 << ' ';
	} 
}