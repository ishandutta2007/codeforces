#include <bits/stdc++.h>
#define int long long
using namespace std;

// RE: START!

int A[100001];

void out(int a, int b, int c, int d){
	cout << a + 1 << ' ' << b + 1 << ' ' << c << ' ' << d << endl; 
}
int32_t main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		for(int i = 0; i < n; i++){
			cin >> A[i];
		}
		int idx = -1, _min = (1 << 30);
		for(int i = 0; i < n; i++){
			if(A[i] < _min){
				_min = A[i];
				idx = i;
			}
		}
		cout << n - 1 << endl;
		for(int i = 0; i < n; i++){
			if(i != idx){
				bool parity = (i - idx) % 2 == 0;
				if(parity){
					out(i, idx, A[idx], A[idx]);
				}else{
					out(i, idx, A[idx] + 1, A[idx]);
				}
			}
		}
	}	
}