#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	int arr[n];
	for(int j = 0;j<n;j++)cin >> arr[j];
	int ans = 0;
	for(int j = 1;j<n-1;j++){
		if((arr[j]<arr[j-1]&&arr[j]<arr[j+1])||(arr[j]>arr[j-1]&&arr[j]>arr[j+1]))ans++;
	}
	cout << ans << "\n";
	return 0;
}