#include <iostream>

#define N 5010

using namespace std;

int arr[N];
int m;

int main() {
	int i,j;
	cin >> m;
	int mx = 0;
	while(m--) {
		cin >> i;
		arr[i]++;
		if(i > mx) mx = i;
	}
	int ans = 0;
	for(j=1;j<=mx;j++) {
		if(j < mx && arr[j] >= 2) ans += 2;
		else if(j == mx) ans += 1;
		else ans += arr[j];
	}
	cout << ans << endl;
	for(j=1;j<mx;j++) {
		if(arr[j]-- > 0) {
			cout << j << " ";
		}
	}
	for(j=mx;j>0;j--) {
		if(arr[j]-- > 0) {
			cout << j << " ";
		}
	}
	cout << endl;
	return 0;
}