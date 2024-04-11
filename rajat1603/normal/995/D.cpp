#include "bits/stdc++.h"
using namespace std;
const int N = 1 << 20;
int n , r;
int arr[N];
long long sum;
int main(){
	scanf("%d %d" , &n , &r);
	for(int i = 0 ; i < (1 << n) ; ++i){
		scanf("%d" , arr + i);
		sum += arr[i];
	}
	printf("%.9lf\n" , 1.0 * sum / (1 << n));
	for(int i = 1 ; i <= r ; ++i){
		int inp;
		scanf("%d" , &inp);
		sum -= arr[inp];
		scanf("%d" , arr + inp);
		sum += arr[inp];
		printf("%.9lf\n" , 1.0 * sum / (1 << n));
	}
}