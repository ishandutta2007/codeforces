#include <bits/stdc++.h>

using namespace std;

#define int long long

int A[100001];
int _max[100001];
void sub(){
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> A[i];
	}
	
	for(int i = 1; i <= n; i++){
		_max[i] = max(A[i], _max[i - 1]);
	}
	
	int r = n, r_bound = n;
	while(r_bound != 0){
		while(r >= 0){
			if(_max[r] != _max[r_bound]){
				for(int j = r + 1; j <= r_bound; j++){
					cout << A[j] << ' ';
				}
				r_bound = r;
				break;
			}
			r--;
		}
	}
	cout << endl;
}

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		sub();
	}
}