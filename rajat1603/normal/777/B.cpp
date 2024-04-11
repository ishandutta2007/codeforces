#include "bits/stdc++.h"
using namespace std;
const int N = 1e3 + 3;
int n;
char a[N];
char b[N];
int cnt[10];
int ans;
int get(int dig){
	for(int i = dig ; i < 10 ; ++i){
		if(cnt[i]){
			--cnt[i];
			return i;
		}
	}
	for(int i = 0 ; i < dig ; ++i){
		if(cnt[i]){
			--cnt[i];
			return i;
		}
	}
}
int main(){
	scanf("%d" , &n);
	scanf("%s" , a + 1);
	scanf("%s" , b + 1);
	memset(cnt , 0 , sizeof(cnt));
	for(int i = 1 ; i <= n ; ++i){
		++cnt[b[i] - '0'];
	}
	ans = 0;
	for(int i = 1 ; i <= n ; ++i){
		int x = get(a[i] - '0');
		if(x < a[i] - '0'){
			++ans;
		}
	}
	printf("%d\n" , ans);
	memset(cnt , 0 , sizeof(cnt));
	for(int i = 1 ; i <= n ; ++i){
		++cnt[b[i] - '0'];
	}
	ans = 0;
	for(int i = 1 ; i <= n ; ++i){
		int x = get(a[i] - '0' + 1);
		if(x > a[i] - '0'){
			++ans;
		}
	}
	printf("%d\n" , ans);
}