#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int k,pa,pb,Pa,Pb,P,f[1010][1010],ans,i,j;
int powmod(int x,int y){
	int ans=1;
	for(;y;y>>=1,x=1ll*x*x%mod)
		if(y&1)ans=1ll*ans*x%mod;
	return ans;
}
int main(){
	scanf("%d%d%d",&k,&pa,&pb);
	Pa=1ll*pa*powmod(pb+pa,mod-2)%mod;
	Pb=1ll*pb*powmod(pb+pa,mod-2)%mod;
	P=1ll*pa*powmod(pb,mod-2)%mod;
	f[1][0]=1;
	for(i=1;i<k;i++)
		for(j=0;j<k;j++){
			if(j+i<k)f[i][j+i]=(f[i][j+i]+1ll*f[i][j]*Pb)%mod;
			f[i+1][j]=(f[i+1][j]+1ll*f[i][j]*Pa)%mod;
		}
	for(i=1;i<=k;i++)
		for(j=0;j<k;j++)
			if(i+j>=k){
				if(i==k)ans=(ans+1ll*f[i][j]*(P+i+j))%mod;
				else ans=(ans+1ll*f[i][j]*Pb%mod*(i+j))%mod;
			}
	printf("%d\n",ans);
}