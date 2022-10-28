#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
int n;
int a[N];
pair < int , int > b[N];
int ans[N];
int main(){
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , a + i);
	}
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , &b[i].first);
		b[i].second = i;
	}
	sort(b + 1 , b + 1 + n);
	sort(a + 1 , a + 1 + n);
	for(int i = 1 ; i <= n ; ++i){
		ans[b[i].second] = a[n - i + 1];
	}
	for(int i = 1 ; i <= n ; ++i){
		printf("%d%c" , ans[i] , " \n"[i == n]);
	}
}