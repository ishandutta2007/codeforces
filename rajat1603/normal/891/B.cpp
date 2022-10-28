#include "bits/stdc++.h"
using namespace std;
const int N = 55;
int n;
int a[N];
int b[N];
pair < int , int > tmp[N];
int main(){
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , a + i);
		tmp[i] = make_pair(a[i] , i);
	}
	sort(tmp + 1 , tmp + 1 + n);
	for(int i = 1 ; i < n ; ++i){
		if(tmp[i].first == tmp[i + 1].first){
			printf("-1\n");
			return 0;
		}
	}
	for(int i = 1 ; i < n ; ++i){
		b[tmp[i].second] = tmp[i + 1].first;
	}
	b[tmp[n].second] = tmp[1].first;
	for(int i = 1 ; i <= n ; ++i){
		printf("%d%c" , b[i] , " \n"[i == n]);
	}
}