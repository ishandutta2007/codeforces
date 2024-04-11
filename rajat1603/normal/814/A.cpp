#include "bits/stdc++.h"
using namespace std;
const int N = 1e3 + 3;
int n , m;
int a[N];
int b[N];
int main(){
	cin >> n >> m;
	for(int i = 1 ; i <= n ; ++i){
		cin >> a[i];
	}
	for(int i = 1 ; i <= m ; ++i){
		cin >> b[i];
	}
	sort(b + 1 , b + 1 + m);
	for(int i = 1 ; i <= n ; ++i){
		if(a[i] == 0){
			a[i] = b[m--];
		}
	}
	for(int i = 1 ; i < n ; ++i){
		if(a[i] > a[i + 1]){
			printf("Yes\n");
			return 0;
		}
	}
	printf("No\n");
}