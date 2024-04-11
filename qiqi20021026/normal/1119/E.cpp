#include<bits/stdc++.h>

using namespace std;

int n,x;
long long r,ans;

int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;++i){
		scanf("%d",&x);
		if (r*2<=x){
			ans+=r; x-=r*2;
			ans+=x/3; x%=3;
			r=x;
		}
		else{
			ans+=x/2;
			r-=x/2;
			r+=x%2;
		}
	}
	printf("%lld\n",ans);
		
	return 0;
}