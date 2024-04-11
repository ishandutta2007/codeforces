#include <bits/stdc++.h>
using namespace std;
 
int A[100000];
int prec[100001];
bool OK[100000];
void sub(void){
	int n, k;
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	if(n == 1){
		cout << (k == A[0] ? "yes": "no") << endl;
		return;
	}
	vector<int> check;
	for(int i = 0; i < n; i++){
		if(A[i] == k){
			check.push_back(i);
		}
 	}
 	if(check.size() == 0){
 		cout << "no" << endl;
 		return;
	}
	for(int i = 0; i < n - 1; i++){
		if(A[i] >= k && A[i + 1] >= k){
			cout << "yes" << endl;
			return;
		}
	}
	for(int i = 0; i < n - 2; i++){
		if(A[i] >= k && A[i + 2] >= k){
			cout << "yes" << endl;
			return;
		}
	}
	cout << "no" << endl;
}
 
int32_t main(){
	int t;
	cin >> t;
	while(t--){
		sub();
	}
	return 0;
}