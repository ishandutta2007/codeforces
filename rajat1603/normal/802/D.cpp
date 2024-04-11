#include "bits/stdc++.h"
using namespace std;
const int N = 250;
int t;
int arr[N];
int main(){
	scanf("%d" , &t);
	while(t--){
		for(int i = 0 ; i < N ; ++i){
			scanf("%d" , arr + i);
		}
		long long sum1 = 0;
		long long sum2 = 0;
		for(int i = 0 ; i < N ; ++i){
			sum1 += arr[i];
			sum2 += 1LL * arr[i] * arr[i];
		}
		double mean = sum1;
		mean /= N;
		double var = sum2;
		var /= N;
		var -= mean * mean;
		double univar = mean * (mean + 1);
		univar /= 3;
		double poivar = mean;
		double tmp = sqrt(univar * poivar);
		if(var >= tmp){
			printf("uniform\n");
		}
		else{
			printf("poisson\n");
		}
	}
}