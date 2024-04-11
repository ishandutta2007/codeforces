#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int n;
int arr[N];
int ans = 0;
void solve(){
	int pos1;
	int posn;
	for(int i = 1 ; i <= n ; ++i){
		if(arr[i] == 1){
			pos1 = i;
		}
		if(arr[i] == n){
			posn = i;
		}
	}
	ans = max(ans , abs(pos1 - posn));
}
int main(){
	cin >> n;
	for(int i = 1 ; i <= n ; ++i){
		cin >> arr[i];
	}
	for(int i = 1 ; i <= n ; ++i){
		for(int j = i + 1 ; j <= n ; ++j){
			swap(arr[i] , arr[j]);
			solve();
			swap(arr[i] , arr[j]);
		}
	}
	cout << ans;
}