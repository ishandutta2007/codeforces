#include <iostream>

#define N 100010

using namespace std;

int arr[N],n;

int main() {
	int i,j;
	cin >> n;
	for(i=0;i<n;i++) {
		cin >> arr[i];
	}
	int ans = arr[0] + n;
	for(i=1;i<n;i++) {
		j = arr[i]-arr[i-1];
		if(j < 0) j = -j;
		ans += j + 1;
	}
	cout << ans << endl;
	return 0;
}