#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n;
pair < pair < int , int > , int > arr[N];
bool rip;
long long sum1 , sum2;
int main(){
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , &arr[i].first.first);
	}
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , &arr[i].first.second);
		arr[i].second = i;
	}
	printf("%d\n" , n + 2 >> 1);
	sort(arr + 1 , arr + 1 + n);
	rip = !(n & 1);
	n -= rip;
	sum1 = 0;
	sum2 = 0;
	if(rip){
		sum1 += arr[n + 1].first.second;
		sum2 += arr[n + 1].first.second;
	}
	sum1 += arr[n].first.second;
	sum2 += arr[n].first.second;
	for(int i = 1 ; i < n ; ++i){
		if(i & 1){
			sum1 += arr[i].first.second;
			sum2 -= arr[i].first.second;
		}
		else{
			sum2 += arr[i].first.second;
			sum1 -= arr[i].first.second;
		}
	}
	if(sum1 > 0){
		for(int i = 1 ; i < n ; i += 2){
			printf("%d " , arr[i].second);
		}
	}
	else{
		for(int i = 2 ; i < n ; i += 2){
			printf("%d " , arr[i].second);
		}
	}
	printf("%d" , arr[n].second);
	if(rip){
		printf(" %d" , arr[n + 1].second);
	}
	printf("\n");
}