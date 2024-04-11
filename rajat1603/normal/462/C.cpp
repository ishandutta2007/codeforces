#include "bits/stdc++.h"
using namespace std;
const int N = 3e5 + 5;
long long ans = 0;
long long sum = 0;
int n;
int arr[N];
int main(){
	cin >> n;
	for(int i = 1 ; i <= n ; ++i){
		cin >> arr[i];
		sum += arr[i];
	}
	sort(arr + 1 , arr + 1 + n);
	ans = sum;
	for(int i = 1 ; i < n ; ++i){
		ans += sum;
		sum -= arr[i];
	}
	cout << ans;
}