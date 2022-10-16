#include<bits/stdc++.h>
using namespace std;
int n,h,a,b,k,ta,fa,tb,fb,ans;
int main(){
	scanf("%d%d%d%d%d",&n,&h,&a,&b,&k);
	for(int i=1;i<=k;i++){
		scanf("%d%d%d%d",&ta,&fa,&tb,&fb);
		if(fa>fb) swap(fa,fb),swap(ta,tb);
		ans=abs(tb-ta);
		if(fb>=a && fb<=b || fa>=a && fa<=b || fa<=a && fb>=b) ans+=fb-fa;
		else{
			if(ta!=tb) ans+=min(abs(fa-b+fb-b),abs(fa-a+fb-a));
			else ans+=fb-fa;
		}
		printf("%d\n",ans);
	}
}