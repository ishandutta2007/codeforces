#include "bits/stdc++.h"
using namespace std;
const int N = 720720;
int n;
int m[20];
int r[20];
int ans = 0;
int main(){
	cin >> n;
	for(int i = 1 ; i <= n ; ++i){
		cin >> m[i];
	}
	for(int i = 1 ; i <= n ; ++i){
		cin >> r[i];
	}
	for(int i = 0 ; i < N ; ++i){
		bool ok = 0;
		for(int j = 1 ; j <= n ; ++j){
			ok |= ((i % m[j]) == r[j]);
		}
		ans += ok;
	}
	printf("%.6lf\n" , 1.0 * ans / N);
}