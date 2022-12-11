#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	int arr[n];
	for(int j = 0;j<n;j++){
		cin >> arr[j];
		if(arr[j]%arr[0]!=0){
			cout << -1 << "\n";
			exit(0);
		}
	}
	cout << n*2-1 << "\n";
	cout << arr[0] << " ";
	for(int j = 1;j<n;j++){
		cout << arr[j] << " " << arr[0] << " ";
	}
	return 0;
}