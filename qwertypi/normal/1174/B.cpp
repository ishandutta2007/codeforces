#include <iostream>
#include <numeric>
#include <algorithm>
using namespace std;
int A[100000];
int main(){
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> A[i];
	}
	int cnt = 0;
	for(int i=0;i<n;i++){
		cnt += A[i] % 2;
	}
	if(cnt == 0 || cnt == n){
		for(int i=0;i<n;i++){
			cout << A[i] << ' ';
		}
		return 0;
	}
	sort(A, A+n);
	for(int i=0;i<n;i++){
		cout << A[i] << ' ';
	}
	return 0;
}