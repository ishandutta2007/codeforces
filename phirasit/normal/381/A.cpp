#include <iostream>

#define N 1010

using namespace std;

int arr[N];
int n;

int main() {
	int i,j;
	int sum = 0;
	cin >> n;
	for(i=0;i<n;i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	int a=0,b=n-1;
	int ans = 0;
	bool turn = true;
	while(a <= b) {
		if(arr[a] > arr[b]) {
			if(turn) 
				ans += arr[a];
			a++;
		}else {
			if(turn)
				ans += arr[b];
			b--;
		}
		turn = !turn;
	}
	cout << ans << " " << sum-ans << endl;
	return 0;
}