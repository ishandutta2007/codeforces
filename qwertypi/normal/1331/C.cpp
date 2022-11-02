#include <bits/stdc++.h>

using namespace std;

int A[6];
int B[6];
int main(){
	int n;
	cin >> n;
	for(int i = 0; i < 6; i++){
		A[i] = n % 2;
		n /= 2;
	}
	B[0] = A[4];
	B[1] = A[1];
	B[2] = A[3];
	B[3] = A[2];
	B[4] = A[0];
	B[5] = A[5];
	int m = 0;
	for(int i = 0; i < 6; i++){
		m += B[i] * (1 << i);
	}
	cout << m << endl;
}