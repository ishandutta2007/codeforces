#include<bits/stdc++.h>
#define il inline
#define vd void
#define mod 1000000007
typedef long long ll;
il int gi(){
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return x*f;
}
int S[5010][5010];
il int pow(int x,int y){
	int ret=1;
	while(y){
		if(y&1)ret=1ll*ret*x%mod;
		x=1ll*x*x%mod;y>>=1;
	}
	return ret;
}
int main(){
	int n=gi(),k=gi();
	S[0][0]=1;
	for(int i=1;i<=k;++i)
		for(int j=1;j<=i;++j)
			S[i][j]=(S[i-1][j-1]+1ll*S[i-1][j]*j)%mod;
	int ans=0,p2=pow(2,n),inv2=pow(2,mod-2),p=1;
	for(int i=0;i<=k;p=1ll*p*(n-i)%mod,++i,p2=1ll*p2*inv2%mod)ans=(ans+1ll*p*S[k][i]%mod*p2%mod)%mod;
	printf("%d\n",ans);
	return 0;
}