#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int n,k;
	cin >> n >> k;
	ll arr[n];
	for(int j = 0;j<n;j++)cin >> arr[j];
	sort(arr,arr+n);
	ll s = 0;
	int l = 0;
	ll ans = 0;
	ll sk = INT_MAX;
	for(int j = 0;j<n;j++){
		if(j==0){
			ans = 1;
			sk = arr[j];
		}
		else{
			s += (arr[j]-arr[j-1])*(j-l);
			while(l<j&&s>k){
				s-=arr[j]-arr[l];
				l++;
			}
			if(j-l+1>ans||(ans==j-l+1&&arr[j]<sk))
				sk = arr[j],ans = j-l+1;
		}
	}
	cout << ans << " " << sk << "\n";
	return 0;
}