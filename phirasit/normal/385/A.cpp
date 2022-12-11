#include <iostream>

using namespace std;

int arr[110];
int n,c;

int main() {
	int i,j;
	cin >> n >> c;
	int mx = 0;
	for(i=0;i<n;i++) {
		cin >> arr[i];
		if(i > 0 && arr[i-1]-arr[i]-c > mx)
			mx = arr[i-1]-arr[i]-c;
	}
	cout << mx << endl;
	return 0;
}