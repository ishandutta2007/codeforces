#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
typedef long long LL;
// Luogu Judging
LL n; int q;
#define Luogu Judge
int main(){
	scanf("%lld%d",&n,&q);
	F(i,1,q){
		LL x,y;
		scanf("%lld%lld",&x,&y);
		if(x+y&1){
			if(n&1){
				if(x&1){
					printf("%lld\n",n*n/2+1+(x-1)/2*n+(y+1)/2);
				}
				else{
					printf("%lld\n",n*n/2+1+(x-2)/2*n+(n/2)+(y+1)/2);
				}
			}
			else{
				printf("%lld\n",n*n/2+(x-1)*(n/2)+(y+1)/2);
			}
		}
		else{
			if(n&1){
				if(x&1){
					printf("%lld\n",(x-1)/2*n+(y+1)/2);
				}
				else{
					printf("%lld\n",(x-2)/2*n+(n/2+1)+(y+1)/2);
				}
			}
			else{
				printf("%lld\n",(x-1)*(n/2)+(y+1)/2);
			}
		}
	}
	return 0;
}