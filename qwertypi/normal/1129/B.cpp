#include <bits/stdc++.h>

using namespace std;

int A[2001];
int main(){
	int k;
	cin >> k;
	int N = (k % 2 ? 1999 : 2000);
	int S = (N + k) / 2;
	A[0] = 0, A[1] = -1;
	for(int i = 2; i < N; i++){
		A[i] = min(S, 1000000);
		S -= A[i];
	}
	cout << N << endl;
	for(int i = 0; i < N; i++){
		cout << A[i] << ' ';
	}
	cout << endl;
}