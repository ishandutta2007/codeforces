#include "bits/stdc++.h"
using namespace std;
const int N = 1e6 + 6;
int n , q;
int oddcnt = 0;
int evencnt = 0;
int type , val;
int sum = 0;
int print[N];
bool ok = 0;
int main(){
	cin >> n >> q;
	while(q--){
		scanf("%d" , &type);
		if(type == 1){
			scanf("%d" , &val);
			val = (val + n) % n;
			oddcnt += val;
			evencnt += val;
			oddcnt %= n;
			evencnt %= n;
			sum += val;
			sum %= n;
			if(val & 1){
				ok ^= 1;
			}
		}
		else if(type == 2){
			if(ok){
				++evencnt;
				evencnt %= n;
				oddcnt += n - 1;
				oddcnt %= n;
				ok = 0;
			}
			else{
				ok = 1;
				++oddcnt;
				oddcnt %= n;
				evencnt += n - 1;
				evencnt %= n;
			}
		}
	}
	for(int i = 1 ; i <= n ; ++i){
		if(i & 1){
			print[(i - 1 + oddcnt) % n] = i;
		}
		else{
			print[(i - 1 + evencnt) % n] = i;
		}
	}
	for(int i = 0 ; i < n ; ++i){
		printf("%d " , print[i]);
	}
}