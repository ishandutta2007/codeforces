#include<bits/stdc++.h> 
#define mod 1000000007
using namespace std;
int n,m,i,j,ans,sum,use[1010],P[1010],F[1010];
char s[100010];
bitset<1010>A[1010];
int powmod(int x,int y){
	int ans=1;
	for(;y;y>>=1,x=1ll*x*x%mod)
		if(y&1)ans=1ll*x*ans%mod;
	return ans;
}
int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++){
		scanf("%s",s+1);
		for(j=1;j<=n;j++)
			A[j][i]=s[j]-'0';
	}
	P[0]=1;
	for(i=1;i<=n;i++)P[i]=1ll*P[i-1]*i%mod;
	F[0]=1;
	for(i=1;i<=n;i++)
		for(j=0;j<i;j++)
			F[i]=(F[i]+1ll*F[j]*P[i-1]%mod*powmod(P[j],mod-2)%mod*powmod(P[i-j-1],mod-2))%mod;
	//for(i=1;i<=n;i++)printf("%d\n",F[i]);
	ans=1;
	for(i=1;i<=n;i++)if(!use[i]){
		sum=1;
		for(j=i+1;j<=n;j++)
		if((A[i]^A[j]).count()==0)
			sum++,use[j]=1;
		ans=1ll*ans*F[sum]%mod;
	}
	printf("%d\n",(ans+mod)%mod);
}