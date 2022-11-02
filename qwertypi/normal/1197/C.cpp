#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

int A[300000];
int diff[299999];

int main(){
	int n, k;
	cin >> n >> k;
	for(int i=0;i<n;i++){
		cin >> A[i];
	}
	for(int i=0;i<n-1;i++){
		diff[i] = A[i+1] - A[i];
	}
	sort(diff, diff+n-1);
	int ans = accumulate(diff, diff+n-k,0);
	cout << ans;
	return 0;
}