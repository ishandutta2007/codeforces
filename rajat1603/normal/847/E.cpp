#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
int n;
char str[N];
int sum1[N];
int sum2[N];
int nxt[N];
int mark[N];
bool check(int val){
	int done = 0;
	memset(mark , 0 , sizeof(mark));
	for(int i = 1 ; i <= n ; ++i){
		if(str[i] == '.'){
			continue;
		}
		if(str[i] == '*'){
			if(done >= i){
				continue;
			}
			int where = nxt[i];
			if(where > n){
				return 0;
			}
			int how = where - i;
			if(how > val){
				return 0;
			}
			int extra = max((val - how) >> 1 , val - how * 2);
			done = max(done , where + extra);
			mark[where] = 1;
		}
		else{
			if(mark[i]){
				continue;
			}
			done = max(done , i + val);
		}
	}
	return 1;
}
int main(){
	scanf("%d" , &n);
	scanf("%s" , str + 1);
	sum1[0] = 0;
	sum2[0] = 0;
	for(int i = 1 ; i <= n ; ++i){
		sum1[i] = sum1[i - 1];
		sum2[i] = sum2[i - 1];
		if(str[i] == 'P'){
			++sum1[i];
		}
		if(str[i] == '*'){
			++sum2[i];
		}
	}
	nxt[n + 1] = n + 1;
	for(int i = n ; i >= 1 ; --i){
		nxt[i] = nxt[i + 1];
		if(str[i] == 'P'){
			nxt[i] = i;
		}
	}
	int l = 1;
	int r = n << 2;
	while(l < r){
		int mid = l + r >> 1;
		if(check(mid)){
			r = mid;
		}
		else{
			l = mid + 1;
		}
	}
	printf("%d\n" , l);
}