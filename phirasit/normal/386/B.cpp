#include <iostream>
#include <algorithm>

#define N 110

using namespace std;

int arr[N];
int n,t;

int main() {
	int i,j;
	cin >> n;
	for(i=0;i<n;i++) {
		cin >> arr[i];
	}
	cin >> t;
	sort(arr,arr+n);
	int ans = 0;
	for(i=j=0;i<n;i++) {
		while(j == 0 || (j < n && arr[j]-arr[i] <= t)) j++;
		if(j-i > ans) ans = j-i;
	}
	cout << ans << endl;
	return 0;
}