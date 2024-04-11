#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int n;
	cin >> n;
	int arr[n];
	for(int i = 0;i<n;i++)
		cin >> arr[i];
	sort(arr,arr+n);
	ll ans = arr[n-1];	
	for(int i = n-2;i>=0;i--){
		arr[i] = max(0,min(arr[i],arr[i+1]-1));
		ans += arr[i];
	}
	cout << ans << "\n";
	return 0;
}