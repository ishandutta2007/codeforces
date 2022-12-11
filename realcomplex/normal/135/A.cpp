#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair

int main(){
	int n;
	cin >> n;
	int arr[n];
	pair<int,int>big;
	big = mp(0,0);
	for(int j = 0;j<n;j++){
		cin >> arr[j];
		big = max(big,mp(arr[j],j));
	}
	arr[big.se] =((big.fi==1)?arr[big.se]=2:arr[big.se]=1);
	sort(arr,arr+n);
	for(int i = 0;i<n;i++)
		cout << arr[i] << " ";
	cout << endl;
	return 0;
}