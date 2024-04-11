#include "bits/stdc++.h"
using namespace std;
const int N = 3e5 + 5;
int n;
int arr[N];
long long c2(int x){
	return ((1LL * x * (x - 1LL)) / 2LL);
}
long long c3(int x){
	return (1LL * x * (x - 1LL) * (x - 2LL)) / 6LL;
}
int main(){
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , arr + i);
	}
	sort(arr + 1 , arr + 1 + n);
	vector < int > v;
	v.clear();
	v.push_back(1);
	for(int i = 2 ; i <= n ; ++i){
		if(arr[i] == arr[i - 1]){
			++v.back();
		}
		else{
			v.push_back(1);
		}
	}
	if(v[0] == 1){
		if(v[1] == 1){
			printf("%d\n" , v[2]);
		}
		else{
			printf("%lld\n" , c2(v[1]));
		}
	}
	else if(v[0] == 2){
		printf("%d\n" , v[1]);
	}
	else{
		printf("%lld\n" , c3(v[0]));
	}
}