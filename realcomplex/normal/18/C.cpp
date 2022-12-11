#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+7;
int arr[N];

int main(){
	int n;
	cin >> n;
	for(int j = 1;j<=n;j++){
		cin >> arr[j];
		arr[j]+=arr[j-1];
	}	
	int ans = 0;
	for(int j = 1;j<n;j++){
		if(arr[j] == arr[n]-arr[j])ans++;
	}
	cout << ans << endl;
	return 0;
}