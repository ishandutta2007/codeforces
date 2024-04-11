#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#define MN 2000
typedef long long LL;

int n,k;
int l[MN+5],r[MN+5],a[MN+5];
LL f[MN+5],ans[MN+5];

void no(){
	puts("-1");
	exit(0);
}

int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d%d%d",&l[i],&r[i],&a[i]);
	for(int i=n;i>=1;i--)
		f[i] = std::max((a[i]+(r[i]==l[i+1]?f[i+1]:0))-1ll*(r[i]-l[i])*k,0ll);
	for(int i=1;i<=n;i++)
		if(f[i]>k) no();
	memset(ans,0x3f,sizeof(ans));
	ans[0] = 0;
	for(int i=1;i<=n;i++){
		int rest = k;
		LL tans = 0;
		for(int j=i;j<=n;j++){
			if(rest<f[j]) break;
			tans += a[j];
			rest = ((rest-a[j])%k+k)%k;
			if(r[j]!=l[j+1]){
				ans[j] = std::min(ans[j],ans[i-1]+tans+(j==n?0:rest));
			}else{
				if(rest<f[j+1]){
					tans += rest;
					rest = k;
				}
			}
		}
	}
	printf("%lld\n",ans[n]);
}