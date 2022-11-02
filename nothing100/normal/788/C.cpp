#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,k,s[1010],b[1010],whs[1010],whb[1010],dps[500010],dpb[500010],ts,tb,mx,ans;
int main(){
	scanf("%d%d",&n,&k);
	for (int i=0;i<k;i++){
		int o;
		scanf("%d",&o);
		if (o==n){
			printf("1\n");
			return 0;
		}
		else if (o<n){
			if (s[n-o]==0){
				whs[ts++]=n-o;
				s[n-o]=1;
			}
		}
		else{
			if (b[o-n]==0){
				whb[tb++]=o-n;
				b[o-n]=1;
			}
		}
	}
	if (!ts||!tb){
		printf("-1\n");
		return 0;
	}
	ans=2000;
	sort(whs,whs+ts);
	sort(whb,whb+tb);
	for (int i=0;i<ts;i++)
	for (int j=0;j<tb;j++){
		ans=min(ans,whs[i]/__gcd(whs[i],whb[j])+whb[j]/__gcd(whs[i],whb[j]));
	}
	dps[0]=0;
	dpb[0]=0;
	for (int i=1;ans>i/whs[ts-1]+i/whb[tb-1];i++){
		dps[i]=100000;
		dpb[i]=100000;
		for (int j=0;j<ts;j++)
		if (i>=whs[j]) dps[i]=min(dps[i],dps[i-whs[j]]+1);
		else break;
		for (int j=0;j<tb;j++)
		if (i>=whb[j]) dpb[i]=min(dpb[i],dpb[i-whb[j]]+1);
		else break;
		ans=min(ans,dps[i]+dpb[i]);
	}
	printf("%d\n",ans);
}