#include "bits/stdc++.h"
using namespace std;
const int N = 5e3 + 3;
int n;
int arr[N];
int freq[N];
int ans[N];
int main(){
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , arr + i);
	}
	for(int i = 1 ; i <= n ; ++i){
		int mx = 0;
		int ele;
		memset(freq , 0 , sizeof(freq));
		for(int j = i ; j <= n ; ++j){
			++freq[arr[j]];
			if(freq[arr[j]] > mx){
				mx = freq[arr[j]];
				ele = arr[j];
			}
			else if(freq[arr[j]] == mx && arr[j] < ele){
				ele = arr[j];
			}
			++ans[ele];
		}
	}
	for(int i = 1 ; i <= n ; ++i){
		printf("%d " , ans[i]);
	}
}