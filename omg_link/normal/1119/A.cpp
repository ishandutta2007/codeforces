#include <stdio.h>
#include <algorithm>
#define MN 300000
int n,ans=0,c[MN+5];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&c[i]);
	if(c[1]!=c[n]){
		printf("%d\n",n-1);
	}else{
		for(int i=1;i<=n;i++)
			if(c[i]!=c[1])
				ans=std::max(ans,std::max(i-1,n-i));
		printf("%d\n",ans);
	}
}