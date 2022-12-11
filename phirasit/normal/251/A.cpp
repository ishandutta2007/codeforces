#include <iostream>
#include <algorithm>

#define N 100010

using namespace std;

int arr[N];
int n, d;

int main() {
	cin >> n >> d;
	for(int i = 0;i < n;i++) {
		cin >> arr[i];
	}
	sort(arr, arr+n);
	int b = 0;
	long long ans = 0ll;
	for(int a = 0;a < n;a++) {
		while(b+1 < n && arr[b+1] - arr[a] <= d) {
			b++;
		}
		long long dif = (long long) b - a;
		ans += dif * (dif-1) / 2;
	}
	cout << ans << endl;
	return 0;
}