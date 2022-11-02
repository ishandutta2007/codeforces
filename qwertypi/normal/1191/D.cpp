#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;
 
int A[100000];
int diff[99999];
int main(){
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> A[i];
	}
	sort(A, A+n);
	if(n == 1){
		if(A[0] % 2 == 1){
			cout << "sjfnb";
		}else{
			cout << "cslnb";
		}
		return 0;
	}
	if(accumulate(A, A+n, 0LL) == 0LL){
		cout << "cslnb";
		return 0;
	}
	for(int i=0;i<n-1;i++){
		diff[i] = A[i+1] - A[i];
	}
	int cnt = 0;
	for(int i=0;i<n-1;i++){
		cnt += diff[i] == 0;
	}
	if(cnt >= 2){
		cout << "cslnb";
	}else if(cnt == 0){
		long long rounds = accumulate(A, A+n, 0LL) - (long long)n * (n-1) / 2;
		if(rounds % 2 == 1){
			cout << "sjfnb";
		}else{
			cout << "cslnb";
		}
	}else{
		int val = -1;
		for(int i=0;i<n-1;i++){
			if(diff[i] == 0){
				val = i;
			}
		}
		
		if(A[val] == 0 || (val != 0 && A[val] - 1 == A[val-1])){
			cout << "cslnb";
		}else{
			long long rounds = accumulate(A, A+n, 0LL) - (long long)n * (n-1) / 2;
			if(rounds % 2 == 1){
				cout << "sjfnb";
			}else{
				cout << "cslnb";
			}
		}
	}
	return 0;
}