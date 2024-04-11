#include <stdio.h>
int q;
int main(){
	scanf("%d",&q);
	while(q--){
		static int l,r,ans;
		ans=0;
		scanf("%d%d",&l,&r);
		if(!(l&1)) ans+=l,l++;
		if(r&1) ans-=r,r--;
		printf("%d\n",ans+((r-l+1)>>1));
	}
}