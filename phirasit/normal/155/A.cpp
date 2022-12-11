#include <iostream>

#define INF (-1u/2)
#define N 1010

using namespace std;

int arr[N];
int n;

int main() {
	int i,j;
	cin >> n;
	int ans = 0,mn = INF,mx = -INF;
	for(i=1;i<=n;i++) {
		cin >> arr[i];
		if(arr[i] > mx || arr[i] < mn) ans++;
		if(arr[i] > mx) mx = arr[i];
		if(arr[i] < mn) mn = arr[i];
	}
	cout << ans-1 << endl;
	return 0;
}