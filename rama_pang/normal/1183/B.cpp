#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define db(x) cout << ">>>>>>>>>>>>>" << #x << " "<< x << endl
#define IOS ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main (){
	int q;
	cin>>q;
	while (q--){
		int n,k;
		cin>>n>>k;
		vector<int> arr(n,0);
		for (int i = 0; i <n; i++){
			cin >> arr[i];
		}
		sort(arr.begin(),arr.end());
		if (arr[n-1]-arr[0]<=2*k){
			cout << arr[0]+k << endl;
		} else{
			cout << -1 << endl;
		}
	}
	
}