#include <bits/stdc++.h>

using namespace std;

int A[100];
int32_t main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		for(int i = 0; i < n; i++){
			cin >> A[i];
		}
		sort(A, A + n, [](int a, int b){
			return a > b;
		});
		for(int i =  0; i < n; i++){
			cout << A[i] << ' '; 
		}
		cout << endl;
	}
}