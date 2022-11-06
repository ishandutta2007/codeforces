#include <cstdio>
const int Maxn=100000;
typedef long long ll;
int n;
ll l,r;
int main(){
	int T;
	scanf("%d",&T);
	ll sum;
	while(T--){
		scanf("%d%lld%lld",&n,&l,&r);
		if(l==1ll*n*(n-1)+1){
			puts("1");
			continue;
		}
		sum=0;
		int x,y;
		for(x=1;sum+((n-x)<<1)<l;x++){
			sum+=((n-x)<<1);
		}
		for(y=x+1;sum+2<l;y++){
			sum+=2;
		}
		if(sum+1==l){
			if(r==1ll*n*(n-1)+1){
				while(x<n){
					printf("%d ",x);
					printf("%d ",y);
					y++;
					if(y>n){
						x++;
						y=x+1;
					}
				}
				printf("%d ",1);
			}
			else{
				while(sum+2<=r){
					printf("%d ",x);
					printf("%d ",y);
					y++;
					if(y>n){
						x++;
						y=x+1;
					}
					sum+=2;
				}
				if(sum+1==r){
					printf("%d ",x);
				}
			}
		}
		else{
			if(r==1ll*n*(n-1)+1){
				printf("%d ",y);
				sum+=2;
				y++;
				if(y>n){
					x++;
					y=x+1;
				}
				while(x<n){
					printf("%d ",x);
					printf("%d ",y);
					y++;
					if(y>n){
						x++;
						y=x+1;
					}
				}
				printf("%d ",1);
			}
			else{
				printf("%d ",y);
				sum+=2;
				y++;
				if(y>n){
					x++;
					y=x+1;
				}
				while(sum+2<=r){
					printf("%d ",x);
					printf("%d ",y);
					y++;
					if(y>n){
						x++;
						y=x+1;
					}
					sum+=2;
				}
				if(sum+1==r){
					printf("%d ",x);
				}
			}
		}
		puts("");
	}
	return 0;
}