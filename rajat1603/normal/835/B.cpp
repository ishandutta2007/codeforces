#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int k;
char str[N];
int cnt[10];
int ans;
int main(){
	scanf("%d" , &k);
	scanf("%s" , str);
	int sum = 0;
	for(int i = 0 ; str[i] ; ++i){
		++cnt[str[i] - '0'];
		sum += str[i] - '0';
	}
	for(int i = 0 ; sum < k ; ++i){
		while(sum < k && cnt[i]){
			sum += 9 - i;
			++ans;
			--cnt[i];
		}
	}
	printf("%d\n" , ans);
}