#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
int n;
int arr[N];
int cnt[N];
bool there[N];
int ptr;
int ans;
int main(){
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , arr + i);
		++cnt[arr[i]];
	}
	ptr = 1;
	for(int i = 1 ; i <= n ; ++i){
		if(cnt[arr[i]] > 1){
			while(cnt[ptr]){
				++ptr;
			}
			if(ptr > arr[i] && !there[arr[i]]){
				there[arr[i]] = 1;
				continue;
			}
			--cnt[arr[i]];
			arr[i] = ptr;
			++cnt[arr[i]];
			++ans;
			there[arr[i]] = 1;		
		}
	}
	printf("%d\n" , ans);
	for(int i = 1 ; i <= n ; ++i){
		printf("%d%c" , arr[i] , " \n"[i == n]);
	}
}