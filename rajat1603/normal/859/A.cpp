#include "bits/stdc++.h"
using namespace std;
const int N = 35;
int n;
int arr[N];
int mx;
int main(){
	scanf("%d" , &n);
	mx = 25;
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , arr + i);
		mx = max(mx , arr[i]);
	}
	printf("%d\n" , mx - 25);
}