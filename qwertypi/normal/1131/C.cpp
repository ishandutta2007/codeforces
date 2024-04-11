#include <iostream>
#include <algorithm>
using namespace std;
int A[100]; 
int main(){
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> A[i];
	}
	sort(A, A+n);
	for(int i=0;i<n;i+=2){
		cout << A[i] << ' ';
	}
	int ind = n % 2 == 0 ? n-1 : n-2;
	for(int i=ind; i>=0; i-=2){
		cout << A[i] << ' ';
	}
	return 0;
}