#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		if(i&1){
			for(int j=0;j<n;j++){
				printf("0 ");
			}
		}
		else{
			for(int j=0;j<n;j++){
				printf("%lld ",1LL<<i+j);
			}
		}
		puts("");
		fflush(stdout);
	}
	int q;
	scanf("%d",&q);
	while(q--){
		ll t;
		scanf("%lld",&t);
		int x=1,y=1;
		printf("%d %d\n",x,y);
		fflush(stdout);
		for(int i=0;i<2*n-2;i++){
			if((t>>i&1)==(t>>(i+1)&1)){
				y++;
			}
			else{
				x++;
			}
			printf("%d %d\n",x,y);
			fflush(stdout);
		}
	}
	return 0;
}