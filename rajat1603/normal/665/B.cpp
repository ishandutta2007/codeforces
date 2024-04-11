#include "bits/stdc++.h"
using namespace std;
const int N = 105;
int n , m , k;
int arr[N];
int inp;
int ans = 0;
int main(){
	cin >> n >> m >> k;
	for(int i = 1 ; i <= k ; ++i){
		cin >> arr[i];
	}
	for(int i = 1 ; i <= n ; ++i){
		for(int j = 1 ; j <= m ; ++j){
			cin >> inp;
			for(int l = 1 ; l <= k ; ++l){
				if(arr[l] == inp){
					ans += l;
					for(int x = l ; x >= 2 ; --x){
						swap(arr[x] , arr[x - 1]);
					}
					arr[1] = inp;
					break;
				}
			}
		}
	}
	cout << ans;
}