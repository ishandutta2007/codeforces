#include "bits/stdc++.h"
using namespace std;
const int N = 55;
int n;
char str[N][N];
int main(){
	scanf("%d" , &n);
	int mnx = n + 1;
	int mxx = -1;
	int mny = n + 1;
	int mxy = -1;
	for(int i = 1 ; i <= n ; ++i){
		scanf("%s" , str[i] + 1);
		for(int j = 1 ; j <= n ; ++j){
			if(str[i][j] == '4'){
				mnx = min(mnx , i - 1);
				mny = min(mny , j - 1);
				mxx = max(mxx , i);
				mxy = max(mxy , j); 
			}
		}
	}
	for(int i = 1 ; i <= n ; ++i){
		for(int j = 1 ; j <= n ; ++j){
			int cnt = 0;
			for(int x = i - 1 ; x <= i ; ++x){
				for(int y = j - 1 ; y <= j ; ++y){
					cnt += (x >= mnx) && (x <= mxx) && (y >= mny) && (y <= mxy);
				}
			}
			if(cnt != str[i][j] - '0'){
				printf("No\n");
				return 0;
			}
		}
	}
	printf("Yes\n");
}