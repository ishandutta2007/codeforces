#include <iostream>

#define N 110

using namespace std;

int arr[N];
int n,m;

int main() {
	int i,j;
	cin >> n;
	for(i=1;i<=n;i++) {
		cin >> arr[i];
	}
	cin >> m;
	while(m--) {
		int a,b;
		cin >> a >> b;
		if(a > 1) {
			arr[a-1] += b-1;
		}
		if(a < n) {
			arr[a+1] += arr[a]-b;
		}
		arr[a] = 0;
	}
	for(i=1;i<=n;i++)
		cout << arr[i] << endl;
	return 0;
}