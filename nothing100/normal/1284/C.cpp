#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,mo,pre[250025];
LL ans;
int main(){
	scanf("%d%d",&n,&mo);
	pre[0]=1;
	for (int i=1;i<=n;i++) pre[i]=1ll*pre[i-1]*i%mo;
	for (int i=1;i<=n;i++)
		ans=(ans+1ll*pre[i]*(n-i+1)%mo*(n-i+1)%mo*pre[n-i]%mo)%mo;
	printf("%lld\n",ans);
}