#include "bits/stdc++.h"
using namespace std;
const int N = 1005;
int n;
int arr[N];
int k;
int main(){
	cin >> n;
	for(int i = 1 ; i <= n ; ++i){
		cin >> arr[i];
	}
	for(int i = 2 ; i <= n ; ++i){
		if(__gcd(arr[i] , arr[i - 1]) != 1){
			++k;
		}
	}
	cout << k << endl;
	cout << arr[1] << " ";
	for(int i = 2 ; i <= n ; ++i){
		if(__gcd(arr[i] , arr[i - 1]) != 1){
			cout << 1 << " ";
		}
		cout << arr[i] << " ";
	}
}