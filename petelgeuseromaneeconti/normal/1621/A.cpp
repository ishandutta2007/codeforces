#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,K;
		scanf("%d%d",&n,&K);
		// 0 2 4 .. 2(K-1)
		if((K-1)*2<n){
			rep(i,0,n-1){
				rep(j,0,n-1){
					if(i==j&&i%2==0&&i/2<K){
						putchar('R');
					}else{
						putchar('.');
					}
				}
				puts("");
			}
		}else{
			puts("-1");
		}
	}
	return 0;
}