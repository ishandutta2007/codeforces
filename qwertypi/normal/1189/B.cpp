#include <iostream>
#include <algorithm>
using namespace std;
int A[100000];
int res[100000];
int main(){
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> A[i];
	}
	sort(A, A+n);
	int L = (n - 1) / 2;
	int R = (n - 1) / 2 + 1;
	int i = 0;
	while(i < n - 1){
		res[L--] = A[i++];
		res[R++] = A[i++];
	}
	if(i != n){
		res[L--] = A[i++];
	}
	for(int i=1;i<n-1;i++){
		if(res[i] >= res[i-1] + res[i+1]){
			cout << "NO";
			return 0; 
		}
	}
	if(res[0] >= res[n-1] + res[1]){
		cout << "NO";
		return 0; 
	}
	if(res[n-1] >= res[n-2] + res[0]){
		cout << "NO";
		return 0; 
	}
	cout << "YES" << endl;
	for(int i=0;i<n;i++){
		cout << res[i] << ' ';
	}
	return 0;
}