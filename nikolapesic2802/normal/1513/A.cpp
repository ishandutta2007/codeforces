#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t, n, k, j;
	cin >> t;
	for(int i=0; i<t; i++){
		cin >> n >> k;
		if(k==0){
			for(j=1; j<=n; j++)  cout << j << " ";
		}
		else if(n <= 2*k) cout << -1;
		else{
			int arr[n];
			for(j=0; j<n; j++)  arr[j]=j+1;
			for(j=0; j<2*k; j=j+2)  swap(arr[n-j-1], arr[n-j-2]);
			for(j=0; j<n; j++)  cout << arr[j] << " ";
		}
		cout << "\n";
	}
	return 0;
}