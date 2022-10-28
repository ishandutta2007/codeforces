#include "bits/stdc++.h"
using namespace std;
const int N = 105;
int n;
double arr[N];
double res;
int main(){
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%lf" , arr + i);
	}
	sort(arr + 1 , arr + 1 + n);
	if(arr[n] >= 0.5){
		res = arr[n];
	}
	else{
		res = 0;
		for(int i = 1 ; i <= n ; ++i){
			double sum = 0;
			for(int j = i ; j <= n ; ++j){
				double prod = 1;
				for(int k = i ; k <= n ; ++k){
					if(k == j){
						prod *= arr[k];
					}
					else{
						prod *= 1 - arr[k];
					}
				}
				sum += prod;
			}
			res = max(res , sum);
		}
	}
	printf("%.9lf\n" , res);
}