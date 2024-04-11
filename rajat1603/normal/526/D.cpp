#include "bits/stdc++.h"
using namespace std;
const int N = 1e6 + 6;
int n , k;
char str[N];
int lcp[N];
int main(){
	scanf("%d %d" , &n , &k);
	scanf("%s" , str + 1);
	lcp[0] = 0;
	lcp[1] = 0;
	for(int i = 2 ; i <= n ; ++i){
		int idx = lcp[i - 1];
		while(idx && str[idx + 1] != str[i]){
			idx = lcp[idx];
		}
		if(str[idx + 1] == str[i]){
			lcp[i] = idx + 1;
		}
		else{
			lcp[i] = 0;
		}
	}
	for(int i = 1 ; i <= n ; ++i){
		int period = i - lcp[i];
		int r = i / period;
		bool ok;
		if(i % period == 0){
			ok = (r / k) >= (r % k);
		}
		else{
			ok = (r / k) > (r % k);
		}
		putchar('0' + ok);
	}
}