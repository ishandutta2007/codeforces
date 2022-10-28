#include "bits/stdc++.h"
using namespace std;
const int N = 1e3 + 3;
int cnt1[N];
int cnt2[N];
int n;
int a[N];
int b[N];
int tot1;
int tot2;
int pre[N];
int suf[N];
int x1 , x2;
bool ok1(int i){
	if(cnt1[a[i]] > 1){
		return tot1 == (n - 1);
	}
	return tot1 == n;
}
bool ok2(int i){
	if(cnt2[b[i]] > 1){
		return tot2 == (n - 1);
	}
	return tot2 == n;
}
int main(){
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , a + i);
	}
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , b + i);
	}
	for(int i = 1 ; i <= n ; ++i){
		++cnt1[a[i]];
		tot1 += cnt1[a[i]] == 1;
		x1 ^= a[i];
	}
	for(int i = 1 ; i <= n ; ++i){
		++cnt2[b[i]];
		tot2 += cnt2[b[i]] == 1;
		x2 ^= b[i];
	}
	pre[0] = 0;
	for(int i = 1 ; i <= n ; ++i){
		if(a[i] == b[i]){
			pre[i] = pre[i - 1];
		}
		else{
			pre[i] = pre[i - 1] + 1;
		}
	}
	int lol = 0;
	for(int i = 1 ; i <= n ; ++i){
		lol^= i;
	}
	for(int i = 1 ; i <= n ; ++i){
		if(ok1(i) && ok2(i)){
			if(pre[i - 1] == 0 && pre[n] - pre[i] == 0){
				int val = x1 ^ a[i] ^ lol;
				if(val != a[i] && val != b[i]){
					if(cnt1[val] == 0){
						for(int j = 1 ; j < i ; ++j){
							printf("%d " , a[j]);
						}
						printf("%d" , val);
						for(int j = i + 1 ; j <= n ; ++j){
							printf(" %d" , a[j]);
						}
						printf("\n");
						return 0;
					}
				}
			}
		}
	}
	for(int i = 1 ; i <= n ; ++i){
		for(int j = 1 ; j <= n ; ++j){
			if(i != j){
				if(ok1(i) && ok2(j)){
					int x = min(i , j);
					int y = max(i , j);
					if(pre[x - 1] == 0 && pre[n] - pre[y] == 0 && pre[y - 1] - pre[x] == 0){
						int vali = x1 ^ a[i] ^ lol;
						int valj = x2 ^ b[j] ^ lol;
						if(vali == b[i] && valj == a[j] && vali != a[i] && valj != b[j]){
							if(cnt1[vali] == 0 && cnt2[valj] == 0){
								a[i] = vali;
								a[j] = valj;
								for(int k = 1 ; k <= n ; ++k){
									printf("%d%c" , a[k] , " \n"[k == n]);
								}
								return 0;
							}
						}
					}
				}
			}
		}
	}
}