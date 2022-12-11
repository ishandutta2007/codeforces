#include <iostream>
#include <algorithm>

using namespace std;

int arr[110];
int n, k;

int main() {
	cin >> n >> k;
	for(int i = 0;i < n;i++) {
		cin >> arr[i];
	}
	sort(arr, arr+n);
	cout << arr[n-k] << endl;
	return 0;
}