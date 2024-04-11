#include "bits/stdc++.h"
using namespace std;
const int N = 1e3 + 3;
int n;
int arr[N];
int cnt1;
int main(){
	cin >> n;
	cnt1 = 0;
	for(int i = 1 ; i <= n ; ++i){
		cin >> arr[i];
		cnt1 += arr[i];
	}
	if(n == 1 && cnt1 == 0){
		cout << "NO\n";
		return 0;
	}
	if(n == 1 && cnt1 == 1){
		cout << "YES\n";
		return 0;
	}
	if(cnt1 != n - 1){
		cout << "NO\n";
	}
	else{
		cout << "YES\n";
	}
}