#include <bits/stdc++.h>
using namespace std;
const int N = 20;
const double eps = -1e7;
int n , t;
double arr[N][N];
int ans = 0;
int main(){
	cin >> n >> t;
	for(int i = 0 ; i < N ; ++i){
		for(int j = 0 ; j < N ; ++j){
			arr[i][j] = 0;
		}
	}
	arr[1][1] = t;
	for(int i = 1 ; i <= n ; ++i){
		for(int j = 1 ; j <= i ; ++j){
			if(arr[i][j] >= 1){
				double extra = arr[i][j] - 1;
				arr[i + 1][j] += extra / 2;
				arr[i + 1][j + 1] += extra / 2;
				arr[i][j] = 1;
				++ans;
			}
		}
	}
	cout << ans;
}