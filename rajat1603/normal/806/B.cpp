#include "bits/stdc++.h"
using namespace std;
const int N = 150;
int n;
int a[N][10];
int sum[10];
int get(int x , int y){
	if(2 * x > y){
		return 500;
	}
	if(4 * x > y){
		return 1000;
	}
	if(8 * x > y){
		return 1500;
	}
	if(16 * x > y){
		return 2000;
	}
	if(32 * x > y){
		return 2500;
	}
	return 3000;
}
bool check(int sub){
	long long tot1 = 0;
	long long tot2 = 0;
	for(int i = 1 ; i <= 5 ; ++i){
		if(a[1][i] == -1){
			if(a[2][i] >= 0){
				tot2 += get(sum[i] , n + sub) * (250 - a[2][i]);
			}
			continue;
		}
		if(a[2][i] == -1){
			tot1 += get(sum[i] , n + sub) * (250 - a[1][i]);
			continue;
		}
		if(a[1][i] == a[2][i]){
			continue;
		}
		if(a[1][i] < a[2][i]){
			tot1 += get(sum[i] , n + sub) * (250 - a[1][i]);
			tot2 += get(sum[i] , n + sub) * (250 - a[2][i]);
		}
		if(a[1][i] > a[2][i]){
			tot1 += get(sum[i] + sub , n + sub) * (250 - a[1][i]);
			tot2 += get(sum[i] + sub , n + sub) * (250 - a[2][i]);
		}
	}
	return tot1 > tot2;
}
int main(){
	cin >> n;
	memset(sum , 0 , sizeof(sum));
	for(int i = 1 ; i <= n ; ++i){
		for(int j = 1 ; j <= 5 ; ++j){
			cin >> a[i][j];
			if(a[i][j] >= 0){
				++sum[j];
			}
		}
	}
	for(int i = 0 ; i <= 100000 ; ++i){
		if(check(i)){
			cout << i << endl;
			return 0;
		}
	}
	cout << -1 << endl;
}