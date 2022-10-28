#include "bits/stdc++.h"
using namespace std;
const int N = 195;
int n , k;
int arr[N][N];
int main(){
	cin >> n >> k;
	if(k > n * n){
		cout << -1 << endl;
		return 0;
	}
	for(int i = 1 ; i <= n && k ; ++i){
		arr[i][i] = 1;
		--k;		
		for(int j = i + 1 ; j <= n && k > 1 ; ++j){
			arr[i][j] = 1;
			arr[j][i] = 1;
			k -= 2;
		}
	}
	if(k){
		cout << -1 << endl;
	}
	else{
		for(int i = 1 ; i <= n ; ++i){
			for(int j = 1 ; j <= n ; ++j){
				cout << arr[i][j] << " ";
			}
			cout << endl;
		}
	}
}