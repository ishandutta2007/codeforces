#include <bits/stdc++.h>

using namespace std;

int A[1000];
void sub(){
	int n;
	cin >> n;
	int pos = 0, neg = 0, cnt = 0;
	for(int i = 0; i < n; i++){
		cin >> A[i];
		if(A[i] >= 0){
			pos += A[i];
		}else{
			neg -= A[i];
			cnt++; 
		} 
	}
	sort(A, A + n);
	
	if(pos == neg){
		cout << "NO" << endl;
	}else{
		cout << "YES" << endl;
		if(pos > neg){
			for(int i = n - 1; i >= cnt; i--){
				cout << A[i] << ' ';
			}
			for(int i = 0; i < cnt; i++){
				cout << A[i] << ' ';
			}
		}else{
			for(int i = 0; i < cnt; i++){
				cout << A[i] << ' ';
			}
			for(int i = n - 1; i >= cnt; i--){
				cout << A[i] << ' ';
			}
		}
		cout << endl;
	}
}

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		sub();
	}
}